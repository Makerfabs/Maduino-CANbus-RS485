#include <SPI.h>
#include "mcp_can.h"

#define SERIAL SerialUSB

const int SPI_CS_PIN = 3;
const int CAN_LED = 8;


MCP_CAN CAN(SPI_CS_PIN);                                    // Set CS pin

const byte interruptPin = 2;
unsigned char flagRecv = 0;
unsigned char len = 0;
unsigned char buf[8];
char str[20];

void setup() {
    SERIAL.begin(9600);
    Serial1.begin(9600);
    pinMode(CAN_LED,OUTPUT);
    delay(3000);
    while (CAN_OK != CAN.begin(CAN_500KBPS)) {            // init can bus : baudrate = 500k
        SERIAL.println("CAN BUS Shield init fail");
        SERIAL.println(" Init CAN BUS Shield again");
        delay(100);
    }
    SERIAL.println("CAN BUS Shield init ok!");

    attachInterrupt(digitalPinToInterrupt(interruptPin), MCP2515_ISR, FALLING); // start interrupt


    /*
        set mask, set both the mask to 0x3ff
    */
    CAN.init_Mask(0, 0, 0x3ff);                         // there are 2 mask in mcp2515, you need to set both of them
    CAN.init_Mask(1, 0, 0x3ff);

    /*
        set filter, we can receive id from 0x04 ~ 0x09
    */
    CAN.init_Filt(0, 0, 0x70);                          // there are 6 filter in mcp2515
    /*CAN.init_Filt(1, 0, 0x05);                          // there are 6 filter in mcp2515

    CAN.init_Filt(2, 0, 0x06);                          // there are 6 filter in mcp2515
    CAN.init_Filt(3, 0, 0x07);                          // there are 6 filter in mcp2515
    CAN.init_Filt(4, 0, 0x08);                          // there are 6 filter in mcp2515
    CAN.init_Filt(5, 0, 0x09);   */                       // there are 6 filter in mcp2515
    SERIAL.println(" Init CAN BUS ok----");
}

void MCP2515_ISR() {
    flagRecv = 1;
}


void loop() {
/*********************  CANBUS  ***************************/
    SERIAL.println("In loop");
    if (flagRecv) {                // check if get data
        flagRecv = 0;                // clear flag
        CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf
        digitalWrite(CAN_LED,HIGH);
        SERIAL.println("\r\n------------------------------------------------------------------");
        SERIAL.print("Get Data From id: ");
        SERIAL.println(CAN.getCanId());
        for (int i = 0; i < len; i++) { // print the data
            SERIAL.print("0x");
            SERIAL.print(buf[i], HEX);
            SERIAL.print("\t");
        }
        SERIAL.println();
        delay(200);
    }
    digitalWrite(CAN_LED,LOW);
    // send the message
    CAN.sendMsgBuf(0x10, 0, 8, buf);
    delay(1000);    


}
