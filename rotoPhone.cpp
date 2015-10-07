#include "Arduino.h"
#include "rotoPhone.h"

rotoPhone::rotoPhone(uint8_t  pin1, uint8_t  pin2){
  pinMode(pin1, INPUT);
  pinMode(pin2,  INPUT);
  _pin1 = pin1;
  _pin2 = pin2;
}

rotoPhone::rotoPhone(uint8_t  pin1, uint8_t  pin2, bool pullUp){
  //Turn on pull up resistor in the arduino to avoid short circuit
  _pullUp = pullUp;
  if(pullUp){
    pinMode(pin1, INPUT_PULLUP);
    pinMode(pin2,  INPUT_PULLUP);
  }else{
    pinMode(pin1, INPUT);
    pinMode(pin2,  INPUT);
  }
  _pin1 = pin1;
  _pin2 = pin2;
}

rotoPhone::number(){
  _state1  = digitalRead(_pin1);
  _state2 = digitalRead(_pin2);
  if(_pullUp){
    if (isNum && num == HIGH && _lastState ==LOW) {
      number ++ ;
    }
  }else{
    if (isNum && num == LOW && _lastState == HIGH) {
      number ++ ;
    }
  }
  if (_state1 == _state2 ) {
    _isNum = true;
  }else{
    _isNum = false;
    //return number;
  }
  _lastState =digitalRead(_pin2);
  delay(10);
}
rotoPhone::lastNumber(){


}
rotoPhone::debug(){
  if(Serial.available){
    Serial.print("Pin state are : Pin1 : ");
    Serial.print(_state1);
    Serial.print("Pin state are Pin2 : ");
    Serial.print(_state2);
    Serial.print(" And current number is : ");
    Serial.println(_number);
  }
}
