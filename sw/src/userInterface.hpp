#pragma once
#include <config.hpp>
#include <Arduino.h>

namespace ui {

void init() {
    pinMode(LEDR, OUTPUT);
    pinMode(LEDG, OUTPUT);
    digitalWrite(LEDR, 0);
    digitalWrite(LEDG, 0);
}

void waitingForSerial(){
    digitalWrite(LEDR, 1);
    delay(250);
    digitalWrite(LEDR, 0);
    delay(25);
    digitalWrite(LEDG, 1);
    delay(250);
    digitalWrite(LEDG, 0);
    delay(25);
}

void waitingForSensor(){
    digitalWrite(LEDR, 1);
    delay(50);
    digitalWrite(LEDR, 0);
    delay(50);
}

void settingTimingBudget(){
    digitalWrite(LEDR, 1);
    delay(350);
    digitalWrite(LEDR, 0);
    delay(100);
}

void switchOn()
{
    for(uint8_t i = 0; i < 2; i++)  // Switch-on blink
    {
        digitalWrite(LEDG, 1);
        digitalWrite(J2, 1);
        delay(100);
        digitalWrite(LEDG, 0);
        digitalWrite(J2, 0);
        delay(50);
    }
}

void ready()
{
    digitalWrite(LEDG, 1);
    digitalWrite(J2, 1);
    delay(100);
    digitalWrite(LEDG, 0);
    digitalWrite(J2, 0);
    delay(50);
}

void sensorCommunicationError() {
    if(has_serial && Serial) Serial.println("Timeout.");
    for(uint8_t i = 0; i < 2; i++)
    {
        digitalWrite(LEDR, 1);
        delay(200);
        digitalWrite(LEDR, 0);
        delay(100);
    }
}

void settingDistance(const bool is_setting = true) {
    digitalWrite(LEDG, is_setting && (millis() % 512) > 256);
}

void muted(const bool muted){
    if(default_mute_profile.dampening_when_microphone_off == MuteProfile::max_dampening)
        digitalWrite(LEDR, muted);
    else
        digitalWrite(LEDG, muted);
}

};