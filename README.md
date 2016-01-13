# RotoPhone

Simple lib to control rotary dial with Arduino. \n
Written with love and Coffee. :full_moon_with_face:
### Fonction

  **number()**

return -1 if nothing was type. If user input a number return it once at the end of the keyboard rotation.

  **numTime()**

return a unsigned long , it's time of the numerotation

  **isNum()**

return a bool, true is the user is currently composing a number

  **isPick()**

`return a bool, `true` when the headphone is pickup and `false when he is hangup.

  **debug()**

print value on each loop in serial. Don't forget to init your serial to use this function



### Usage

**Code:**
```
#include <RotoPhone.h>

int rotaryNumber;
boolean isPick;

RotoPhone roto(4,5,3, false);

void setup() {
   // if you use debug don't forget to init Serial
   Serial.begin(9600);
   Serial.println("Void setup");
}

void loop() {

  // Capture the rotary number
  rotaryNumber = roto.number();
  if(rotaryNumber >= 0){
    Serial.println(rotaryNumber);
  }

  if(roto.isNum()){
    Serial.print(".");  
  }

  // Capture the phone state
  boolean pickUp = roto.isPick();
  if(pickUp != isPick){
    if(pickUp){
      Serial.println("hangUp");
    } else {
      Serial.println("pickUp");
    }
    isPick = pickUp;
  }

  // print value on each loop
  //roto.debug();
  //Serial.println(roto.isNum());
  delay(20);
}
```

**Prototype :**

![](http://i.imgur.com/mYJ91SB.png)
### WIP
