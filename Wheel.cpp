#include "Wheel.h"

// TODO: Find a better place for this personal calibration. It does not belong here.
const int servoUsMiddle = (544+2400)/2; // Middle of the default servo range
const int servoUsVariation = 150; // Calibrated from particular servos

Wheel::Wheel(int pin, int directionMultiplier)
  : _directionMultiplier(directionMultiplier)
  , _pin(pin)
  , _started(false)
{;}


void Wheel::start() {
  pinMode(_pin, OUTPUT);
  _servo.attach(_pin);
  _started = true;
  this->write(0);
}


void Wheel::write(double speed) {
  if (!_started) start();
  _servo.writeMicroseconds(servoUsMiddle + speed * servoUsVariation * _directionMultiplier);
  _speed = speed;
}


double Wheel::read() const {
  return _started ? _speed : 0;
}
