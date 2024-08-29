/*
* This file is used to configure the default behaviours of the Iyada when given features like RGB and Audio are enabled.
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
    #define RGBLIGHT_LIMIT_VAL 165
    #define RGBLIGHT_DEFAULT_VAL 130
    #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_BREATHING
    #define RGBLIGHT_DEFAULT_SPD 3
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
    #define JOYSTICK_BUTTON_COUNT 17
#endif
