#pragma once
#include <WiFiS3.h>
#include <string>
#include "wifi_helper.h"
#include "command.h"
#include "pins.h"


Command parseCommand(WiFiClient& client)
{
    arduino::String command = client.readStringUntil('\n');
    command.trim();

    return commandFromString(command);
}

void processCommand(const Command& command, const arduino::String* parameters = nullptr)
{
    switch (command)
    {
    case Command::LED_ON:
        digitalWrite(LED_PIN, PinStatus::HIGH);
        break;
    case Command::LED_OFF:
        digitalWrite(LED_PIN, PinStatus::LOW);
        break;
    default:
        break;
    }
}


