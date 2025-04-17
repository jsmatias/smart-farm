#pragma once
#include <WiFiS3.h>
#include <string>
#include "wifi_helper.h"
#include "command.h"
#include "pins.h"


Command parseCommand(WiFiClient& client, uint16_t timeout = 1000)
{
    arduino::String line = "";
    unsigned long start = millis();
    while (client.connected() && millis() - start < timeout) {
        if (client.available()) {
            char c = client.read();
            if (c == '\n') break;
            line += c;
        }
    }

    return commandFromString(line);
}

arduino::String processCommand(const Command& command, const arduino::String* parameters = nullptr)
{
    switch (command)
    {
    case Command::LED_ON:
        digitalWrite(LED_PIN, PinStatus::HIGH);
        return "ACK";
    case Command::LED_OFF:
        digitalWrite(LED_PIN, PinStatus::LOW);
        return "ACK";
    case Command::GET_DATA:
        return "LIGHT_INTENSITY:" + arduino::String(analogRead(PHOTO_DIODE_PIN));
        
    default:
        return "UNKNOWN";
    }
}


