# Xilinx ZynqMP SoC R5 Processor Board Configuration
# This file defines the board-specific configuration for the ZynqMP R5 processor

# Board name
BOARD_NAME := zynqmp-r5

# Processor architecture
ARCH := cortex-r5

# Toolchain
TOOLCHAIN := arm-none-eabi

# Compiler flags
CFLAGS += -mcpu=cortex-r5 -mfloat-abi=hard -mfpu=vfpv3-d16
CFLAGS += -mthumb -mthumb-interwork
CFLAGS += -ffunction-sections -fdata-sections
CFLAGS += -fno-builtin -fno-common
CFLAGS += -Wall -Wextra -Werror=implicit-function-declaration
CFLAGS += -Wno-unused-parameter -Wno-unused-variable
CFLAGS += -Wno-missing-field-initializers
CFLAGS += -Wno-unused-but-set-variable
CFLAGS += -Wno-unused-function
CFLAGS += -Wno-unused-label
CFLAGS += -Wno-unused-value
CFLAGS += -Wno-unused-parameter
CFLAGS += -Wno-unused-variable
CFLAGS += -Wno-unused-but-set-variable
CFLAGS += -Wno-unused-function
CFLAGS += -Wno-unused-label
CFLAGS += -Wno-unused-value

# Linker flags
LDFLAGS += -mcpu=cortex-r5 -mfloat-abi=hard -mfpu=vfpv3-d16
LDFLAGS += -mthumb -mthumb-interwork
LDFLAGS += -Wl,--gc-sections
LDFLAGS += -Wl,--as-needed
LDFLAGS += -Wl,--strip-all

# Board-specific defines
DEFINES += CONFIG_ARCH_BOARD_ZYNQMP_R5
DEFINES += CONFIG_ARCH_CORTEXR5
DEFINES += CONFIG_ARCH_FPU
DEFINES += CONFIG_ARCH_HAVE_DPFPU
DEFINES += CONFIG_ARCH_HAVE_SPFPU

# Memory layout
DEFINES += CONFIG_RAM_START=0x00000000
DEFINES += CONFIG_RAM_SIZE=0x1000000
DEFINES += CONFIG_FLASH_START=0x08000000
DEFINES += CONFIG_FLASH_SIZE=0x1000000

# System clock
DEFINES += CONFIG_CLOCK_FREQUENCY=80000000

# Serial console
DEFINES += CONFIG_UART0_BASE=0xFF000000
DEFINES += CONFIG_UART0_BAUD=115200

# GPIO configuration
DEFINES += CONFIG_GPIO_BASE=0xFF010000

# Timer configuration
DEFINES += CONFIG_TIMER_BASE=0xFF020000

# Interrupt controller
DEFINES += CONFIG_GIC_BASE=0xF9000000

# Board-specific source files
BOARD_SRCS := \
	board.c \
	board_init.c \
	board_led.c \
	board_uart.c \
	board_timer.c \
	board_gpio.c

# Include paths
INCLUDE_DIRS += $(BOARD_DIR)/include
INCLUDE_DIRS += $(BOARD_DIR)/drivers

# Board-specific libraries
BOARD_LIBS :=

# Build configuration
BUILD_TYPE := release
DEBUG_LEVEL := 0
