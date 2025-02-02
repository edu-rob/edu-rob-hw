#include "robot.h"

typedef int8_t speed_t;

// Motor right pins
const int rightPinF = 24;  // GP23 -> IN1 ->
const int rightPinB = 25;  // GP22 -> IN2 ->

// Motor left pins
const int leftPinF = 22;   // GP24 -> IN3 ->
const int leftPinB = 23;   // GP25 -> IN4 ->

const speed_t MAX_SPEED = std::numeric_limits<speed_t>::max();
const speed_t MIN_SPEED = std::numeric_limits<speed_t>::min();
const speed_t IDLE = 0;

Robot::Robot() {
  pinMode(rightPinF, OUTPUT);
  pinMode(rightPinB, OUTPUT);
  pinMode(leftPinF, OUTPUT);
  pinMode(leftPinB, OUTPUT);
}

/** 
  * speed : [-128, 127]
  */
void Robot::controlMotor(Motor motor, speed_t speed) {
  int pinForwards = motor == Motor::LEFT ? leftPinF : rightPinF;
  int pinBackwards = motor == Motor::LEFT ? leftPinB : rightPinB;

  digitalWrite(pinForwards, speed > 0 ? HIGH : LOW);
  digitalWrite(pinBackwards, speed > 0 ? LOW : (speed == 0 ? LOW : HIGH));
}

void Robot::stop() {
#ifdef DEBUG
  Serial.println("Stopping Motors");
#endif
  controlMotor(Motor::RIGHT, IDLE);
  controlMotor(Motor::LEFT, IDLE);
}

void Robot::forwards(int meters) {
#ifdef DEBUG
  Serial.println("Moving Forward");
#endif
  controlMotor(Motor::RIGHT, MAX_SPEED);
  controlMotor(Motor::LEFT, MAX_SPEED);
  delay((moveDelay * meters) / 10);
  stop();
}

void Robot::backwards(int meters) {
#ifdef DEBUG
  Serial.println("Moving Backward");
#endif
  controlMotor(Motor::RIGHT, MIN_SPEED);
  controlMotor(Motor::LEFT, MIN_SPEED);
  delay((moveDelay * meters) / 10);
  stop();
}

void Robot::left(int deg) {
#ifdef DEBUG
  Serial.println("Moving Left");
#endif
  controlMotor(Motor::RIGHT, MAX_SPEED);
  controlMotor(Motor::LEFT, MIN_SPEED);
  delay(spinDelay * deg / 90);
  stop();
}

void Robot::right(int deg) {
#ifdef DEBUG
  Serial.println("Moving Right");
#endif
  controlMotor(Motor::LEFT, MAX_SPEED);
  controlMotor(Motor::RIGHT, MIN_SPEED);
  delay(spinDelay * deg / 90);
  stop();
}