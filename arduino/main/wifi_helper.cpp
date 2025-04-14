#include "wifi_helper.h"

WiFiServer server(80);

void connectToWifi(const char* ssid, const char* pass)
{
    WiFi.begin(ssid, pass);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("Connected to WiFi");
    server.begin();
}
