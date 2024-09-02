#include QMK_KEYBOARD_H
#include "keyboard.h"

#if __has_include( "layers.h" ) && LAYER_MAP == yes
    #include "layers.h"
#endif

#if JOYSTICK_ENABLE == yes
    #include "joystick.h"
#endif

#if AUDIO_ENABLE == yes
    #include "song_list.h"
#endif

#ifdef JOYSTICK_ENABLE
// Joysticks - Enumerating 4 Joystick axes: Left X, Left Y, Right X, and Right Y.
joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
    JOYSTICK_AXIS_VIRTUAL, // 0 - Left Stick, X
    JOYSTICK_AXIS_VIRTUAL, // 1 - Left Stick, Y
    JOYSTICK_AXIS_VIRTUAL, // 2 - Right Stick, X
    JOYSTICK_AXIS_VIRTUAL  // 3 - Right Stick, Y
};
//Joysticks - Creating a bool that will be set to true when a Joystick layer is active
bool JOYSTICK_ON = false;
// Setting the Cirque Joystick speed multiplier
uint8_t JOYSTICK_SPEED = 1.75;
#endif

//Audio - Parsing songs already available in QMK itself into their own variables
#ifdef AUDIO_ENABLE
float qwe_song[][2] = SONG(TERMINAL_SOUND);
float sym_song[][2] = SONG(UNICODE_WINDOWS);
float mou_song[][2] = SONG(UNICODE_LINUX);
float gam_song[][2] = SONG(AUDIO_ON_SOUND);
float ste_song[][2] = SONG(QWERTY_SOUND);
#endif

