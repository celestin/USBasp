# avr dev env in Linux

## ubuntu/centos

1. install avrdude

``` sudo apt-get install avrdude ```

2. install compiler
```
# ubuntu
sudo apt-get install gcc-avr binutils-avr avr-libc
# centos
sudo yum install gcc-avr binutils-avr avr-libc

avr-gcc -mmcu=atmega128 -Wall -Os -o led.o led.c
# -mmcu: avr type

# convert to hex
avr-objcopy -j .text -j .data -O ihex led.o led.hex

.data: used to store date
```

3. burn the firmware
```
sudo avrdude -p m128 -c usbasp -e -U flash:w:led.hex
# m128: atmega128
```

```makefile
###################################
# Makefile, for AVR Programming
 
PROJECT =
# Target name:
TARGET =
 
# Target type
MCU = atmega128
PROGRAMMER = usbasp
F_CPU = 16000000UL
 
SRC =
OBJ = $(SRC:.c=.o)
 
# Compiler / Linker flags:
CFLAGS = -mmcu=$(MCU) -Wall -Os -std=gnu99 -D F_CPU=$(F_CPU) -funsigned-char -funsigned-bitfields -
fpack-struct -fshort-enums
LDFLAGS = -mmcu=$(MCU) -Wl,-Map=$(TARGET).map
 
###################################
# Makerules:
 
.PHONY: compile flash clean
 
compile:$(TARGET).hex $(TARGET).eep $(TARGET).lss
 
flash: compile
 avrdude -c $(PROGRAMMER) -P usb -p $(MCU) -U flash:w:$(TARGET).hex
 # sleep 2
 # avrdude -c $(PROGRAMMER) -P usb -p $(MCU) -U eeprom:w:$(TARGET).eep
 
clean:
 rm -f $(OBJ) $(TARGET).*
 
###################################
# Psudorules:
 
%.eep: %.hex
 avr-objcopy -j .eeprom --set-section-flags=.eeprom="alloc,load" --change-section-lma .eeprom=0
--no-change-warnings -O ihex $< $@
 
%.hex: %.elf
 avr-objcopy -O ihex -R .eeprom -R .fuse -R .lock -R .signature $< $@
 
%.lss: %.elf
 avr-objdump -h -S $< > $@
 
%.elf: $(OBJ)
 avr-gcc $^ $(LDFLAGS) -o $@
 
%.o : %.c
 avr-gcc $(CFLAGS) -c $< -o $@
```
