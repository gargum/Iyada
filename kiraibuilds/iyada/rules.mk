#
# This file exists to configure the behaviour of the Iyada across all versions, keymaps, etc.
#

# Microcontroller selection
	MCU = RP2040									# Selecting the Microcontroller used for the Iyada
	
# Bootloader selection
	BOOTLOADER = rp2040								# Selecting the appropriate bootloader for the above Microcontroller

# Default path
	DEFAULT_FOLDER = kiraibuilds/iyada/rev1			# Selecting the default subtype of Iyada to make if none are selected

# Build Options
	SPLIT_KEYBOARD = yes							# Confirming that this is a split keyboard
	SERIAL_DRIVER = vendor
	LTO_ENABLE = yes								# Link Time Optimization - This helps the firmware take up less space
	
# Tap Dance
	TAP_DANCE_ENABLE = yes							# Tap Dance toggle
	
# Combos
	COMBO_ENABLE = yes								# Combo toggle
	
# Cirque dual pointing functionality
	POINTING_DEVICE_ENABLE = yes					# Cirque Pinnacle toggle
	
# Cirque dual analogue functionality
	JOYSTICK_ENABLE = yes							# Cirque Pinnacle Gamepad toggle
	
# Rotary encoder options
	ENCODER_ENABLE = yes		  					# Rotary encoder toggle
	EC12_LEFT = yes									# Low-profile Rotary toggles
	EC12_RIGHT = yes								# Select yes when using EC12 Rotary encoders and no when using EC11 Rotary encoders
	
# Per-key RGB lighting
	RGBLIGHT_ENABLE = yes							# Per-key LED toggle
	
# OLED screens
	OLED_ENABLE = yes								# OLED 32x128 display toggle
	
# Haptic feedbacK
	HAPTIC_ENABLE = yes								# Haptic feedback toggle
