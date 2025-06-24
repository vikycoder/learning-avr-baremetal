# Bare-Metal Programming on ATmega328P (Arduino Uno) – Zero to Hero Checklist

---

## PHASE 0: Setup & Fundamentals

- [ ] **Install Toolchain (Arch Linux)**
  - `sudo pacman -S avr-gcc avr-libc avrdude make`
- [ ] **Understand Bare-Metal Concepts**
  - No Arduino library, direct register manipulation
  - [Intro to Bare-Metal Programming](https://interrupt.memfault.com/blog/bare-metal-basics)
- [ ] **Read ATmega328P Datasheet**
  - [ATmega328P Datasheet (Microchip)](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf)
- [ ] **Understand AVR Architecture**
  - Harvard architecture, program/IO memory
  - Status register, SP, PC, Flash, SRAM

---

## PHASE 1: Blink & Build System

- [ ] Write "Hello World" LED blink using registers
- [ ] Learn `PORTx`, `DDRx`, `PINx`
- [ ] Use `util/delay.h` for delay
- [ ] Write your own Makefile
- [ ] Compile using `avr-gcc` → `.hex`
- [ ] Upload using `avrdude`
  - [Makefile Template](https://github.com/MCUdude/MiniCore/blob/master/extra/Makefile)
- [ ] Understand fuse bits and set them if needed

---

## PHASE 2: Digital I/O and Interrupts

- [ ] Poll input button press
- [ ] External Interrupts: `INT0`, `INT1`
- [ ] Pin Change Interrupts: `PCINTx`
- [ ] Configure `EIMSK`, `EICRA`, `PCMSKx`, `PCICR`
  - [AVR Interrupts Tutorial](https://www.electronicwings.com/avr-atmega/interrupts-in-atmega328)

---

## PHASE 3: Timers and PWM

- [ ] Understand Timer0, Timer1, Timer2
- [ ] Configure for:
  - [ ] Normal mode
  - [ ] CTC mode
  - [ ] Fast PWM / Phase Correct PWM
- [ ] Use `TCCRn`, `OCRn`, `TCNTn`, `TIMSKn`
- [ ] Timer Compare/Overflow interrupts
- [ ] PWM for LED dimming, servo control
  - [AVR Timer Tutorial](https://www.best-microcontroller-projects.com/atmega328-timer.html)

---

## PHASE 4: Analog Peripherals

- [ ] Read analog sensors using ADC
- [ ] Use `ADMUX`, `ADCSRA`, `ADCH`, `ADCL`
- [ ] Set reference voltage, prescaler
- [ ] Use ADC interrupt (`ADIE`, `ADIF`)
- [ ] Explore Analog Comparator: `ACSR`
  - [AVR ADC Tutorial](https://exploreembedded.com/wiki/Analog_Inputs_using_ADC_in_AVR)

---

## PHASE 5: Communication Protocols

### UART (Serial)
- [ ] Setup `UBRR`, `UCSRx` registers
- [ ] TX and RX data
- [ ] Interrupt-based UART
- [ ] Use `minicom` or `screen`

### SPI
- [ ] Use `SPCR`, `SPSR`, `SPDR`
- [ ] Master-slave communication
- [ ] Interfacing with EEPROM, 74HC595

### I2C (TWI)
- [ ] Use `TWBR`, `TWCR`, `TWDR`
- [ ] Send START, STOP, ACK, NACK
- [ ] Interface with I2C sensors
  - [AVR TWI Tutorial](https://www.electronicwings.com/avr-atmega/i2c-communication-in-atmega328)

---

## PHASE 6: Memory & Power

- [ ] Use EEPROM for storing data
  - [ ] `eeprom_read_byte`, `eeprom_write_byte`
- [ ] Understand sections: `.data`, `.bss`, `.text`, stack
- [ ] Use sleep modes: Idle, ADC Noise Reduction, Power-down
- [ ] Configure Power Reduction Register: `PRR`
  - [AVR Power Management](https://www.avrfreaks.net/forum/power-management-atmega328p)

---

## PHASE 7: Integrated Projects

- [ ] Weather station: ADC + I2C + UART
- [ ] Soft serial logger to EEPROM
- [ ] Motor controller: PWM + ADC feedback
- [ ] IR remote: external interrupt + timer + PWM

---

## PHASE 8: Debugging & Optimization

- [ ] Use `avr-objdump -D program.elf > program.asm`
- [ ] Use `-Os` and `-Og` for size/speed
- [ ] Profile with timers
- [ ] Simulate with [SimAVR](https://github.com/buserror/simavr)
- [ ] Optional: Learn linker scripts (advanced)

---

## Suggested Books & References

- [AVR Microcontroller and Embedded Systems – Mazidi](https://www.amazon.in/Muhammad-Ali-Mazidi/e/B001K7Y13I)
- [AVR Libc Manual](https://www.nongnu.org/avr-libc/user-manual/index.html)
- [AVR Freaks Forum](https://www.avrfreaks.net/)
- [MCUdude GitHub Repos (Makefiles)](https://github.com/MCUdude)

---

## Optional Tools & Enhancements

- [ ] Use `vim` or `nvim` with syntax highlighting for AVR
- [ ] Use VSCode + `PlatformIO` for easier navigation (not strictly bare-metal)
- [ ] Use USBasp or Arduino as ISP
- [ ] Connect logic analyzer (Saleae / Sigrok) for SPI/I2C/UART capture

---

## Final Goal: Total Peripheral Utilization

- [ ] GPIO (input/output)
- [ ] Timers (delay, PWM)
- [ ] ADC
- [ ] UART
- [ ] SPI
- [ ] I2C
- [ ] EEPROM
- [ ] Interrupts
- [ ] Analog Comparator
- [ ] Sleep & Power Reduction
