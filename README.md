# IR_LightStrips
## Description
The primary goal of this project is to add remote-controlled LED strips to the desks in the IEEE room. When the lights are on in the room slight electrical interference occurs on sensitive devices. As such, an alternate lighting source would be of use when testing particularly sensitive devices. Additionally, the lights would help increase visability when working at the desks, even with the lights on. 

## Components
Below are the components to be used for the project. Additional components can be added in the future.
### [Arduino Nano]{https://en.wikipedia.org/wiki/Arduino_Nano}
At the time of writing, there are six Arduino Nanos in the IEEE room. The Arduino Nano uses the same ATmega328p microcontroller as the Arduino UNO and offers the same specs and connectivity. 

### [WS2812B LED Strips] {https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf} 
The WS2812B allows for individual LED's to be individually addressed. This allows for a variety of patterns to be displayed through the LEDs. The [FastLED]{https://github.com/FastLED/FastLED} library will be used to control the LEDS. Here's an [example]{https://howtomechatronics.com/tutorials/arduino/how-to-control-ws2812b-individually-addressable-leds-using-arduino/} of the library in action. Once basic functionality is verified, the next goal would be to add the ability to choose colors and patterns to select from using the IR remote.

### IR remote
There are multiple IR remotes in the IEEE room at the moment and several IR receivers. DroneBot workshop made an excellent article [https://dronebotworkshop.com/using-ir-remote-controls-with-arduino/] on the topic.
