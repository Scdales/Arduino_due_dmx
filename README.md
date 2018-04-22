# Arduino_due_dmx
A script for interfacing an Arduino Due with the DMX protocol. This will allow you to read a DMX universe and ensure you're receiving the correct data

## Story

It was difficult to get the Arduino Due to interface into DMX lines, and this lead me to engineer a solution. I wanted to use the Due because of it's superior CPU speeds as my project was operating motors and monitoring encoders while being controlled by a DMX board.

## Hardware

### CTC-DRA-10-1 - Arduino DMX Shield
https://www.dfrobot.com/product-984.html

This is a shield with a MAX485 chip that will assist in interpreting the DMX signals. This board also has the capability of broadcasting, but is out of scope for this.

### Logic Level Converter
https://www.sparkfun.com/products/12009

This is needed because the Arduino Due operates at 3.3V and will shift 5V signals to 3.3 as to not damage the Due. This can also be used with I2C comms, and is simple to wire.



## Usage

Use this script to make sure your Due is correctly reading the DMX protocol. Make sure you're getting the correct values at the correct addresses. Bear in mind that Serial logging in other Arduino models has influenced CPU speed to the point where it impacts the ability for the arduino to read the DMX effectively.

The maximum and minimum values may need to be altered depending on what you're interfacing with. I've had to use values of 250 - 500 microseconds for my test system, but in production the gap between frames was ~1000 microseconds.
