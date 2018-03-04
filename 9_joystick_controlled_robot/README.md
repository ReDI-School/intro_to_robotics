# 9. Radio controlled moving robot

## Description
Transmitter board is has a joystick connected. When joystick is moved, transmitter converts the movement
to an action for a robot and sends it to receiver. Receiver board gets the messages from the transmitter
and starts the motors respectively to the commands in the messages. 
and prints them to the console output.

## Hardware used
* 2 * Arduino Uno R3
* 2 * NRF24L01
* Aduino Motor Shield R3
* 2 * DC Motor
* Wheels platform
* 4 * AA Battery pack
* Joystick

## New hardware knowledge

## New C++ knowledge

## Requirements
* When unmodifief Arduino Motor Shield R3 is used, [DigitalIO](https://github.com/greiman/DigitalIO) library 
must be imported to Arduino IDE (available in Arduino IDE library manager). See notes for additional details.
* If RF24 library was installed before (e.g. in example 10), it should be removed, as customized RF24 library
is used in this example (no additional actions are needed to install it - files are copied to the project 
folder). See notes for additional details. 

## Notes
* NRF24L01 radio module uses SPI interface, which is presented on Arduino side by pins 11, 12, 13. 
  Arduino Motor Shield R3 also uses this pins along with some others (see [Documentation -> Input and Output](https://store.arduino.cc/arduino-motor-shield-rev3))
  So there is two ways to connect both motor shield and radio module to Arduino: 
  * Remove connection to pins 11, 12, 13 on the motor shield and move appropriate functions to the free pins - 
    this approach is not covered in this tutorial.
  * Use software SPI emulation on the Arduino side and connect radio module to the pins assigned to software SPI 
    emulation. [RF24](https://github.com/nRF24/RF24) library has already support for software SPI feature, but it 
    requires [DigitalIO](https://github.com/greiman/DigitalIO) library to be installed. Then I copied [RF24](https://github.com/nRF24/RF24)
    library files (only related to Arduino) to the receiver project folder and edited RF24_config.h to allow software SPI 
    and assing new pins to the SPI interface (5, 6, 7). 
* The note above should be ignored if some other motor shield is used which doesn't occupy Arduino SPI pins. 





