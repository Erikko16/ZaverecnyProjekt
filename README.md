# ZaverecnyProjekt
<br>
Cílem je vytvořit automatické krmítko ryb pomocí esp a servo motoru<br>

<br>
Inspirace:<br> 
https://www.youtube.com/watch?v=aifWWOIwX1A<br>
https://www.youtube.com/watch?v=ijt6JUwdLgY<br>
<br>
1.Září - zakoupit součástky a začít s obvodem <br>
-součástky zakoupene<br>
2.Říjen - Dokončit zapojení obvodu a začít s software<br>
3.Listopad - Dokončit software<br>
4.Prosinec - Dokončení projektu a odevzdát dokumentace<br>
<br>
#include <Servo.h>

Servo servo;

void setup() {

    servo.attach(5); D1
    servo.write(0);

    delay(2000);

}

void loop() {

    servo.write(90);

    delay(1000);

    servo.write(0);

    delay(1000);
    

}
Odkazy:<br>
ESP: https://arduino-shop.cz/arduino/1457-esp8266-esp-12e-ota-wemos-d1-ch340-wifi-arduino-ide-uno-r3.html<br>
Funkce Servo motoru: https://navody.arduino-shop.cz/arduino-projekty/servo-motor.html


