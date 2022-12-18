/*
  Passthrough keypresses from Arduino Micro second serial to Keyboard
*/

// Keyboard library
#include <Keyboard.h>

// flag if the next key is pressed or released
bool press=true;

void setup() {
  Serial1.begin(9600);
  Keyboard.begin();
  Serial.begin(9600);
}

void loop() {
  if (Serial1.available()) {
    byte k = Serial1.read();
    Serial.write(k);
    Serial.println(" received");

    if (k == 0) {
      press = 0;
    } else if (k == 1) {
      press = 1;
    } else {
      Serial.write(k);
      if (press){
        Keyboard.press(k);
        Serial.println(" pressed");
        
      } else {
        Keyboard.release(k);
        Serial.println(" released");
      }
    }
  }
}
