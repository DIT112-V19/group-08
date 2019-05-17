#include <Smartcar.h>
#include <SoftwareSerial.h>
char command;
char input;

// Pin ids
const int leftMotorForwardPin = 8;
const int leftMotorBackwardPin = 10;
const int leftMotorSpeedPin = 9;
const int rightMotorForwardPin = 12;
const int rightMotorBackwardPin = 13;
const int rightMotorSpeedPin = 11;
const int ledPin = 3;// the number of the LED pin
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

SimpleCar car(control);


// variables
const int blinkInterval = 600;
const int failproof_distance = 100;

boolean objectNextTo = false;
int side_obstacle_counter = 0;
int traveled_distance = 0;


SoftwareSerial EEBlue(18, 19);

void setup() {
  pinMode(40, OUTPUT);
  digitalWrite(40,HIGH);
  Serial.begin(9600);
  EEBlue.begin(38400);

  Serial.println("Connect");
  pinMode(ledPin, OUTPUT);

  odometer.attach(odometerPin, []() {
    odometer.update();
  });
}

void loop() {

  if(EEBlue.available())
  Serial1.write(EEBlue.read());
  if(Serial1.available())
  Serial2.write(Serial.read());
  check();
  Serial.println(side_obstacle_counter);
  Serial.println(odometer.getDistance());
  Serial.println(front_sensor.getDistance());
  Serial.println(side_sensor.getDistance());
  Serial.println(rear_sensor.getDistance());
  Serial.println();

  remote_Command();
  led();
}


void remote_Command(){
  if (Serial.available() > 0) {
    input = ' ';
  }

  while(Serial.available() > 0) {
    command = ((byte)Serial.read());

    if(command == ':') {
       while(1){}
    }else {
      input = command;
    }

    switch (input) {
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

void check(){
   int current_distance = front_sensor.getDistance();
   int side_distance = side_sensor.getDistance();
   int rear_distance = rear_sensor.getDistance();
   if ((current_distance > 20 || current_distance == 0) &&
                                   (side_distance > 20 || side_distance == 0)) {
    if (side_obstacle_counter == 1 && side_distance > 20){
       parallelParking();
     }
     car.setSpeed(30);
     car.setAngle(0);
   }

   else if (current_distance > 0 && current_distance < 20) {
     car.setSpeed(0);
   }

   else if (side_distance > 0 && side_distance < 20){
     side_obstacle_counter = 1;
     car.setSpeed(30);
   }
}

void parallelParking(){
  int distance_Stamp = odometer.getDistance();
  int parking_distance = side_sensor.getDistance();
  while (parking_distance > 6 && parking_distance != 0){
     parking_distance = side_sensor.getDistance();
     car.setSpeed(30);
     car.setAngle(55);
  }

  int  second_Distance_Stamp = odometer.getDistance();
  double  turning_Distance_Stamp = (second_Distance_Stamp - distance_Stamp) * 0.7;
    while (odometer.getDistance() < second_Distance_Stamp + turning_Distance_Stamp){
     car.setSpeed(30);
     car.setAngle(-55);
  }

  while(1) {
    car.setSpeed(0);
    car.setAngle(0);
  }
}

void forward() {
  car.setSpeed(30);
  car.setAngle(0);
  Serial.println(input);
}

void backward() {
  car.setSpeed(-30);
  car.setAngle(0);
  Serial.println(input);
}

void right() {
  car.setSpeed(30);
  car.setAngle(50);
  Serial.println(input);
}

void left() {
  car.setSpeed(30);
  car.setAngle(-50);
  Serial.println(input);
}
