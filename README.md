# Maduino Zero CANbus with RS485
## Introduce


Maduino zero CANbus with RS485 is an IoT (Internet of things) Solution based on the 32-bit Atmel’s SAMD21 MCU.<br>
[Makerfabs Wiki](https://www.makerfabs.com/wiki/index.php?title=Maduino_Zero_Canbus_with_RS485) <br>
![](https://github.com/Makerfabs/Maduino-CANbus-RS485/blob/main/md_pic/Maduino_RS485_101.jpg)

## Features


* ATMEL SAMD21G18A: 32-bit ARM® Cortex®-M0 up to 48MHz, 256KB flash, 32KB SRAM, LQFP48v • Powered by lithium battery (3.4-4.2V) or AC-DC Adapter.<br>
* Arduino Compatible: Compatible with Arduino IDE.<br>
* Implements CAN V2.0 at 1M/s.<br>
* MCP2515 CAN Bus controller and MCP2551 CAN Bus transceiver.<br>
* Allows for Transmission Speeds Up to 16Mbps of RS-485.<br>
* AutoDirection Enables Driver Automatically on Transmission of RS-485.<br>
* Allowing Up to 128 Transceivers on the Bus of RS-485.<br>
* Extended ESD Protection for RS-485 I/O Pins and CANBUS I/O Pins.<br>
* Integrated DB9 male connector.<br>
* Industrial standard 9 pin sub-D connector.<br>
* 5V power supply.<br>

## Usage


### Software setup

* After installed Arduino, there is no package to support the board (Arduino zero) that is needed to be installed.<br>
* select tools ->Board -> Board Manager, search "Arduino zero" and install "Arduino SAMD Boards".<br>
* Select Tools ->Board -> Arduino Zero (Native USB Port), select Tools -> Port -> com…<br>

### Test

* The sensors or devices which can carry on RS485 or CANbus are connected to the board through cables. in this project, use the same board instead of the device being tested, and connected two board by cables or Dupont Lines to check the communication between boards.<br>
* The pins connection is:<br>

|Maduino Zero CANbus with RS485 |Devices or sensors |
|---|---|
|GND |GND |
|RS485_A |RS485_A |
|RS485_B |RS485_B |
|CAN_H | CAN_H |
|CAN_L | CAN_L |

* One board upload the code xxxx , and the other upload the code xxx. Both programs include the functions which can realize receiving and sending data in RS485 communication mode and CANBUS communication mode.<br>
* After the upload is successful, open the Serial Monitor and you can observe that the board is receiving and sending data cyclically through CANBUS.<br>
![](https://github.com/Makerfabs/Maduino-CANbus-RS485/blob/main/md_pic/Maduino_RS485_103.jpg)
* Send data through the Serial Monitor, and receive the data through RS485 communication on another board.<br>
![](https://github.com/Makerfabs/Maduino-CANbus-RS485/blob/main/md_pic/Maduino_RS485_104.jpg)
![](https://github.com/Makerfabs/Maduino-CANbus-RS485/blob/main/md_pic/Maduino_RS485_105.jpg)














