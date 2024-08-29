# Build Options
AUTOCORRECT_ENABLE = yes 						# Autocorrect toggle
CAPS_WORD_ENABLE = yes							# Caps word toggle
AUTO_SHIFT_ENABLE = yes							# Auto shift toggle
DYNAMIC_MACRO_ENABLE = no						# Dynamic macro toggle
DYNAMIC_TAPPING_TERM_ENABLE = no				# Dynamic tapping term toggle
WPM_ENABLE = no									# Word Per Minute measurement toggle

STENO_ENABLE = yes								# Stenotype output
MIDI_ENABLE = no								# MIDI output
AUDIO_ENABLE = yes 								# Audio output
UNICODE_ENABLE = no								# Unicode output

ifdef POINTING_DEVICE_ENABLE
	POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c	# Mouse sensor model
endif

ifdef JOYSTICK_ENABLE
	JOYSTICK_DRIVER = digital					    # Gamepad & Joystick driver
endif

ifdef RGBLIGHT_ENABLE
	SLEEP_LED_ENABLE = yes							# LEDs inactive when computer is sleeping
	SRC += layer_behaviours.c					    # Parsing the layer_behaviours.c file (RGB Light Layers, Layer sounds, Cirque Dual Joystick)
endif					

ifdef HAPTIC_ENABLE
	HAPTIC_DRIVER = drv2605l                        # Haptic feedback driver
endif
