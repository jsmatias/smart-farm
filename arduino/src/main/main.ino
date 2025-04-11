// // Define LRD Pin
// #define LDR_PIN A0
// #define LED_PIN 13

// void setup() {
//   Serial.begin(9600);  // Start serial communication
//   pinMode(LDR_PIN, INPUT);  // Set the LDR_PIN to input
//   pinMode(LED_PIN, OUTPUT);  // Set the LED_PIN to output
// }


// void loop() {
//   Serial.println("Loop is running...");
  
//   int lightLevel = analogRead(LDR_PIN);
//   // Print the light level to the serial monitor
//   Serial.print("Light Level: ");
//   Serial.println(lightLevel);

//   if (lightLevel < 800)
//   {
//     digitalWrite(LED_PIN, HIGH);
//   }
//   else
//   {
//     digitalWrite(LED_PIN, LOW);
//   }

//   delay(1000);
// }

#include <WiFiS3.h>

char ssid[] = "ssid";
char pass[] = "pass";

WiFiServer server(80);

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("Connected to WiFi");
  server.begin();
}

void loop() {
  Serial.println(WiFi.localIP());
  WiFiClient client = server.available();
  if (client) {
    Serial.println("Client connected");
    String command = client.readStringUntil('\n');
    command.trim();

    if (command == "LED_ON") {
      digitalWrite(13, HIGH);
    } else if (command == "LED_OFF") {
      digitalWrite(13, LOW);
    }

    client.println("ACK");
    // client.stop();
  }
}
