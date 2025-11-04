#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void board_uart_init(void);
void board_uart_send(uint8_t data);
uint8_t board_uart_receive(void);

#ifdef __cplusplus
}
#endif
