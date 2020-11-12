#include <SPI.h>
#include "mcp_can.h"
#include <Arduino.h>
#include <U8g2lib.h>

#include <Wire.h>

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

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
    u8g2.begin();

    delay(3000);
    while (CAN_OK != CAN.begin(CAN_500KBPS)) {            // init can bus : baudrate = 500k
        SERIAL.println("CAN BUS Shield init fail");
        SERIAL.println(" Init CAN BUS Shield again");
        delay(100);
    }
    SERIAL.println("CAN BUS Shield init ok!");
    
   
}




String s;

void loop() {
/*********************  CANBUS  ***************************/
    SERIAL.println("In loop");
    

       if (CAN_MSGAVAIL == CAN.checkReceive()) {         // check if data coming
        CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf
        digitalWrite(CAN_LED,HIGH);
        unsigned long canId = CAN.getCanId();
        SERIAL.println("-----------------------------");
        SERIAL.println("get data from ID: 0x");
        SERIAL.println(canId, HEX);
        if (canId == 0x10) 
        {
          char text_T[len];
          for (int i = 0; i < len; i++) { // print the data
                  text_T[i]= char(buf[i]) ;  
          }
          //u8g2.clearBuffer();         // clear the internal memory
          u8g2.setFontDirection(0);
          u8g2.setFont(u8g2_font_inb16_mf);
          //u8g2.setFont(u8g2_font_inb19_mn);
          //u8g2.setFont(u8g2_font_inb24_mf);
          //u8g2.setFont(u8g2_font_inb30_mn);
          //u8g2.setFont(u8g2_font_ncenB08_tr); // choose a suitable font
          u8g2.drawStr(10,20, "T=");  // write something to the internal memory
          u8g2.setFont(u8g2_font_inb19_mn);
          u8g2.drawStr(40,20, text_T);
          u8g2.sendBuffer();
          delay(300);
        }
        if (canId == 0x11) 
        {
          char text_T[len];
          for (int i = 0; i < len; i++) { // print the data
                  text_T[i]= char(buf[i]) ;  
          }
          //u8g2.clearBuffer();         // clear the internal memory
          u8g2.setFontDirection(0);
          u8g2.setFont(u8g2_font_inb16_mf);
          //u8g2.setFont(u8g2_font_inb19_mn);
          //u8g2.setFont(u8g2_font_inb24_mf);
          //u8g2.setFont(u8g2_font_inb30_mn);
          //u8g2.setFont(u8g2_font_ncenB08_tr); // choose a suitable font
          u8g2.drawStr(10,60, "H=");  // write something to the internal memory
          u8g2.setFont(u8g2_font_inb19_mn);
          u8g2.drawStr(40,60, text_T);
          u8g2.sendBuffer();
          delay(300);
        }
    }
    delay(200);

}
