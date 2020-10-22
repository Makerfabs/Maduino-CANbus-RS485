
#include "mcp_can.h"
#include <SPI.h>

/*SAMD core*/

#define SERIAL SerialUSB


const int SPI_CS_PIN = 3;
const int RS485_LED = 9;
const int CAN_LED = 8;

MCP_CAN CAN(SPI_CS_PIN);                                    // Set CS pin

void setup() {
    SERIAL.begin(9600);
    Serial1.begin(9600);
    pinMode(RS485_LED,OUTPUT);
    pinMode(CAN_LED,OUTPUT);
    while (CAN_OK != CAN.begin(CAN_500KBPS)) {            // init can bus : baudrate = 500k
        SERIAL.println("CAN BUS Shield init fail");
        SERIAL.println(" Init CAN BUS Shield again");
        delay(100);
    }
    SERIAL.println("CAN BUS Shield init ok!");
}

unsigned char stmp[8] = {1, 0, 9, 9, 9, 0, 0, 7};

void loop() {
    SERIAL.println("In loop");
/************************  CANBUS  ********************************/ 
    // send data:  id = 0x70, standard frame, data len = 8, stmp: data buf
    CAN.sendMsgBuf(0x70, 0, 8, stmp);
    delay(4000);                       // send data once per second

    unsigned char len = 0;
    unsigned char buf[8];

    if (CAN_MSGAVAIL == CAN.checkReceive()) {         // check if data coming
        CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf
        digitalWrite(CAN_LED,HIGH);
        unsigned long canId = CAN.getCanId();
        SERIAL.println("-----------------------------");
        SERIAL.println("get data from ID: 0x");
        SERIAL.println(canId, HEX);
        for (int i = 0; i < len; i++) { // print the data
            SERIAL.print(buf[i]);
            SERIAL.print("\t");            
        }
        SERIAL.println();
    }
    digitalWrite(CAN_LED,LOW);

/*****************  RS485  ***********************/
    //get the data from RS485
    while (Serial1.available() > 0) {
        SerialUSB.write(Serial1.read());
        digitalWrite(RS485_LED,HIGH);  
        yield();
    }
    //send the data to RS485 
    while (SerialUSB.available() > 0) {
        Serial1.write(SerialUSB.read());
        yield();
    }
    digitalWrite(RS485_LED,LOW);
}

/*********************************************************************************************************
    END FILE
*********************************************************************************************************/
