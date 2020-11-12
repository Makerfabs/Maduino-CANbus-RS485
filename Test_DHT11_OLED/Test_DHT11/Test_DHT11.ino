
#include "mcp_can.h"
#include <SPI.h>
#include<DHT.h>
DHT  dht(10,DHT11);



#define SERIAL SerialUSB

const int SPI_CS_PIN = 3;
const int CAN_LED = 8;

MCP_CAN CAN(SPI_CS_PIN);                                    // Set CS pin

void setup() {
    SERIAL.begin(9600);
    Serial1.begin(9600);
    dht.begin();
    pinMode(CAN_LED,OUTPUT);
    while (CAN_OK != CAN.begin(CAN_500KBPS)) {            // init can bus : baudrate = 500k
        SERIAL.println("CAN BUS Shield init fail");
        SERIAL.println(" Init CAN BUS Shield again");
        delay(100);
    }
    SERIAL.println("CAN BUS Shield init ok!");
}

//unsigned char stmp[8] = {0,0,0,0,0,0,0,0};
String stmp1 ;
String stmp2 ;

void loop() {
    SERIAL.println("In loop");

    float t = dht.readTemperature();
    float h = dht.readHumidity();
    SERIAL.print("T=");
    SERIAL.println(t);
    SERIAL.print("H=");
    SERIAL.println(h);
    stmp1 = t;
    stmp2 = h;
    char data_t[stmp1.length()];
    char data_h[stmp2.length()];
    stmp1.toCharArray( data_t, stmp1.length());
    stmp2.toCharArray( data_h,stmp2.length());    
    unsigned char stmp_send1[stmp1.length()];
    unsigned char stmp_send2[stmp2.length()];
    for (int i=0;i<stmp1.length();i++)
        stmp_send1[i] = stmp1[i];
    for (int i=0;i<stmp2.length();i++)
        stmp_send2[i] = stmp2[i];
    

/************************  CANBUS  ********************************/ 
    // send data:  id = 0x70, standard frame, data len = 8, stmp: data buf
    digitalWrite(CAN_LED,HIGH);
    CAN.sendMsgBuf(0x10, 0, stmp1.length(), stmp_send1);
    delay(500);
    CAN.sendMsgBuf(0x11, 0, stmp2.length(), stmp_send2);
    delay(500);                       // send data once per second
    digitalWrite(CAN_LED,LOW);
    delay(3000);  

}

/*********************************************************************************************************
    END FILE
*********************************************************************************************************/
