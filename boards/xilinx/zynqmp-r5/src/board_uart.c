#include <stdint.h>
#include <stdbool.h>

// Example UART base address (update as needed for your hardware)
#define BOARD_UART_BASE 0xFF000000
#define BOARD_UART_BAUD 115200

void board_uart_init(void) {
    // TODO: Initialize UART hardware at BOARD_UART_BASE with BOARD_UART_BAUD
}

void board_uart_send(uint8_t data) {
    // TODO: Send a byte over UART
}

uint8_t board_uart_receive(void) {
    // TODO: Receive a byte from UART
    return 0;
}
