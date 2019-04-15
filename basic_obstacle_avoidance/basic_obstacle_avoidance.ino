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

//HC-SR04 front ultrasound sensor
const int FRONT_TRIGGER_PIN = 6; //D6 pin
const int FRONT_ECHO_PIN = 7; //D7 pin
const unsigned int FRONT_MAX_DISTANCE = 500;
SR04 front_sensor(FRONT_TRIGGER_PIN, FRONT_ECHO_PIN, FRONT_MAX_DISTANCE);

//HC-SR04 side ultrasound sensor
const int SIDE_TRIGGER_PIN = 10; //D10 pin
const int SIDE_ECHO_PIN = 11; //D11 pin
const unsigned int SIDE_MAX_DISTANCE = 100;
SR04 side_sensor(SIDE_TRIGGER_PIN, SIDE_ECHO_PIN, SIDE_MAX_DISTANCE);
//SimpleCar side_car(control);
SimpleCar car(control);

void setup() {
Serial.begin(9600);
}

void loop() {
 check();
}

void check(){
   int current_distance = front_sensor.getDistance();
   int side_distance = side_sensor.getDistance();
//    Serial.println(side_distance);
    Serial.println(current_distance);
   if (current_distance > 0) {
    Serial.println("In If\n");
   car.setAngle(0);
   car.setSpeed(0);
  }
   if (current_distance > 20) {
//    delay(1000);
   Serial.println("In Else if\n");
    car.setSpeed(30);
    car.setAngle(0);
  }
  }
