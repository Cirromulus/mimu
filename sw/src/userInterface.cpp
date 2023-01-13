#include "userInterface.hpp"

void ui::init() {
    pinMode(LEDR, OUTPUT);
    pinMode(LEDG, OUTPUT);
    digitalWrite(LEDR, 0);
    digitalWrite(LEDG, 0);
}

void ui::waitingForSerial(){
    digitalWrite(LEDR, 1);
    delay(250);
    digitalWrite(LEDR, 0);
    delay(25);
    digitalWrite(LEDG, 1);
    delay(250);
    digitalWrite(LEDG, 0);
    delay(25);
}

void ui::waitingForSensor(){
    digitalWrite(LEDR, 1);
    delay(50);
    digitalWrite(LEDR, 0);
    delay(50);
}

void ui::errorSettingSensorSetting(){
    digitalWrite(LEDR, 1);
    delay(350);
    digitalWrite(LEDR, 0);
    delay(100);
}

void ui::switchOn() {
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

void ui::ready() {
    digitalWrite(LEDG, 1);
    digitalWrite(J2, 1);
    delay(200);
    digitalWrite(LEDG, 0);
    digitalWrite(J2, 0);
    delay(50);
}

void ui::sensorCommunicationError() {
    if constexpr (has_serial)
        if (Serial) Serial.println("ToF Timeout.");

    for(uint8_t i = 0; i < 2; i++)
    {
        digitalWrite(LEDR, 1);
        delay(200);
        digitalWrite(LEDR, 0);
        delay(100);
    }
    delay(300);
}

void ui::digipotCommunicationError(const AD5258::TwiReturnStatus return_status) {
    if constexpr (has_serial)
        if (Serial) Serial.println("Digipot comm error.");
    for(uint8_t i = 0; i < 3; i++)
    {
        digitalWrite(LEDR, 1);
        delay(200);
        digitalWrite(LEDR, 0);
        delay(100);
    }
    delay(200);
    for(uint8_t i = return_status; i > 0; i--) {
        digitalWrite(LEDR, 1);
        delay(100);
        digitalWrite(LEDR, 0);
        delay(100);
    }
    delay(400);
}

void ui::settingDistance(const bool is_setting) {
    digitalWrite(LEDG, is_setting && ((millis() % 512) > 256));
}

void ui::muted(const bool muted){
    if(default_mute_profile.dampening_when_microphone_off == MuteProfile::max_dampening)
        digitalWrite(LEDR, muted);
    else
        digitalWrite(LEDG, muted);
}