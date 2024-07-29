/* Copyright 2024 Gareth Gummow <ggummow@uwaterloo.ca> (@gargum)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define SERIAL_USART_DRIVER SIOD0
// #define SERIAL_USART_FULL_DUPLEX
// #define SERIAL_USART_TX_PIN GP0
// #define SERIAL_USART_RX_PIN GP25
#define UART_TX_PIN GP0
#define UART_RX_PIN GP25

#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP2
#define I2C1_SCL_PIN GP3

#define SPI_DRIVER SPID1
#define SPI_SCK_PIN GP14
#define SPI_MISO_PIN GP12
#define SPI_MOSI_PIN GP15

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behaviour
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U // Timeout window in ms in which the double tap can occur.

#define DEBOUNCE 5
#define DEBOUNCE_TYPE sym_defer_g

// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS

#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

#define USB_SUSPEND_WAKEUP_DELAY 200

#define TAPPING_TERM 185
#define TAPPING_TOGGLE 1

#define SPLIT_LAYOUT
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2000
#define SPLIT_USB_TIMEOUT_POLL 10
#define SPLIT_ACTIVITY_ENABLE
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_OLED_ENABLE
#define SPLIT_HAPTIC_ENABLE
#define SPLIT_POINTING_ENABLE
// #define POINTING_DEVICE_RIGHT
// #define POINTING_DEVICE_LEFT
#define POINTING_DEVICE_COMBINED
//  #define POINTING_DEVICE_ROTATION_270_RIGHT
#define CIRQUE_PINNACLE_CIRCULAR_SCROLL_ENABLE
#define CIRQUE_PINNACLE_DIAMETER_MM 40
#define CIRQUE_PINNACLE_CURVED_OVERLAY
#define CIRQUE_PINNACLE_TAP_ENABLE
#define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE
// #define CIRQUE_PINNACLE_SKIP_SENSOR_CHECK
#define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_ABSOLUTE_MODE
#define CIRQUE_PINNACLE_ATTENUATION EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_2X

#define WS2812_DI_PIN GP17
#define RGBLIGHT_LED_COUNT 30
#define RGBLED_SPLIT { 15, 15 }
#define RGBLIGHT_EFFECT_BREATHING
// #define RGBLIGHT_EFFECT_RAINBOW_MOOD
// #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
// #define RGBLIGHT_EFFECT_SNAKE
// #define RGBLIGHT_EFFECT_KNIGHT
// #define RGBLIGHT_EFFECT_CHRISTMAS
// #define RGBLIGHT_EFFECT_STATIC_GRADIENT
// #define RGBLIGHT_EFFECT_RGB_TEST
// #define RGBLIGHT_EFFECT_ALTERNATING
// #define RGBLIGHT_EFFECT_TWINKLE
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_LIMIT_VAL 175
#define RGBLIGHT_DEFAULT_VAL 150
#define RGBLIGHT_DEFAULT_HUE 148
#define RGBLIGHT_DEFAULT_SAT 225
#define RGBLIGHT_DEFAULT_SPD 1
// #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_BREATHING
#define RGBLIGHT_EFFECT_BREATHE_MAX 175
#define RGBLIGHT_LAYERS
#define SPLIT_LED_STATE_ENABLE

#undef RGBLIGHT_EFFECT_BREATHING 
#undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
#undef RGBLIGHT_EFFECT_SNAKE
#undef RGBLIGHT_EFFECT_KNIGHT
#undef RGBLIGHT_EFFECT_CHRISTMAS
#undef RGBLIGHT_EFFECT_STATIC_GRADIENT
#undef RGBLIGHT_EFFECT_RGB_TEST
#undef RGBLIGHT_EFFECT_ALTERNATING
#undef RGBLIGHT_EFFECT_TWINKLE

// #define HAPTIC_ENABLE_PIN GP10
// #define SOLENOID_PIN GP10
#define DRV2605L_FB_ERM_LRA 0
#define DRV2605L_FB_BRAKEFACTOR 3
#define DRV2605L_FB_LOOPGAIN 1
#define DRV2605L_RATED_VOLTAGE 3
#define DRV2605L_V_PEAK 5
#define DRV2605L_GREETING 92
#define DRV2605L_DEFAULT_MODE 1
#define NO_HAPTIC_MOD
#define NO_HAPTIC_ALPHA
#define NO_HAPTIC_PUNCTUATION
#define NO_HAPTIC_LOCKKEYS
#define NO_HAPTIC_NAV
#define NO_HAPTIC_NUMERIC

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOThttps://docs.qmk.fm/platformdev_rp2040#generic-rp2040-board
