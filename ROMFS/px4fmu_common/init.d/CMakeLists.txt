############################################################################
#
#   Copyright (c) 2018 PX4 Development Team. All rights reserved.
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

add_subdirectory(airframes)

px4_add_romfs_files(

	rc.autostart_ext

	rcS
	rc.sensors
	rc.vehicle_setup

	# TODO
	rc.balloon_apps
	rc.balloon_defaults
	rc.sysinit
)

if(CONFIG_MODULES_AIRSHIP_ATT_CONTROL)
	px4_add_romfs_files(
		rc.airship_apps
		rc.airship_defaults
	)
endif()

if(CONFIG_MODULES_FW_RATE_CONTROL)
	px4_add_romfs_files(
		rc.fw_apps
		rc.fw_defaults
	)
endif()

if(CONFIG_MODULES_MC_RATE_CONTROL)
	px4_add_romfs_files(
		rc.heli_defaults
		rc.mc_apps
		rc.mc_defaults
	)
endif()

if(CONFIG_MODULES_ROVER_DIFFERENTIAL)
	px4_add_romfs_files(
		rc.rover_differential_apps
		rc.rover_differential_defaults
	)
endif()

if(CONFIG_MODULES_ROVER_ACKERMANN)
	px4_add_romfs_files(
		rc.rover_ackermann_apps
		rc.rover_ackermann_defaults
	)
endif()

if(CONFIG_MODULES_SPACECRAFT)
	px4_add_romfs_files(
		rc.sc_apps
		rc.sc_defaults
	)
endif()

if(CONFIG_MODULES_ROVER_MECANUM)
	px4_add_romfs_files(
		rc.rover_mecanum_apps
		rc.rover_mecanum_defaults
	)
endif()

if(CONFIG_MODULES_UUV_ATT_CONTROL)
	px4_add_romfs_files(
		rc.uuv_apps
		rc.uuv_defaults
	)
endif()

if(CONFIG_MODULES_VTOL_ATT_CONTROL)
	px4_add_romfs_files(
		rc.vtol_apps
		rc.vtol_defaults
	)
endif()


if(CONFIG_MODULES_LOGGER)
	px4_add_romfs_files(
		rc.logging
	)
endif()

if(CONFIG_MODULES_TEMPERATURE_COMPENSATION)
	px4_add_romfs_files(
		rc.thermal_cal
	)
endif()
