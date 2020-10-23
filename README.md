# Maduino Zero CANbus with RS485
## Introduce


Maduino zero CANbus with RS485 is an IoT (Internet of things) Solution based on the 32-bit Atmel’s SAMD21 MCU.<br>
[Makerfabs Wiki](https://www.makerfabs.com/wiki/index.php?title=Maduino_Zero_Canbus_with_RS485) <br>
<img src="https://github.com/Makerfabs/Maduino-CANbus-RS485/blob/main/md_pic/Maduino_RS485_101.jpg" width="400" height="400"  alt=""/><br/>

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

#### CANBUS
* One board upload the [CAN_Sender.ino](https://github.com/Makerfabs/Maduino-CANbus-RS485/blob/main/CAN_Sender/CAN_Sender.ino) , and the other upload the [CAN_Receiver.ino](https://github.com/Makerfabs/Maduino-CANbus-RS485/blob/main/CAN_Receiver/CAN_Receiver.ino). Both programs include the functions which can realize receiving and sending data in RS485 communication mode and CANBUS communication mode.<br>
* After the upload is successful, open the Serial Monitor and you can observe that the board is receiving and sending data cyclically through CANBUS. The green indicator light on the board will flash when data is received.<br>
![](https://github.com/Makerfabs/Maduino-CANbus-RS485/blob/main/md_pic/Maduino_RS485_103.jpg)
<img src="https://github.com/Makerfabs/Maduino-CANbus-RS485/blob/main/md_pic/Maduino_RS485_103.jpg" width="400" height="500"  alt=""/><br/>

#### RS485
* Two boards upload the [RS485.ino](https://github.com/Makerfabs/Maduino-CANbus-RS485/blob/main/RS485/RS485.ino) ,
* After the upload is successful, open the Serial Monitor and send data through the Serial Monitor, and receive the data through RS485 communication on another board. The blue indicator light on the board will flash when data is received.<br>
![](https://github.com/Makerfabs/Maduino-CANbus-RS485/blob/main/md_pic/Maduino_RS485_104.jpg)
![](https://github.com/Makerfabs/Maduino-CANbus-RS485/blob/main/md_pic/Maduino_RS485_105.jpg)
<img src="https://github.com/Makerfabs/Maduino-CANbus-RS485/blob/main/md_pic/Maduino_RS485_104.jpg" width="375" height="350"  alt=""/><br/>
<img src="https://github.com/Makerfabs/Maduino-CANbus-RS485/blob/main/md_pic/Maduino_RS485_105.jpg" width="400" height="400"  alt=""/><br/>














