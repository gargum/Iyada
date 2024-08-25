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

// for split keyboard initialization
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
    #define SPLIT_LED_STATE_ENABLE
    #define SPLIT_WATCHDOG_ENABLE
    #define SPLIT_WATCHDOG_TIMEOUT 3000

// Pointer (Cirque Pinnacle) initialization settings
#ifdef POINTING_DEVICE_ENABLE
    #define MOUSE_EXTENDED_REPORT
    #define POINTING_DEVICE_COMBINED
    #define POINTING_DEVICE_TASK_THROTTLE_MS 10
    #define CIRQUE_PINNACLE_DIAMETER_MM 40
    #define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_ABSOLUTE_MODE
    #define CIRQUE_PINNACLE_ATTENUATION EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_4X
    #define CIRQUE_PINNACLE_TIMEOUT 20
#endif

// RGB initialization settings
#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_LED_COUNT 30
    #define RGBLED_SPLIT { 15, 15 }
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_HUE_STEP 8
    #define RGBLIGHT_SAT_STEP 8
    #define RGBLIGHT_VAL_STEP 8
    #define RGBLIGHT_LIMIT_VAL 135
    #define RGBLIGHT_DEFAULT_VAL 135
    #define RGBLIGHT_DEFAULT_HUE 148
    #define RGBLIGHT_DEFAULT_SAT 225
    #define RGBLIGHT_DEFAULT_SPD 1
    #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_BREATHING
    #define RGBLIGHT_EFFECT_BREATHE_MAX 135
#endif

// Haptic feedback initialization settings
#ifdef HAPTIC_ENABLE
    #define DRV2605L_FB_ERM_LRA 0
    #define DRV2605L_FB_BRAKEFACTOR 6
    #define DRV2605L_FB_LOOPGAIN 3
    #define DRV2605L_RATED_VOLTAGE 2.7
    #define DRV2605L_V_PEAK 5.1
#endif

// Audio settings - Sound settings
#ifdef AUDIO_ENABLE
    #define AUDIO_CLICKY
    #define AUDIO_CLICKY_FREQ_DEFAULT 250
    #define AUDIO_CLICKY_FREQ_MIN 100
    #define AUDIO_CLICKY_FREQ_MAX 400
#endif

// Joystick settings - Axis definitions
#ifdef JOYSTICK_ENABLE
    #define JOYSTICK_AXIS_COUNT 4
#endif
