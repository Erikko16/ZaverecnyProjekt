#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>

void setup() {
  Serial.begin(115200);

  WiFiManager wifiManager;
  wifiManager.autoConnect("ArduinoAP");

  //if you get here you have connected to the WiFi
  Serial.println("connected...");
}

void loop() {
}
