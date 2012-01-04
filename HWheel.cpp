#include "HWheel.h"

void HWheel::write(double speed) {
  if (!_started) start();
  speed = min(max(-1, speed), 1);
  analogWrite(_pinFd, speed > 0 ? speed *  255 : 0);
  analogWrite(_pinBk, speed < 0 ? speed * -255 : 0);
  _speed = speed;
}

void HWheel::start() {
  pinMode(_pinFd, OUTPUT);
  pinMode(_pinBk, OUTPUT);
  _started = true;
}
