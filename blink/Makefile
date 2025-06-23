MCU=atmega328p			# Arduino UNO ATmega328p
F_CPU=16000000UL		# UNO Clock speed 16MHz
CC=avr-gcc				# Cross-compiler
OBJCOPY=avr-objcopy		# Converts .elf to .hex
CFLAGS=-mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os	# Compiler Flags ('Os : optimize for size)

all: main.hex			# Default target .hex

main.hex: main.elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@		# Build .hex from .elf using avr-objcopy
# -R .eeprom	: dont flash EEPROM
#  $<			: first dependency
#  $@			: target name
main.elf: main.c
	$(CC) $(CFLAGS) -o $@ $<

flash: main.hex
	avrdude -c arduino -p m328p -P /dev/ttyACM0 -b 115200 -U flash:w:main.hex

clean:
	rm -f *.elf *.hex
