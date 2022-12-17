#include <Arduino.h>

void setup() {
    // debug onboard PIN
    pinMode(PA0, OUTPUT);
    analogWriteResolution (8);
    analogWriteFrequency(20000);
}

void loop() {
    delay(1000);
    for(unsigned i = 0; i < 256; i++){
        analogWrite(PA0, i);
        delay(1000/256);
    }
    delay(1000);
    for(unsigned i = 155; i >= 0; i--){
        analogWrite(PA0, i);
        delay(1000/256);
    }
}