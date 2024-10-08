# This file exists to configure the behaviour of the Iyada across all versions, keymaps, etc.

# Microcontroller selection
	MCU = RP2040					# Selecting the Microcontroller used for the Iyada
	
# Bootloader selection
	BOOTLOADER = rp2040				# Selecting the appropriate bootloader for the above Microcontroller

# Default path
	DEFAULT_FOLDER = kiraibuilds/iyada/rev1		# Selecting the default subtype of Iyada to make if none are selected

# Build Options
	SPLIT_KEYBOARD = yes				# Confirming that this is a split keyboard
	SERIAL_DRIVER = vendor
	LTO_ENABLE = yes				# Link Time Optimization - This helps the firmware take up less space
	OS_DETECTION_ENABLE = yes			# Automatically change how much power the Iyada draws depending on the OS
	
# Layer options
	LAYER_MAP = yes					# Layer definitions file toggle
	
# Rotary encoder options
	ENCODER_ENABLE = yes		  		# Rotary encoder toggle
	ENCODER_MAP_ENABLE = yes			# Encoder map toggle
	EC12_LEFT = yes					# Low-profile Rotary toggles
	EC12_RIGHT = yes				# Select yes when using EC12 Rotary encoders and no when using EC11 Rotary encoders
	
# Per-key RGB lighting
	RGBLIGHT_ENABLE = yes				# Per-key LED toggle
	BACKLIGHT_ENABLE = no				# Backlight toggle
	SLEEP_LED_ENABLE = yes				# LEDs inactive when computer is sleeping
	
# OLED screens
	OLED_ENABLE = yes				# OLED display toggle
	OLED_DEFAULT_GRAPHICS = yes			# Allowing the user to choose whether to use the graphics that come with the Iyada, or to use their own
	
# Dual Cirque Pinnacle Trackpads
	POINTING_DEVICE_ENABLE = yes			# Cirque input toggle
	POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c	# Cirque input driver
