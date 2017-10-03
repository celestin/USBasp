avr-gcc -mmcu=atmega8 -Wall -Os -o main.o main.c
avr-objcopy -j .text -j .data -O ihex main.o main.hex
sudo avrdude -p m8 -c usbasp -e -U flash:w:main.hex

