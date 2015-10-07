#ifndef RotoPhone_h
#define RotoPhone_h

#include "Arduino.h"
class RotoPhone{
  public :
    RotoPhone(uint8_t pin1, uint8_t pin2);
    RotoPhone(uint8_t pin1, uint8_t pin2, bool pullUp);
    void number();
    void lastNumber();
  private :
    uint8_t _number;
    uint8_t _pin1;
    uint8_t _pin2;
    uint8_t _lastState;
    bool _state1;
    bool _state2;
    bool _isNum;
    bool _pullUp;
};
