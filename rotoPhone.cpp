#include "Arduino.h"
#include "rotoPhone.h"

rotoPhone::rotoPhone(int pin1, int pin2){
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  _pin1 = pin1;
  _pin2 = pin2;
}

rotoPhone::number(){
  _state1  = digitalRead(_pin1);
  _state2 = digitalRead(_pin2);

  if (_state1 == _state2 ) {
    _isNum = true;
  }else{
    _isNum = false;
    return number;
  }
  if (isNum && num == 0 && lastNum ==1) {
    number ++ ;
  }

}