//Layers - Detecting the current active layer, then responding accordingly
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    #ifdef _SYMBOL
        case _SYMBOL:
        #ifdef RGBLIGHT_ENABLE
            rgblight_sethsv(125, 255, 160); /* RGB - TEAL */
        #endif
        #ifdef AUDIO_ENABLE
            PLAY_SONG(sym_song);            /* Layer Song - Play */
        #endif
        #ifdef JOYSTICK_ENABLE
            JOYSTICK_ON = false;            /* Cirque Joystick - False */
        #endif
            break;
    #endif
    #ifdef _SYM
        case _SYM:
        #ifdef RGBLIGHT_ENABLE
            rgblight_sethsv(125, 255, 160); /* RGB - TEAL */
        #endif
        #ifdef AUDIO_ENABLE
            PLAY_SONG(sym_song);            /* Layer Song - Play */
        #endif
        #ifdef JOYSTICK_ENABLE
            JOYSTICK_ON = false;            /* Cirque Joystick - False */
        #endif
            break;
    #endif
    #ifdef _LOWER
        case _LOWER:
        #ifdef RGBLIGHT_ENABLE
            rgblight_sethsv(125, 255, 160); /* RGB - TEAL */
        #endif
        #ifdef AUDIO_ENABLE
            PLAY_SONG(sym_song);            /* Layer Song - Play */
        #endif
        #ifdef JOYSTICK_ENABLE
            JOYSTICK_ON = false;            /* Cirque Joystick - False */)
        #endif
            break;
    #endif
    #ifdef _MOUSE
        case _MOUSE:
        #ifdef RGBLIGHT_ENABLE
            rgblight_sethsv(183, 255, 255); /* RGB - PURPLE */ 
        #endif
        #ifdef AUDIO_ENABLE
            PLAY_SONG(mou_song);            /* Layer Song - Play */
        #endif
        #ifdef JOYSTICK_ENABLE
            JOYSTICK_ON = false;            /* Cirque Joystick - False */
        #endif
            break;
    #endif
    #ifdef _MOU
        case _MOU:
        #ifdef RGBLIGHT_ENABLE
            rgblight_sethsv(183, 255, 255); /* RGB - PURPLE */ 
        #endif
        #ifdef AUDIO_ENABLE
            PLAY_SONG(mou_song);            /* Layer Song - Play */
        #endif
        #ifdef JOYSTICK_ENABLE
            JOYSTICK_ON = false;            /* Cirque Joystick - False */
        #endif
            break;
    #endif
    #ifdef _RAISE
        case _RAISE:
        #ifdef RGBLIGHT_ENABLE
            rgblight_sethsv(183, 255, 255); /* RGB - PURPLE */ 
        #endif
        #ifdef AUDIO_ENABLE
            PLAY_SONG(mou_song);            /* Layer Song - Play */
        #endif
        #ifdef JOYSTICK_ENABLE
            JOYSTICK_ON = false;            /* Cirque Joystick - False */
        #endif
            break;
    #endif
    #ifdef _GAMES
        case _GAMES:
        #ifdef RGBLIGHT_ENABLE
            rgblight_sethsv(160, 255, 255); /* RGB - BLUE */
        #endif
        #ifdef AUDIO_ENABLE
            PLAY_SONG(gam_song);            /* Layer Song - Play */
        #endif
        #ifdef JOYSTICK_ENABLE
            JOYSTICK_ON = true;             /* Cirque Joystick - True */
        #endif
            break;
    #endif
    #ifdef _GAM
        case _GAM:
        #ifdef RGBLIGHT_ENABLE
            rgblight_sethsv(160, 255, 255); /* RGB - BLUE */
        #endif
        #ifdef AUDIO_ENABLE
            PLAY_SONG(gam_song);            /* Layer Song - Play */
        #endif
        #ifdef JOYSTICK_ENABLE
            JOYSTICK_ON = true;             /* Cirque Joystick - True */
        #endif
            break;
    #endif
    #ifdef _ADJUST
        case _ADJUST:
        #ifdef RGBLIGHT_ENABLE
            rgblight_sethsv(160, 255, 255); /* RGB - BLUE */
        #endif
        #ifdef AUDIO_ENABLE
            PLAY_SONG(gam_song);            /* Layer Song - Play */
        #endif
        #ifdef JOYSTICK_ENABLE
            JOYSTICK_ON = false;            /* Cirque Joystick - False */
        #endif
            break;
    #endif
    #ifdef _STENO
        case _STENO:
        #ifdef RGBLIGHT_ENABLE
            rgblight_sethsv(85, 255, 255);  /* RGB - GREEN */
        #endif
        #ifdef AUDIO_ENABLE
            PLAY_SONG(ste_song);            /* Layer Song - Play */
        #endif
        #ifdef JOYSTICK_ENABLE
            JOYSTICK_ON = false;            /* Cirque Joystick - False */
        #endif
            break;
    #endif
    #ifdef _STE
        case _STE:
        #ifdef RGBLIGHT_ENABLE
            rgblight_sethsv(85, 255, 255);  /* RGB - GREEN */
        #endif
        #ifdef AUDIO_ENABLE
            PLAY_SONG(ste_song);            /* Layer Song - Play */
        #endif
        #ifdef JOYSTICK_ENABLE
            JOYSTICK_ON = false;            /* Cirque Joystick - False */
        #endif
            break;
    #endif
    #ifdef _PLOVER
        case _PLOVER:
        #ifdef RGBLIGHT_ENABLE
            rgblight_sethsv(85, 255, 255);  /* RGB - GREEN */
        #endif
        #ifdef AUDIO_ENABLE
            PLAY_SONG(ste_song);            /* Layer Song - Play */
        #endif
        #ifdef JOYSTICK_ENABLE
            JOYSTICK_ON = false;            /* Cirque Joystick - False */
        #endif
            break;
    #endif
    #ifdef _MAIN
        case _MAIN:
        #ifdef RGBLIGHT_ENABLE
            rgblight_sethsv(150, 30, 255);  /* RGB - AZURE */
        #endif
        #ifdef AUDIO_ENABLE
            PLAY_SONG(qwe_song);            /* Layer Song - Play */
        #endif
        #ifdef JOYSTICK_ENABLE
            JOYSTICK_ON = false;            /* Cirque Joystick - False */
        #endif
            break;
    #endif
    #ifdef _QWERTY
        case _QWERTY:
        #ifdef RGBLIGHT_ENABLE
            rgblight_sethsv(150, 30, 255);  /* RGB - AZURE */
        #endif
        #ifdef AUDIO_ENABLE
            PLAY_SONG(qwe_song);            /* Layer Song - Play */
        #endif
        #ifdef JOYSTICK_ENABLE
            JOYSTICK_ON = false;            /* Cirque Joystick - False */
        #endif
            break;
    #endif
        default: // Primary/default layer
        #ifdef RGBLIGHT_ENABLE
            rgblight_sethsv(150, 30, 255);  /* RGB - AZURE */
        #endif
        #ifdef AUDIO_ENABLE
            PLAY_SONG(qwe_song);            /* Layer Song - Play */
        #endif
        #ifdef JOYSTICK_ENABLE
            JOYSTICK_ON = false;            /* Cirque Joystick - False */
        #endif
            break;
    }
  return state;
}

