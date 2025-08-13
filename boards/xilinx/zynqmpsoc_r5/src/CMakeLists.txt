############################################################################
#
#   Copyright (c) 2024 PX4 Development Team. All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in
#    the documentation and/or other materials provided with the
#    distribution.
# 3. Neither the name PX4 nor the names of its contributors may be
#    used to endorse or promote products derived from this software
#    without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
# COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
# OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
# AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
############################################################################

px4_add_board(
	PLATFORM nuttx
	VENDOR xilinx
	MODEL zynqmpsoc_r5
	LABEL default
	TOOLCHAIN arm-none-eabi
	ARCHITECTURE cortex-r5
	ROMFSROOT px4fmu_common
	CONSTRAINED_FLASH
	CONSTRAINED_MEMORY
	LINKER_PREFIX armv7-r
	TESTING

	SERIAL_PORTS
		GPS1:/dev/ttyS0
		GPS2:/dev/ttyS1
		TEL1:/dev/ttyS2
		TEL2:/dev/ttyS3
		TEL3:/dev/ttyS4
		RC:/dev/ttyS5

	DRIVERS
		barometer/ms5611
		batt_smbus
		camera_trigger
		differential_pressure
		distance_sensor
		dshot
		gps
		iridiumsbd
		magnetometer
		optical_flow
		osd
		pwm_out
		px4io
		rc_input
		roboclaw
		safety_button
		telemetry
		tone_alarm
		uavcan

	MODULES
		airspeed_selector
		attitude_estimator_q
		battery_status
		camera_feedback
		commander
		control_allocator
		dataman
		ekf2
		events
		flight_mode_manager
		gimbal
		gyro_calibration
		land_detector
		landing_target_estimator
		load_mon
		logger
		mag_bias_estimator
		manual_control
		mavlink
		mc_att_control
		mc_autotune_attitude_control
		mc_hover_thrust_estimator
		mc_pos_control
		mc_rate_control
		navigator
		rc_update
		sensors
		temperature_compensation
		vtol_att_control

	SYSTEMCMDS
		actuator_test
		bsondump
		dmesg
		hardfault_log
		i2cdetect
		led_control
		mft
		motor_ramp
		motor_test
		mtd
		nshterm
		param
		perf
		reboot
		reflect
		sd_bench
		shutdown
		system_time
		top
		topic_listener
		tune_control
		uorb
		usb_connected
		ver
		work_queue
)

target_sources(px4 PRIVATE
	init.c
	timer_config.cpp
)

target_include_directories(px4 PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}
)