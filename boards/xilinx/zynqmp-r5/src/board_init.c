#include "zynqmp-r5.h"
#include "board_led.h"
#include "board_uart.h"
#include "board_timer.h"
#include "board_gpio.h"

// Board initialization entry point
void board_init(void) {
    board_led_init();
    board_uart_init();
    board_timer_init();
    board_gpio_init();
    // Add more initialization as needed
}



