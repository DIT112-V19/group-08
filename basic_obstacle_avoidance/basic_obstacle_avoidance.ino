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

//HC-SR04 ultrasound sensor
const int TRIGGER_PIN = 6; //D6 pin
const int ECHO_PIN = 7; //D7 pin
const unsigned int MAX_DISTANCE = 100;
SR04 front_sensor(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
SimpleCar car(control);

void setup() {
Serial.begin(9600);
car.setSpeed(40);
car.setAngle(0);
}

void loop() {
  int current_distance = front_sensor.getDistance();
 
  if (current_distance < 40 && current_distance > 0) {
    car.setSpeed(0);
    car.setAngle(0);
  }

}
