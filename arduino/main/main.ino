
#include "Arduino_LED_Matrix.h"
#include "wifi_helper.h"
#include "secrets.h"

ArduinoLEDMatrix matrix;

const char* ssid = SECRET_SSID;
const char* pass = SECRET_PASS;

void setup() {
  Serial.begin(9600);
  
  connectToWifi(ssid, pass);

  // 3. Update LED matrix
  matrix.begin();
  // matrix.loadFrame();
}

void loop() {
  // Serial.println(WiFi.localIP());
  // 1. Cconnect to client 
  WiFiClient client = server.available();
  if (client) 
  {
    // 2. Parse client command
    Serial.println("Client connected");
    String command = client.readStringUntil('\n');
    command.trim();

    // 3. process client command
    if (command == "LED_ON") {
      digitalWrite(13, HIGH);
    } else if (command == "LED_OFF") {
      digitalWrite(13, LOW);
    }

    // Acknowledge client
    client.println("ACK");
    // client.stop();
  }
}
