# Maduino Zero CANbus with RS485
## Introduce

CAN-BUS is a common industrial communication bus because of its long travel distance, medium communication speed, and high reliability, it is the backbone of many protocols with applications in automation, industrial systems, building management. This Maduino Zero CAN-BUS based on SAMD21G18A, with the CAN controller MCP2515 and CAN transceiver MAX3051, to create a ready-to-use CAN-bus port. With this board, you can easily get/send your local data remotely with a standard CAN Bus. For example, you can collect local sensor data, using the Maduino zero ports, and send all the data to remote servers, to create remote-monitor with reliable CAN-Bus communication.<br>
[Makerfabs Wiki](https://www.makerfabs.com/wiki/index.php?title=Maduino_Zero_Canbus_with_RS485) <br>
<img src="https://github.com/Makerfabs/Maduino-CANbus-RS485/blob/main/md_pic/Maduino_RS485_101.jpg" width="400" height="400"  alt=""/><br/>

## Features


* ATMEL SAMD21G18A: 32-bit ARM® Cortex®-M0, Arduino Zero bootloader pre-loaded.<br>
* CAN-BUS/ RS-485.<br>
* Implements CAN V2.0 at 1M/s.<br>
* MCP2515 CAN Bus controller and MAX3051 CAN Bus transceiver.<br>
* Allows for Transmission Speeds Up to 16Mbps of RS-485.<br>
* Industrial standard 9 pins sub-D connector.<br>

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

<img src="https://github.com/Makerfabs/Maduino-CANbus-RS485/blob/main/md_pic/Maduino_RS485_103.jpg" width="900" height="1000"  alt=""/><br/>

#### RS485
* Two boards upload the [RS485.ino](https://github.com/Makerfabs/Maduino-CANbus-RS485/blob/main/RS485/RS485.ino) ,
* After the upload is successful, open the Serial Monitor and send data through the Serial Monitor, and receive the data through RS485 communication on another board. The blue indicator light on the board will flash when data is received.<br>


<img src="https://github.com/Makerfabs/Maduino-CANbus-RS485/blob/main/md_pic/Maduino_RS485_104.jpg" width="1000" height="300"  alt=""/><br/>
<img src="https://github.com/Makerfabs/Maduino-CANbus-RS485/blob/main/md_pic/Maduino_RS485_105.jpg" width="400" height="400"  alt=""/><br/>














