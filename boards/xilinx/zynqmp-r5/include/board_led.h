#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void board_led_init(void);
void board_led_on(void);
void board_led_off(void);
void board_led_toggle(void);

#ifdef __cplusplus
}
#endif
