#pragma once
#include <WiFiS3.h>
#include <string>
#include "wifi_helper.h"
#include "command.h"


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
        digitalWrite(13, PinStatus::HIGH);
        break;
    case Command::LED_OFF:
        digitalWrite(13, PinStatus::LOW);
        break;
    default:
        break;
    }
}


