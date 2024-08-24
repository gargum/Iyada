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

POINTING_DEVICE_ENABLE = yes					# Mouse sensor input toggle
POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c	# Mouse sensor model

ENCODER_ENABLE = yes		  					# Rotary encoder toggle

HAPTIC_ENABLE = yes								# Haptic feedback toggle
HAPTIC_DRIVER = drv2605l                        # Haptic feedback driver
