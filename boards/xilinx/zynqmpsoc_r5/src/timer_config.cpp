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
 * @file timer_config.cpp
 *
 * ZynqMP SoC R5 timer configuration
 */

#include <px4_platform_common/px4_config.h>
#include <px4_platform_common/micro_hal.h>

#include <nuttx/arch.h>
#include <nuttx/irq.h>

#include <drivers/drv_pwm_output.h>
#include <drivers/drv_hrt.h>

#include "board_config.h"

/**
 * Timer configuration for ZynqMP R5
 * 
 * The ZynqMP R5 processor has access to various timers:
 * - Triple Timer Counter (TTC) - 3 timers per TTC, 4 TTC blocks
 * - System Watchdog Timer (SWDT)
 * - Generic Timer (part of ARM Cortex-R5)
 * 
 * For this configuration, we'll use:
 * - Timer 1 for HRT (High Resolution Timer)
 * - Timer 2 for PWM output
 */

__EXPORT const io_timers_t io_timers[MAX_IO_TIMERS] = {
	{
		.base = 0,           // TTC0 Timer 0 base address (to be defined)
		.clock_register = 0, // Clock control register
		.clock_bit = 0,      // Clock enable bit
		.clock_freq = 100000000, // 100MHz clock
		.vectorno = 0,       // IRQ vector number
		.first_channel_index = 0,
		.last_channel_index = 7,
		.handler = nullptr,
	}
};

__EXPORT const timer_io_channels_t timer_io_channels[MAX_TIMER_IO_CHANNELS] = {
	// PWM channels 0-7
	{
		.gpio_out = 0,      // GPIO configuration
		.gpio_in = 0,       // GPIO input configuration
		.timer_index = 0,   // Timer index
		.ccr_offset = 0,    // Capture/Compare register offset
		.masks = 0,         // Channel masks
		.timer = 0,         // Timer number
		.ccr_value = 0,     // CCR value
		.dshot_offset = 0,  // DShot offset
	},
	{
		.gpio_out = 0,
		.gpio_in = 0,
		.timer_index = 0,
		.ccr_offset = 0,
		.masks = 0,
		.timer = 0,
		.ccr_value = 0,
		.dshot_offset = 0,
	},
	{
		.gpio_out = 0,
		.gpio_in = 0,
		.timer_index = 0,
		.ccr_offset = 0,
		.masks = 0,
		.timer = 0,
		.ccr_value = 0,
		.dshot_offset = 0,
	},
	{
		.gpio_out = 0,
		.gpio_in = 0,
		.timer_index = 0,
		.ccr_offset = 0,
		.masks = 0,
		.timer = 0,
		.ccr_value = 0,
		.dshot_offset = 0,
	},
	{
		.gpio_out = 0,
		.gpio_in = 0,
		.timer_index = 0,
		.ccr_offset = 0,
		.masks = 0,
		.timer = 0,
		.ccr_value = 0,
		.dshot_offset = 0,
	},
	{
		.gpio_out = 0,
		.gpio_in = 0,
		.timer_index = 0,
		.ccr_offset = 0,
		.masks = 0,
		.timer = 0,
		.ccr_value = 0,
		.dshot_offset = 0,
	},
	{
		.gpio_out = 0,
		.gpio_in = 0,
		.timer_index = 0,
		.ccr_offset = 0,
		.masks = 0,
		.timer = 0,
		.ccr_value = 0,
		.dshot_offset = 0,
	},
	{
		.gpio_out = 0,
		.gpio_in = 0,
		.timer_index = 0,
		.ccr_offset = 0,
		.masks = 0,
		.timer = 0,
		.ccr_value = 0,
		.dshot_offset = 0,
	},
};

__EXPORT const struct dshot_config_t dshot_config = {
	.dshot_timers_count = 1,
	.dshot_timers = {
		{
			.timer_index = 0,
			.gpio_af = 0,
			.dma_base = 0,
			.channels_count = 8,
			.channels = {
				{
					.gpio = 0,
					.timer_channel = 0,
					.raw_gpio = 0,
					.generated_gpio = 0,
				},
				{
					.gpio = 0,
					.timer_channel = 1,
					.raw_gpio = 0,
					.generated_gpio = 0,
				},
				{
					.gpio = 0,
					.timer_channel = 2,
					.raw_gpio = 0,
					.generated_gpio = 0,
				},
				{
					.gpio = 0,
					.timer_channel = 3,
					.raw_gpio = 0,
					.generated_gpio = 0,
				},
				{
					.gpio = 0,
					.timer_channel = 4,
					.raw_gpio = 0,
					.generated_gpio = 0,
				},
				{
					.gpio = 0,
					.timer_channel = 5,
					.raw_gpio = 0,
					.generated_gpio = 0,
				},
				{
					.gpio = 0,
					.timer_channel = 6,
					.raw_gpio = 0,
					.generated_gpio = 0,
				},
				{
					.gpio = 0,
					.timer_channel = 7,
					.raw_gpio = 0,
					.generated_gpio = 0,
				},
			}
		}
	}
};