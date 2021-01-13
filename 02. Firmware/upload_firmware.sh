#!/bin/bash
avrdude -p t13 -c avrisp2 -P usb -v -U flash:w:./.pio/build/ATTiny13A/firmware.hex:i
