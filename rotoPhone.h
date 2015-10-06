#ifndef rotoPhone_h
#define rotoPhone_h

#include "Arduino.h"
class rotoPhone{
  public :
    rotoPhone(uint8_t pin1, uint8_t pin2);
    void number();
    void lastNumber();
  private :
    uint8_t _pin1;
    uint8_t _pin2;
    bool _state1;
    bool _state2;
    bool _isNum;


}
