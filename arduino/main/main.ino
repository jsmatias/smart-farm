
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
      // 2. Parse client command
      Command command = parseCommand(client);
      processCommand(command, nullptr);

      // Acknowledge client
      client.println("ACK");
      client.stop();
    }
}
