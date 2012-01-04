// HWheel

// Wraps an H-bridge

/////////////////////////
// Fd // Bk  //  Motor //
/////////////////////////
//  0 //  0  //  stop  //
/////////////////////////
//  1 //  0  //  forw. //
/////////////////////////
//  0 //  1  //  back  //
/////////////////////////
//  1 //  1  //  stop  //
/////////////////////////

// Write values range from -1.0 to 1.0
// Values beyond this range are clamped.
// Effective resolution is that of two analogWrites
// (~500 discrete speeds) for PWM enabled pins
// For non-PWM enabled pins, resolution will gracefully
// degrade to three states.

#ifndef _HWHEEL_H_
#define _HWHEEL_H_

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include <Wheel.h>

class HWheel : public Wheel {
  public:
    HWheel(int pinFd, int pinBk) : _pinFd(pinFd), _pinBk(pinBk) {};
    void write(double speed);
  
  private:
    const int _pinFd;
    const int _pinBk;
    boolean _started;
    
    void start();
};

#endif
