#include <Smartcar.h>


char input;
String command="";

// Pin ids
const int leftMotorForwardPin = 8;
const int leftMotorBackwardPin = 10;
const int leftMotorSpeedPin = 9;
const int rightMotorForwardPin = 12;
const int rightMotorBackwardPin = 13;
const int rightMotorSpeedPin = 11;
const int ledPin = A3;// the number of the LED pin

int ledState = LOW;   // ledState used to set the LED
// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated
// constants won't change:
const long interval = 1000;           // interval at which to blink (milliseconds)


BrushedMotor leftMotor(leftMotorForwardPin, leftMotorBackwardPin, leftMotorSpeedPin);
BrushedMotor rightMotor(rightMotorForwardPin, rightMotorBackwardPin, rightMotorSpeedPin);
DifferentialControl control(leftMotor, rightMotor);


//HC-SR04 side, front and back ultrasound sensors respectively
const int SIDE_TRIGGER_PIN = 6; //D6 pin
const int SIDE_ECHO_PIN = 7; //D7 pin
const unsigned int SIDE_MAX_DISTANCE = 80;
SR04 side_sensor(SIDE_TRIGGER_PIN, SIDE_ECHO_PIN, SIDE_MAX_DISTANCE);

const int FRONT_TRIGGER_PIN = 5; //D5 pin
const int FRONT_ECHO_PIN = 4; //D4 pin
const unsigned int FRONT_MAX_DISTANCE = 80;
SR04 front_sensor(FRONT_TRIGGER_PIN, FRONT_ECHO_PIN, FRONT_MAX_DISTANCE);

const int REAR_TRIGGER_PIN = 22; //D22 pin
const int REAR_ECHO_PIN = 24; //D24 pin
const unsigned int REAR_MAX_DISTANCE = 80;
SR04 rear_sensor(REAR_TRIGGER_PIN, REAR_ECHO_PIN, REAR_MAX_DISTANCE);

// Odometer
DirectionlessOdometer odometer(80);
const int odometerPin = 2; //D2 pin

const int GYROSCOPE_OFFSET = 37;
GY50 gyro(GYROSCOPE_OFFSET);

SimpleCar car(control);


// variables
const int blinkInterval = 600;
const int failproof_distance = 100;

boolean positive_speed = true;
boolean objectNextTo = false;
int side_obstacle_counter = 0;
int traveled_distance = 0;

void setup() {
  pinMode(40, OUTPUT);
  digitalWrite(40,HIGH);
  Serial.begin(9600);
  Serial1.begin(9600);

  Serial.println("Connect");
  pinMode(ledPin, OUTPUT);

  odometer.attach(odometerPin, []() {
    odometer.update();
  });
}

void loop() {
  gyro.update();
  checkBluetoothData();
  checkObstaclesFront(command);
//  checkObstaclesRear();
  remote_Command(command);
  led();
}

void checkBluetoothData() {
  command = "";

  if (Serial1.available()>0){
    char info = Serial1.read();
    command.concat(info);
  }

  if (!command.equals("") && command.length()==2){
    Serial1.flush();
    Serial.println(command);
  }
}

void remote_Command(String command){
  if (command!=""){
    input = command[0];
  Serial.println(input);
    switch (command[0]) {
      case 'F':
        forward();
        break;
      case 'B':
        backward();
        break;
      case 'R':
        right();
        break;
      case 'L':
        left();
        break;
      case 'P':
        parkingSpotting();
        break;
      case 'C':
        cruiseControl();
        break;
      case '0':
        stop();
        break;
      case '1':
        resetAngle();
        break;
    }
  }
}


void led(){
   unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
}

// collision avoidance code while driving the car manually
boolean checkObstaclesFront(String command){
   boolean obstacle_in_front = false; 
   int current_distance = front_sensor.getDistance();
   if (current_distance > 0 && current_distance < 20) {
     car.setSpeed(0);
     car.setAngle(0);
     obstacle_in_front = true;
   }
   return obstacle_in_front;
}

