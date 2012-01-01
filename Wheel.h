// Wheel

// Abstract class for interfacing with a wheel
// Write values range from -1.0 to 1.
// Treatment of out of bounds values is dependent upon the implementation

#ifndef _WHEEL_H_
#define _WHEEL_H_

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class Wheel {
  public:
    Wheel() : _speed(0) {};
    virtual void write(double speed) =0;
    double read() const {return _speed;};
    void stop() {return write(0);};
  
  protected:
    double _speed;
};

#endif
