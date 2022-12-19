#include <Arduino.h>
#include <config.hpp>

namespace ui {

void waiting(){
    digitalWrite(LED, 1);
    delay(250);
    digitalWrite(LED, 0);
    delay(25);
}

void waitingForSensor(){
    digitalWrite(LED, 1);
    delay(50);
    digitalWrite(LED, 0);
    delay(50);
}

void switchOn()
{
    for(uint8_t i = 0; i < 2; i++)  // Switch-on blink
    {
        digitalWrite(LED, 1);
        digitalWrite(J2, 1);
        delay(100);
        digitalWrite(LED, 0);
        digitalWrite(J2, 0);
        delay(50);
    }
}

void ready()
{
    digitalWrite(LED, 1);
    digitalWrite(J2, 1);
    delay(100);
    digitalWrite(LED, 0);
    digitalWrite(J2, 0);
    delay(50);
}

void sensorCommunicationError() {
    for(uint8_t i = 0; i < 2; i++)
    {
        digitalWrite(LED, 1);
        delay(100);
        digitalWrite(LED, 0);
        delay(100);
    }
}

void muted(const bool muted){
    digitalWrite(LED, muted);
}

};