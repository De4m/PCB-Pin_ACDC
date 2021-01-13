#!/bin/bash

# Download Firmware
avrdude -p t13 -c avrisp2 -P usb -v -U flash:w:./.pio/build/ATTiny13A/firmware.hex:i

# Flash Fuses  (H:FD, L:6A)
avrdude -p t13 -c avrisp2 -P usb -v  -U hfuse:w:0xFD:m -U lfuse:w:0x6A:m
 

