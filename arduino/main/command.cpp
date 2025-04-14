#include "command.h"

Command commandFromString(const arduino::String cmdStr)
{
    if (cmdStr == "LED_ON") return Command::LED_ON;
    if (cmdStr == "LED_OFF") return Command::LED_OFF;
    return Command::UNKNOWN;
}

const arduino::String commandToString(Command cmd)
{
    switch (cmd)
    {
        case Command::LED_ON: return "LED_ON";
        case Command::LED_OFF: return "LED_OFF";
        default: return "UNKNOWN";
    }
}