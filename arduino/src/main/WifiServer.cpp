// #include <WiFiS3.h>

// char ssid[] = "vrouwenregt13a";
// char pass[] = "REMOVED";

// WiFiServer server(80);

// void setup() {
//   Serial.begin(9600);
//   WiFi.begin(ssid, pass);

//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }

//   Serial.println("Connected to WiFi");
//   server.begin();
// }

// void loop() {
//   WiFiClient client = server.available();
//   if (client) {
//     Serial.println("Client connected");
//     String command = client.readStringUntil('\n');
//     command.trim();

//     if (command == "LED_ON") {
//       digitalWrite(13, HIGH);
//     } else if (command == "LED_OFF") {
//       digitalWrite(13, LOW);
//     }

//     client.println("ACK");
//     client.stop();
//   }
// }