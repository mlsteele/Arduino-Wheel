#include "ServoWheel.h"

// These were for Parallax Continuous Rotation Servos
// const int servoUsMiddle = (544+2400)/2; // Middle of the default servo range
// const int servoUsVariation = 150; // Calibrated from particular servos

ServoWheel::ServoWheel(int pin, int directionMultiplier, int stopUs = 1500, int varianceUs = 500)
  : _pin(pin)
  , _directionMultiplier(directionMultiplier)
  , _stopUs(stopUs)
  , _varianceUs(varianceUs)
  , _started(false)
{;}

void ServoWheel::start() {
  pinMode(_pin, OUTPUT);
  _servo.attach(_pin);
  _started = true;
  this->write(0);
}

void ServoWheel::write(double speed) {
  if (!_started) start();
  _servo.writeMicroseconds(_stopUs + speed * _varianceUs * _directionMultiplier);
  _speed = speed;
}
