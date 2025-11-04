#pragma once

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

void board_gpio_init(void);
void board_gpio_set(uint32_t pin, bool value);
bool board_gpio_get(uint32_t pin);

#ifdef __cplusplus
}
#endif
