#pragma once

#include "LiquidCrystal_I2C.h"
#include "Arduino_LED_Matrix.h"


inline void setUpLedMatrix()
{
    ArduinoLEDMatrix matrix;
    const uint32_t happy[] = {
      0x19819,
      0x80000001,
      0x81f8000
    };
    matrix.begin();
    matrix.loadFrame(happy);
}

inline void setUpLcd(const arduino::IPAddress& localIP)
{
    LiquidCrystal_I2C lcd(0x27, 16, 2);
    
    lcd.init();
    lcd.backlight();    
    lcd.setCursor(0, 0);
    lcd.print("Hello, from Bee!");
    lcd.setCursor(0, 1);
    lcd.print(localIP);
}