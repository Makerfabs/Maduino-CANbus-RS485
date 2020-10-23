#include<stdio.h>
#include<string.h>
const int RS485_LED = 9;

void setup() {
    SerialUSB.begin(9600);
    Serial1.begin(9600);
    pinMode(RS485_LED,OUTPUT);
    digitalWrite(RS485_LED,LOW);
}


void loop() {
     //get what form serial send to USB serial
    while (Serial1.available() > 0) {
      digitalWrite(RS485_LED,HIGH);  
      SerialUSB.write(Serial1.read()); 
      
      yield();
    }
    //get what form USB serial send to serial
    while (SerialUSB.available() > 0) {
      Serial1.write(SerialUSB.read());
     // digitalWrite(RS485_LED,HIGH);
      yield();
    }
   delay(200); digitalWrite(RS485_LED,LOW);
}
