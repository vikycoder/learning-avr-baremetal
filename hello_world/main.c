#include <avr/io.h>
#include <util/delay.h>

void uart_init() {
    uint16_t ubrr = F_CPU / 16 / 9600 - 1;
    UBRR0H = (ubrr >> 8);
    UBRR0L = ubrr;
    UCSR0B = (1 << TXEN0); // Enable transmitter
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // 8-bit data
}

void uart_send(char c) {
    while (!(UCSR0A & (1 << UDRE0))); // Wait until ready
    UDR0 = c;
}

void uart_print(const char* s) {
    while (*s) uart_send(*s++);
}

int main(void) {
    uart_init();

    while (1) {
        uart_print("Hello, World!\r\n");
        _delay_ms(1000);
    }
}
