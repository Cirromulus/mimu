#pragma once
#include <config.hpp>
#include <Arduino.h>

/*
@return values 0 - ~5000
*/
uint16_t readVcc_mV() {
    uint16_t result;
    // Read 1.1V reference against AVcc
    ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
    delay(2); // Wait for Vref to settle
    ADCSRA |= _BV(ADSC); // Convert
    while (bit_is_set(ADCSRA,ADSC));
    result = ADCL;
    result |= ADCH<<8;
    result = 1126400L / result; // Back-calculate AVcc in mV
    return result;
}

inline void initButton() {
    pinMode(BUTTON, INPUT_PULLUP);
}

inline bool getButton() {
    // PULLUP, so active low
    return !digitalRead(BUTTON);
}

inline void initDebugLines(){
    pinMode(J0, OUTPUT);
    pinMode(J1, OUTPUT);
    pinMode(J2, OUTPUT);
}

inline void setDebugLine(const uint8_t num, const bool on) {
    switch(num){
    case 0:
        digitalWrite(J0, on);
        break;
    case 1:
        digitalWrite(J1, on);
        break;
    case 2:
        digitalWrite(J2, on);
        break;
    default:
        break;
    }
}