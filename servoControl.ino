#include <Servo.h> 

int servoPin = 2; //D9 ESP8266

Servo Servo1; 
void setup() { 
   Servo1.attach(servoPin); 
}
void loop(){ 
   Servo1.write(0); 
   delay(1000);  
   Servo1.write(180); 
   delay(1000); 
}
