/****************************************************************************
 * boards/xilinx/zynqmpsoc_r5/nuttx-config/include/board.h
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

#ifndef __BOARDS_XILINX_ZYNQMPSOC_R5_NUTTX_CONFIG_INCLUDE_BOARD_H
#define __BOARDS_XILINX_ZYNQMPSOC_R5_NUTTX_CONFIG_INCLUDE_BOARD_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <stdbool.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Board Information */
#define BOARD_NAME                "ZynqMP SoC R5"
#define BOARD_REVISION            1

/* Clocking *****************************************************************/

/* The ZynqMP R5 processor can run at various frequencies.
 * For this configuration, we assume a 600MHz R5 clock
 */

#define BOARD_XTAL_FREQUENCY      33333333  /* 33.333 MHz crystal */
#define BOARD_CPU_FREQUENCY       600000000 /* 600 MHz CPU clock */
#define BOARD_SYSTICK_FREQUENCY   BOARD_CPU_FREQUENCY

/* Memory Configuration *****************************************************/

/* TCM Memory Layout */
#define BOARD_ATCM_BASE           0x00000000
#define BOARD_ATCM_SIZE           (128 * 1024)  /* 128KB */

#define BOARD_BTCM_BASE           0x00020000
#define BOARD_BTCM_SIZE           (128 * 1024)  /* 128KB */

/* OCM Memory Layout */
#define BOARD_OCM_BASE            0xFFFC0000
#define BOARD_OCM_SIZE            (256 * 1024)  /* 256KB */

/* LED definitions **********************************************************/

/* The ZynqMP R5 board may have LEDs connected to GPIO pins.
 * These definitions are board-specific and may need to be adjusted
 * based on the actual hardware implementation.
 */

#define BOARD_NLEDS               3

/* GPIO definitions *********************************************************/

/* UART definitions *********************************************************/

/* The ZynqMP R5 has access to multiple UART controllers.
 * UART0 is typically used as the console.
 */

#define BOARD_UART0_BASE          0xFF000000
#define BOARD_UART1_BASE          0xFF010000

/* SPI definitions **********************************************************/

/* The ZynqMP R5 has access to SPI controllers for peripheral communication */

#define BOARD_SPI0_BASE           0xFF040000
#define BOARD_SPI1_BASE           0xFF050000

/* I2C definitions **********************************************************/

/* The ZynqMP R5 has access to I2C controllers for sensor communication */

#define BOARD_I2C0_BASE           0xFF020000
#define BOARD_I2C1_BASE           0xFF030000

/* Timer definitions ********************************************************/

/* The ZynqMP R5 has access to Triple Timer Counters (TTC) */

#define BOARD_TTC0_BASE           0xFF110000
#define BOARD_TTC1_BASE           0xFF120000
#define BOARD_TTC2_BASE           0xFF130000
#define BOARD_TTC3_BASE           0xFF140000

/* Interrupt definitions ****************************************************/

/* Define interrupt numbers for various peripherals */

#define BOARD_UART0_IRQ           53
#define BOARD_UART1_IRQ           54
#define BOARD_SPI0_IRQ            51
#define BOARD_SPI1_IRQ            52
#define BOARD_I2C0_IRQ            49
#define BOARD_I2C1_IRQ            50
#define BOARD_TTC0_IRQ            68
#define BOARD_TTC1_IRQ            69
#define BOARD_TTC2_IRQ            70
#define BOARD_TTC3_IRQ            71

/* Button definitions *******************************************************/

/* The ZynqMP R5 board may have buttons connected to GPIO pins */

#define BOARD_NBUTTONS            0

/* ADC definitions **********************************************************/

/* The ZynqMP R5 has access to XADC (Xilinx ADC) */

#define BOARD_XADC_BASE           0xFFA50000

/****************************************************************************
 * Public Types
 ****************************************************************************/

#ifndef __ASSEMBLY__

/****************************************************************************
 * Public Data
 ****************************************************************************/

#undef EXTERN
#if defined(__cplusplus)
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Name: board_autoled_on
 *
 * Description:
 *   Turn on the "logical" LED state
 *
 ****************************************************************************/

#ifdef CONFIG_ARCH_LEDS
void board_autoled_on(int led);
#endif

/****************************************************************************
 * Name: board_autoled_off
 *
 * Description:
 *   Turn off the "logical" LED state
 *
 ****************************************************************************/

#ifdef CONFIG_ARCH_LEDS
void board_autoled_off(int led);
#endif

/****************************************************************************
 * Name: board_userled_initialize
 *
 * Description:
 *   Initialize user LEDs
 *
 ****************************************************************************/

#ifdef CONFIG_USERLED
void board_userled_initialize(void);
#endif

/****************************************************************************
 * Name: board_userled
 *
 * Description:
 *   Control user LED
 *
 ****************************************************************************/

#ifdef CONFIG_USERLED
void board_userled(int led, bool ledon);
#endif

/****************************************************************************
 * Name: board_userled_all
 *
 * Description:
 *   Control all user LEDs
 *
 ****************************************************************************/

#ifdef CONFIG_USERLED
void board_userled_all(uint8_t ledset);
#endif

#undef EXTERN
#if defined(__cplusplus)
}
#endif

#endif /* __ASSEMBLY__ */
#endif /* __BOARDS_XILINX_ZYNQMPSOC_R5_NUTTX_CONFIG_INCLUDE_BOARD_H */