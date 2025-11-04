# Xilinx ZynqMP SoC R5 Processor Default Configuration
# This file contains the default build configuration for the ZynqMP R5 board

# Board configuration
set(BOARD_NAME "zynqmp-r5")
set(BOARD_DIR "${PX4_SOURCE_DIR}/boards/xilinx/zynqmp-r5")

# Toolchain configuration
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR ARM)

# Compiler settings
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)
set(CMAKE_OBJDUMP arm-none-eabi-objdump)
set(CMAKE_SIZE arm-none-eabi-size)

# Compiler flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mcpu=cortex-r5 -mfloat-abi=hard -mfpu=vfpv3-d16")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mthumb -mthumb-interwork")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ffunction-sections -fdata-sections")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fno-builtin -fno-common")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mcpu=cortex-r5 -mfloat-abi=hard -mfpu=vfpv3-d16")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mthumb -mthumb-interwork")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ffunction-sections -fdata-sections")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-builtin -fno-common")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -mcpu=cortex-r5 -mfloat-abi=hard -mfpu=vfpv3-d16")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -mthumb -mthumb-interwork")

# Linker flags
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mcpu=cortex-r5 -mfloat-abi=hard -mfpu=vfpv3-d16")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mthumb -mthumb-interwork")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--gc-sections")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--as-needed")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--strip-all")

# Board-specific defines
add_definitions(-DCONFIG_ARCH_BOARD_ZYNQMP_R5)
add_definitions(-DCONFIG_ARCH_CORTEXR5)
add_definitions(-DCONFIG_ARCH_FPU)
add_definitions(-DCONFIG_ARCH_HAVE_DPFPU)
add_definitions(-DCONFIG_ARCH_HAVE_SPFPU)

# Memory configuration
add_definitions(-DCONFIG_RAM_START=0x00000000)
add_definitions(-DCONFIG_RAM_SIZE=0x1000000)
add_definitions(-DCONFIG_FLASH_START=0x08000000)
add_definitions(-DCONFIG_FLASH_SIZE=0x1000000)

# System configuration
add_definitions(-DCONFIG_CLOCK_FREQUENCY=80000000)
add_definitions(-DCONFIG_UART0_BASE=0xFF000000)
add_definitions(-DCONFIG_UART0_BAUD=115200)
add_definitions(-DCONFIG_GPIO_BASE=0xFF010000)
add_definitions(-DCONFIG_TIMER_BASE=0xFF020000)
add_definitions(-DCONFIG_GIC_BASE=0xF9000000)

# Include directories
include_directories(${BOARD_DIR}/include)
include_directories(${BOARD_DIR}/drivers)

# Board-specific source files
set(BOARD_SRCS
    ${BOARD_DIR}/board.c
    ${BOARD_DIR}/board_init.c
    ${BOARD_DIR}/board_led.c
    ${BOARD_DIR}/board_uart.c
    ${BOARD_DIR}/board_timer.c
    ${BOARD_DIR}/board_gpio.c
)

# Build configuration
set(BUILD_TYPE "release" CACHE STRING "Build type")
set(DEBUG_LEVEL 0 CACHE STRING "Debug level")

# PX4 specific configuration
set(PX4_BOARD_NAME "zynqmp-r5")
set(PX4_BOARD_DIR "${BOARD_DIR}")

# Include PX4 board configuration
include(${PX4_SOURCE_DIR}/boards/common/px4/board.cmake)
