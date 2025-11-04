# PX4 Board Support: Xilinx ZynqMP R5

This directory contains PX4 board support for the Xilinx ZynqMP R5 processor.

## Architecture
- ARM Cortex-R5 (real-time core)
- Intended for use with the ZynqMP SoC family

## Toolchain
- Uses `arm-linux-gnueabihf` toolchain
- Platform: POSIX/Linux

## Files
- `default.px4board`: PX4 board configuration
- `firmware.prototype`: Board metadata for firmware
- `board.mk`, `default.cmake`, `board.c`, `board_init.c`: Board-specific build and initialization

## Bring-up Notes
- Ensure the toolchain is installed and available in your PATH
- Board-specific drivers and initialization should be added to `src/` and `include/` as needed
- This is a starting point for porting PX4 to the ZynqMP R5
