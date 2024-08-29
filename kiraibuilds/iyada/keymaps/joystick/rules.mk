# Build Options
COMBO_ENABLE = no								# Key combos
TAP_DANCE_ENABLE = no							# Tap Dance toggle
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
AUDIO_ENABLE = no 								# Audio output
UNICODE_ENABLE = no								# Unicode output
JOYSTICK_ENABLE = yes 							# Gamepad & Joystick output
JOYSTICK_DRIVER = digital					    # Gamepad & Joystick driver
SRC += layer_behaviours.c					    # Parsing the layer_behaviours.c file (RGB Light Layers, Layer sounds, Cirque Dual Joystick)
ENCODER_MAP_ENABLE = no 						# Encoder map toggle
  
POINTING_DEVICE_ENABLE = yes					# Mouse sensor input toggle
POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c	# Mouse sensor model
OLED_ENABLE = yes								# OLED display output toggle
BACKLIGHT_ENABLE = no							# Keyboard backlight
RGBLIGHT_ENABLE = yes							# Per-key LED toggle
