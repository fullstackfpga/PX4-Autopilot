#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void board_timer_init(void);
void board_timer_delay(uint32_t ms);
uint32_t board_timer_get_tick(void);

#ifdef __cplusplus
}
#endif
