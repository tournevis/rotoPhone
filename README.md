# RotoPhone

Simple lib to control rotary dial with Arduino


### Usage

```
#include <RotoPhone.h>
RotoPhone roto(4,5);
void setup() {
   Serial.begin(9600);
}
void loop() {
  Serial.println(roto.number());
  roto.debug();
  delay(20);
}
```
### WIP
