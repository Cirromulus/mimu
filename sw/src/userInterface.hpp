#pragma once
#include <config.hpp>
#include <Arduino.h>
#include "AD5258.hpp"

namespace ui {

void init();

void waitingForSerial();

void waitingForSensor();

void errorSettingSensorSetting();

void switchOn();

void ready();

void sensorCommunicationError();

void digipotCommunicationError(const AD5258::TwiReturnStatus return_status = AD5258::TwiReturnStatus::success);

void settingDistance(const bool is_setting = true);

void muted(const bool muted);

};