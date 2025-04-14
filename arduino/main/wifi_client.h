#pragma once

#include <WiFiS3.h>
#include <string>
#include "command.h"

Command parseCommand(WiFiClient& client);
void processCommand(const Command& commandName, const arduino::String* parameters = nullptr);