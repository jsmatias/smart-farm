#pragma once

#include <Arduino.h>

enum class Command
{
    LED_ON,
    LED_OFF,
    GET_DATA,
    UNKNOWN
};

Command commandFromString(const arduino::String cmdStr);
const arduino::String commandToString(Command cmd);