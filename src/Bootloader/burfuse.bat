avrdude -v -p at90pwm3b -c avrisp2 -P usb -U lfuse:w:0xC3:m -U hfuse:w:0xd2:m -U efuse:w:0xf8:m