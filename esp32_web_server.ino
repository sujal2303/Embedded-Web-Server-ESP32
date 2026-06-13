#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "Your_WiFi_Name";
const char* password = "Your_WiFi_Password";

WebServer server(80);

void handleRoot() {
  server.send(200, "text/html",
              "<h1>ESP32 Web Server</h1><p>Server Running Successfully</p>");
}

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }

  Serial.println("Connected");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.begin();
}

void loop() {
  server.handleClient();
}
