# Microcontroller selection
MCU = RP2040

# Bootloader selection
BOOTLOADER = rp2040

# Build Options
SPLIT_KEYBOARD = yes							# Confirming that this is a split keyboard

SERIAL_DRIVER = vendor
LTO_ENABLE = yes								# Link Time Optimisation
SLEEP_LED_ENABLE = yes							# LEDs inactive when computer is sleeping

OS_DETECTION_ENABLE = no						# Operating System detection toggle

COMBO_ENABLE = yes								# Key combos
TAP_DANCE_ENABLE = yes							# Tap Dance toggle
LEADER_ENABLE = no								# Leader key toggle
AUTOCORRECT_ENABLE = no 						# Autocorrect toggle
CAPS_WORD_ENABLE = no							# Caps word toggle
AUTO_SHIFT_ENABLE = no							# Auto shift toggle
DYNAMIC_MACRO_ENABLE = no						# Dynamic macro toggle
KEY_LOCK_ENABLE = no							# Key lock toggle
DYNAMIC_TAPPING_TERM_ENABLE = no				# Dynamic tapping term toggle
WPM_ENABLE = no									# Word Per Minute measurement toggle

STENO_ENABLE = no								# Stenotype output
MIDI_ENABLE = no								# MIDI output
AUDIO_ENABLE = yes 								# Audio output
UNICODE_ENABLE = no								# Unicode output
JOYSTICK_ENABLE = no 							# Gamepad & Joystick output
JOYSTICK_DRIVER = digital					    # Gamepad & Joystick driver
  
POINTING_DEVICE_ENABLE = yes					# Mouse sensor input toggle
POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c	# Mouse sensor model
OLED_ENABLE = yes								# OLED display output toggle
BACKLIGHT_ENABLE = no							# Keyboard backlight
RGBLIGHT_ENABLE = yes							# Per-key LED toggle
ENCODER_ENABLE = yes		  					# Rotary encoder toggle
HAPTIC_ENABLE = yes								# Haptic feedback toggle
HAPTIC_DRIVER = drv2605l						# Haptic feedback module model
