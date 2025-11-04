#pragma once

#include <stdint.h>

// Board-wide definitions for Xilinx ZynqMP R5

// UART
#define ZYNQMP_UART0_BASE   0xFF000000U
#define ZYNQMP_UART0_BAUD   115200U

// GPIO
#define ZYNQMP_GPIO_BASE    0xFF010000U

// Timer
#define ZYNQMP_TIMER_BASE   0xFF020000U

// Interrupt Controller
#define ZYNQMP_GIC_BASE     0xF9000000U

// RAM/Flash
#define ZYNQMP_RAM_START    0x00000000U
#define ZYNQMP_RAM_SIZE     0x1000000U
#define ZYNQMP_FLASH_START  0x08000000U
#define ZYNQMP_FLASH_SIZE   0x1000000U

// System clock
#define ZYNQMP_CLOCK_FREQUENCY 80000000U

// Utility macros (add more as needed)
#define ZYNQMP_UNUSED(x) ((void)(x))
