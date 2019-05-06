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

const int blinkInterval = 600;
const int rightTurnInterval = 900;
const int leftTurnInterval = 1750;
const int backwardsInterval = 2250;
unsigned long currentMillis = 0;    // stores the value of millis() in each iteration of loop()
unsigned long timestampMillis = 0;   // will store time after starting to perform time based actions
  int side_obstacle_counter = 0;


void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  odometer.attach(odometerPin, [](){
    odometer.update();
  });
}

void loop() {
  check();
  led(); 
}

void led(){
  timestampMillis = millis();
  while (millis() - timestampMillis < blinkInterval){
      digitalWrite(8, LOW);
    }
//  while (millis() - timestampMillis < blinkInterval){
//      digitalWrite(8, LOW);
//    }
  }

void check(){
   int current_distance = front_sensor.getDistance();
   int side_distance = side_sensor.getDistance();
    
   if ((current_distance > 20 || current_distance == 0) && (side_distance > 20 || side_distance == 0)) {
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
  timestampMillis = millis();
  while (millis() - timestampMillis < rightTurnInterval){
     car.setSpeed(30);
     car.setAngle(60);
  }
  while (millis() - timestampMillis < leftTurnInterval){
     car.setSpeed(30);
     car.setAngle(-65);
  }
  while (millis() - timestampMillis < backwardsInterval){
     car.setSpeed(-30);
     car.setAngle(0);
  }
  while(1) {
    car.setSpeed(0);
    car.setAngle(0);
  }
}
