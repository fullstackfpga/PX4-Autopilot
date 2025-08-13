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
 * @file board_config.h
 *
 * ZynqMP SoC R5 internal definitions
 */

#pragma once

/****************************************************************************************************
 * Included Files
 ****************************************************************************************************/

#include <px4_platform/board_ctrl.h>
#include <px4_platform_common/px4_config.h>
#include <nuttx/compiler.h>
#include <stdint.h>

/****************************************************************************************************
 * Definitions
 ****************************************************************************************************/

/* Configuration ************************************************************************************/

#define BOARD_HAS_NO_RESET              1
#define BOARD_HAS_NO_BOOTLOADER         1

/* LEDs */
#define BOARD_HAS_CONTROL_STATUS_LEDS   0

/* ADC channels */
#define BOARD_HAS_NO_ADC                1

/* PWM */
#define DIRECT_PWM_OUTPUT_CHANNELS      8
#define BOARD_HAS_PWM                   DIRECT_PWM_OUTPUT_CHANNELS

/* Serial ports */
#define BOARD_SERIAL_GPS1               "/dev/ttyS0"
#define BOARD_SERIAL_GPS2               "/dev/ttyS1"
#define BOARD_SERIAL_TEL1               "/dev/ttyS2"
#define BOARD_SERIAL_TEL2               "/dev/ttyS3"
#define BOARD_SERIAL_TEL3               "/dev/ttyS4"
#define BOARD_SERIAL_RC                 "/dev/ttyS5"

/* RC Serial port */
#define RC_SERIAL_PORT                  "/dev/ttyS5"

/* High-resolution timer */
#define HRT_TIMER                       1
#define HRT_TIMER_CHANNEL               1

/* Board capabilities */
#define BOARD_HAS_ETHERNET              1
#define BOARD_HAS_NO_UUID               1
#define BOARD_HAS_NO_EEPROM             1

/* Memory configuration */
#define BOARD_FLASH_SIZE                (2 * 1024 * 1024)  // 2MB Flash
#define BOARD_RAM_SIZE                  (256 * 1024)       // 256KB RAM

/* Board specific GPIO initialization */
#define PX4_GPIO_INIT_LIST              { }

/* Board DMA configuration */
#define BOARD_DMA_ALLOC_POOL_SIZE       2048

/* Board has no reset capability */
#define BOARD_HAS_ON_RESET              0

/* Number of I/O timers */
#define BOARD_NUM_IO_TIMERS             1

__BEGIN_DECLS

/****************************************************************************************************
 * Public Types
 ****************************************************************************************************/

/****************************************************************************************************
 * Public data
 ****************************************************************************************************/

#ifndef __ASSEMBLY__

/****************************************************************************************************
 * Public Functions
 ****************************************************************************************************/

/**
 * @brief Initialize board peripherals
 */
extern void board_peripheral_reset(int ms);

#include <px4_platform_common/board_common.h>

#endif /* __ASSEMBLY__ */

__END_DECLS