
#include "LiquidCrystal_I2C.h"
#include "Arduino_LED_Matrix.h"
#include "wifi_helper.h"
#include "secrets.h"
#include "wifi_client.h"
#include "command.h"
#include "pins.h"
#include "displays.h"

ArduinoLEDMatrix matrix;

const char* ssid = SECRET_SSID;
const char* pass = SECRET_PASS;

long clientConnectedAt = -5000;

void setup() {
  Serial.begin(9600);

  setupPins();
  connectToWifi(ssid, pass);
  setUpLedMatrix(matrix);
  setUpLcd(WiFi.localIP());
}

void loop() {
  WiFiClient client = server.available();
  if (client) 
  {
    Serial.println("Client connected");
    clientConnectedAt = millis();
    Serial.print("Start: ");
    Serial.println(millis());
    while (client.connected())
    {
      if (client.available())
      {
        Command command = parseCommand(client);
        Serial.print("Parsed at: ");
        Serial.println(millis());
        arduino::String msg = processCommand(command, nullptr);
        Serial.print("Processed at: ");
        Serial.println(millis());
        client.println(msg);
        client.stop();
        break;
      }
    }
  }
  if (millis() - clientConnectedAt > 5000)
  {
    digitalWrite(LED_PIN, analogRead(PHOTO_DIODE_PIN) < 750 ? PinStatus::HIGH : PinStatus::LOW);
  }
}
