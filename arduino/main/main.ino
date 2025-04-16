
#include "Arduino_LED_Matrix.h"
#include "wifi_helper.h"
#include "secrets.h"
#include "wifi_client.h"
#include "command.h"

ArduinoLEDMatrix matrix;

const char* ssid = SECRET_SSID;
const char* pass = SECRET_PASS;

void setup() {
  Serial.begin(9600);
  
  connectToWifi(ssid, pass);
  // 3. Update LED matrix
  const uint32_t happy[] = {
    0x19819,
    0x80000001,
    0x81f8000
  };
  matrix.begin();
  matrix.loadFrame(happy);
}

void loop() {
  // Serial.println(WiFi.localIP());
  // 1. Cconnect to client 
  WiFiClient client = server.available();
  if (client) 
    {
      Serial.println("Client connected");
      Serial.print("Start: ");
      Serial.println(millis());
      // 2. Parse client command
      Command command = parseCommand(client);
      Serial.print("Parsed at: ");
      Serial.println(millis());
      

      processCommand(command, nullptr);
      Serial.print("Processed at: ");
      Serial.println(millis());

      // Acknowledge client
      client.println("ACK");
      // client.stop();
    }
}
