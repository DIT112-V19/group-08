#include <Smartcar.h>
int leftMotorForwardPin = 8;
int leftMotorBackwardPin = 10;
int leftMotorSpeedPin = 9;
int rightMotorForwardPin = 12;
int rightMotorBackwardPin = 13;
int rightMotorSpeedPin = 11;

BrushedMotor leftMotor(leftMotorForwardPin, leftMotorBackwardPin, leftMotorSpeedPin);
BrushedMotor rightMotor(rightMotorForwardPin, rightMotorBackwardPin, rightMotorSpeedPin);
DifferentialControl control(leftMotor, rightMotor);

//HC-SR04 side ultrasound sensor
const int SIDE_TRIGGER_PIN = 6; //D6 pin
const int SIDE_ECHO_PIN = 7; //D7 pin
const unsigned int SIDE_MAX_DISTANCE = 80;
SR04 side_sensor(SIDE_TRIGGER_PIN, SIDE_ECHO_PIN, SIDE_MAX_DISTANCE);

//HC-SR04 front ultrasound sensor
const int FRONT_TRIGGER_PIN = 5; //D5 pin
const int FRONT_ECHO_PIN = 4; //D4 pin
const unsigned int FRONT_MAX_DISTANCE = 80;
SR04 front_sensor(FRONT_TRIGGER_PIN, FRONT_ECHO_PIN, FRONT_MAX_DISTANCE);

DirectionlessOdometer odometer(80);
const int odometerPin = 2; //D2 pin

SimpleCar car(control);

//unsigned long currentMillis = 0;    // stores the value of millis() in each iteration of loop()
//unsigned long timestampMillis = 0;   // will store time after starting to perform time based actions
int side_obstacle_counter = 0;
boolean objectNextTo = false;
const int rightTurnInterval = 26;
const int leftTurnInterval = 96;
const int backwardsInterval = 120;
unsigned int currentdistance= 0;
int traveled_distance = 0;
int failproof_distance = 100;
   

void setup() {
  Serial.begin(9600);
  odometer.attach(odometerPin, [](){
    odometer.update();
  });
}

void loop() {
  check();
  Serial.println(side_obstacle_counter);
  Serial.println(odometer.getDistance());
 }

void check(){
   int current_distance = front_sensor.getDistance();
   int side_distance = side_sensor.getDistance();
   if ((current_distance > 20 || current_distance == 0) && (side_distance > 20 || side_distance == 0)) {
    if (side_obstacle_counter == 2 && side_distance > 20){
       parallelParking();
     }
     car.setSpeed(30);
     car.setAngle(0);
     if(odometer.getDistance() - traveled_distance > failproof_distance){
        objectNextTo = false;   
     }
   }
   else if (current_distance > 0 && current_distance < 20) {
     car.setSpeed(0);
   }
   
   else if (side_distance > 0 && side_distance < 20){
     if(objectNextTo == false){
        side_obstacle_counter += 1;
        traveled_distance = odometer.getDistance();
     }
     objectNextTo = true;
     car.setSpeed(30);
   }
}

void parallelParking(){
  int  distanceStamp = odometer.getDistance();
  while (odometer.getDistance() - distanceStamp < rightTurnInterval){
     car.setSpeed(-30);
     car.setAngle(60);
  } 
  while (odometer.getDistance() - distanceStamp < leftTurnInterval){
     car.setSpeed(-30);
     car.setAngle(-65);
  }
  while (odometer.getDistance() - distanceStamp < backwardsInterval){
     car.setSpeed(30);
     car.setAngle(0);
  }
  while(1) {
    car.setSpeed(0);
    car.setAngle(0);
  }
}
