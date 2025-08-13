/****************************************************************************
 *
 *   Copyright (c) 2024 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/**
 * @file init.c
 *
 * ZynqMP SoC R5 board initialization
 */

#include <px4_platform_common/px4_config.h>
#include <px4_platform_common/micro_hal.h>

#include <nuttx/board.h>
#include <arch/board/board.h>

#include "board_config.h"

/****************************************************************************
 * Name: board_peripheral_reset
 *
 * Description:
 *   Reset board peripherals
 *
 ****************************************************************************/

void board_peripheral_reset(int ms)
{
	/* ZynqMP R5 has no peripheral reset capability */
	UNUSED(ms);
}

/****************************************************************************
 * Name: board_on_reset
 *
 * Description:
 *   Called on reset, before main
 *
 ****************************************************************************/

void board_on_reset(int status)
{
	/* ZynqMP R5 has no reset capability */
	UNUSED(status);
}

/****************************************************************************
 * Name: board_app_initialize
 *
 * Description:
 *   Perform architecture specific initialization
 *
 ****************************************************************************/

int board_app_initialize(uintptr_t arg)
{
	UNUSED(arg);

	/* Configure board GPIO */
	px4_platform_configure_gpio_pins(px4_board_gpio_pins, arraySize(px4_board_gpio_pins));

	/* Configure SPI */
	px4_platform_spi_init();

	/* Configure I2C */
	px4_platform_i2c_init();

	return OK;
}

/****************************************************************************
 * Name: board_late_initialize
 *
 * Description:
 *   Late board initialization
 *
 ****************************************************************************/

void board_late_initialize(void)
{
	/* Nothing to do here */
}

/****************************************************************************
 * Name: board_get_uuid
 *
 * Description:
 *   Get board UUID - not available on ZynqMP R5
 *
 ****************************************************************************/

void board_get_uuid(uuid_byte_t uuid_bytes)
{
	/* ZynqMP R5 has no UUID */
	for (int i = 0; i < PX4_CPU_UUID_BYTE_LENGTH; i++) {
		uuid_bytes[i] = 0;
	}
}

/****************************************************************************
 * Name: board_get_uuid32
 *
 * Description:
 *   Get board UUID as 32-bit values
 *
 ****************************************************************************/

void board_get_uuid32(uuid_uint32_t uuid_words)
{
	/* ZynqMP R5 has no UUID */
	for (int i = 0; i < PX4_CPU_UUID_WORD32_LENGTH; i++) {
		uuid_words[i] = 0;
	}
}