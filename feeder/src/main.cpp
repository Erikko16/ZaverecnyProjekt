#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <WiFiManager.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <Servo.h> 


/*const char *ssid     = "ESPNet";
const char *password = "";*/
int servoPin = 2; //D9 ESP8266
Servo myservo; 
int hodina=15;
bool probiha= false;
int pos = 0; 

const long utcOffsetInSeconds = 3600;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "192.168.1.1", utcOffsetInSeconds);

void setup(){
  myservo.attach(2);
  Serial.begin(115200);
  WiFiManager wifiManager;
  wifiManager.autoConnect("ArduinoAP");
  Serial.println("connected...");
  timeClient.begin();
}

void otoceni(){
  probiha = true;
  for (pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);              
    delay(15);                       
  }
  for (pos = 180; pos >= 0; pos -= 1) { 
    myservo.write(pos);              
    delay(15);                       
  }
}

void loop() {
  if(millis()%100 == 0){
  timeClient.update();
  Serial.print(daysOfTheWeek[timeClient.getDay()]);
  Serial.print(", ");
  Serial.print(timeClient.getHours());
  Serial.print(":");
  Serial.print(timeClient.getMinutes());
  Serial.print(":");
  Serial.println(timeClient.getSeconds());
  }

  for(int i=0;i<3;i++){
    if((timeClient.getHours()==hodina && timeClient.getMinutes() == 03 && timeClient.getSeconds() <= 50) != probiha){
      Serial.print("Pokus");
      otoceni();
    }
  }
}

