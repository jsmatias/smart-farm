#pragma once

#include <Arduino.h>

constexpr uint8_t LED_PIN = 13;
constexpr uint8_t PHOTO_DIODE_PIN = A0;

inline void setupPins() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(PHOTO_DIODE_PIN, INPUT);
}