// Pointers - Dual pointer initialization
#ifdef POINTING_DEVICE_COMBINED
report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {

//  Inverting the Scroll Wheel on the right-hand side
    right_report.v = right_report.h;
    right_report.h = right_report.v;     

//  Inverting the left-click and right-click functions on the right-hand side
    if((right_report.buttons) == MOUSE_BTN1) {
    right_report.buttons &= ~MOUSE_BTN1;
    right_report.buttons |= MOUSE_BTN2;
    } else if((right_report.buttons) == MOUSE_BTN2) {
    right_report.buttons &= ~MOUSE_BTN2;
    right_report.buttons |= MOUSE_BTN1;
    } else {
    right_report.buttons &= ~MOUSE_BTN1;
    right_report.buttons &= ~MOUSE_BTN2;
    }
    
#ifdef JOYSTICK_ENABLE
//  Cirque Joystick - Setting the previously enumerated Joystick axes
    if(JOYSTICK_ON) {
//  Parsing the calculations for each axis to their own temp variables
    uint16_t LeftTempx = (joystick_read_axis(0) + left_report.x) * JOYSTICK_SPEED;
    uint16_t LeftTempy = (joystick_read_axis(1) + left_report.y) * JOYSTICK_SPEED;
    uint16_t RightTempx = (joystick_read_axis(2) + right_report.x) * JOYSTICK_SPEED;
    uint16_t RightTempy = (joystick_read_axis(3) + right_report.y) * JOYSTICK_SPEED;
// Setting the Left stick's X axis
    if(left_report.x < 0 || left_report.x > 0) {
        joystick_set_axis(0, +LeftTempx);
    }
// Setting the Left stick's Y axis
    if(left_report.y < 0 || left_report.y > 0) {
        joystick_set_axis(1, +LeftTempy);
    }
// Setting the Right stick's X axis
    if(right_report.x < 0 || right_report.x > 0) {
        joystick_set_axis(2, +RightTempx);
    }
// Setting the Right sticks Y axis
    if(right_report.y < 0 || right_report.y > 0) {
        joystick_set_axis(3, +RightTempy);
    }
// Setting the non-joystick related pointer movements to zero when on a Joystick layer
        left_report.x = 0;
        left_report.y = 0;
        left_report.v = 0;
        left_report.h = 0;
        right_report.x = 0;
        right_report.y = 0;
        right_report.v = 0;
        right_report.h = 0;
        left_report.buttons &= ~MOUSE_BTN1;
        left_report.buttons &= ~MOUSE_BTN2;
        right_report.buttons &= ~MOUSE_BTN1;
        right_report.buttons &= ~MOUSE_BTN2;
    }
#endif
 
    return pointing_device_combine_reports(left_report, right_report);
}

#endif