//boolean checkObstaclesRear(){
//   boolean obstacle_in_rear = false; 
//   int rear_distance = rear_sensor.getDistance();
//   if (rear_distance > 0 && rear_distance < 20) {
//     car.setSpeed(0);
//     car.setAngle(0);
//     obstacle_in_rear = true;
//   }
//   return obstacle_in_rear;
//}


// Smartcar goes forward checking obstacles to the right side of itself
// and measuring distances between passed objects. If there is enough
// space - the car activates parallel parking functionality
void parkingSpotting(){
   while (side_obstacle_counter < 2){
     int current_distance = front_sensor.getDistance();
     int side_distance = side_sensor.getDistance();

     if ((current_distance > 20 || current_distance == 0) &&
                                     (side_distance > 20 || side_distance == 0)) {
        car.setSpeed(30);
        car.setAngle(0);
        if (odometer.getDistance() - traveled_distance > failproof_distance){
          objectNextTo = false;
        }
     }
  
     else if (current_distance > 0 && current_distance < 20) {
        car.setSpeed(0);
     }
  
     else if (side_distance > 0 && side_distance < 20){
        if (objectNextTo == false){
           side_obstacle_counter += 1;
           traveled_distance = odometer.getDistance();
        }
        objectNextTo = true;
        car.setSpeed(30);
        car.setAngle(0);
     }
   }
   side_obstacle_counter = 0;
   parallelParking();
}


// Method for the car to park in parallel to the right.
// The car moves automatically as long as there is space to move and
// straightens itself by the end.
void parallelParking(){
  gyro.update();
  int car_direction = gyro.getHeading();
  int initial_direction = car_direction;
  int turn_degree;
  
  if (car_direction >= 45)
     turn_degree = car_direction - 45;
  else {
     turn_degree = 360 - (45 - car_direction);
  }

//  int direction_failproof = 5;
  int low_bound = turn_degree - 5;
  int up_bound = turn_degree + 5;
  int lowS_bound = initial_direction - 5;
  int upS_bound = initial_direction + 5;  


  while (car_direction < low_bound || car_direction > up_bound){
     car.setSpeed(-25);
     car.setAngle(40);
     gyro.update();
     car_direction = gyro.getHeading();
  }

  int rear_distance = rear_sensor.getDistance();
  while (rear_distance > 15 /*|| rear_distance == 0*/){
     rear_distance = rear_sensor.getDistance();
     car.setSpeed(-20);
     car.setAngle(0);
  }

  
  while (car_direction < lowS_bound || car_direction > upS_bound){
     car.setSpeed(-24);
     car.setAngle(-60);
     gyro.update();
     car_direction = gyro.getHeading();
  }
}


void forward() {
//  if (checkObstaclesFront()){}
//  else {
    positive_speed = true;
    car.setSpeed(30);
    car.setAngle(0);
//  }
}
void backward() {
//  if (checkObstaclesRear()) {}
//  else{
//    positive_speed = false;
    car.setSpeed(-30);
    car.setAngle(0);
//  }
}
void right() {
  if (positive_speed == true) 
      car.setSpeed(30);
  else car.setSpeed(-30);
  car.setAngle(70);
}
void left() {
  if (positive_speed == true) 
      car.setSpeed(30);
  else car.setSpeed(-30);
  car.setAngle(-70);
}

void stop() {
  car.setSpeed(0);
}

void resetAngle() {
  car.setAngle(0);
}

void cruiseControl() {
  car.setSpeed(30);
  car.setAngle(0);
  input = command[0];

  while (input!='0'){
    checkBluetoothData();
    int current_distance = front_sensor.getDistance();
    int side_distance = side_sensor.getDistance();
    int rear_distance = rear_sensor.getDistance();

    if (current_distance>0 && current_distance<50){
      car.setSpeed(30);

      if (side_distance>0 && side_distance<50){
        car.overrideMotorSpeed(-40,30);
      } else{
        car.overrideMotorSpeed(30,-40);
      }

    } else{
      car.setSpeed(30);
      car.setAngle(0);
    }



    input = command[0];
  }
}
