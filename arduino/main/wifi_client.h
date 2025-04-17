#pragma once

#include <WiFiS3.h>
#include <string>
#include "command.h"

Command parseCommand(WiFiClient& client, uint16_t timeout = 500);
arduino::String processCommand(const Command& commandName, const arduino::String* parameters = nullptr);