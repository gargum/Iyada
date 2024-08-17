/*
This file exists primarily to allow for more advanced Cirque/Pointer configuration options.
*/
#include QMK_KEYBOARD_H
#include <iyada.h>
#include <ch.h>
#include <hal.h>
#include "joystick.h"

// Joysticks - Dual joystick initialization
#ifdef JOYSTICK_ENABLE
joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
    JOYSTICK_AXIS_VIRTUAL, // Left Stick, X
    JOYSTICK_AXIS_VIRTUAL, // Left Stick, Y
    JOYSTICK_AXIS_VIRTUAL, // Right Stick, X
    JOYSTICK_AXIS_VIRTUAL  // Right Stick, Y
};
#endif
// Pointers - Dual pointer initialization
#ifdef POINTING_DEVICE_COMBINED
report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {

    right_report.v = right_report.h;
    right_report.h = right_report.v;     

    /* Inverting the left-click and right-click functions on the right-hand side */
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
    int16_t left_x_val = left_report.x;
    uint8_t left_x_axis = joystick_read_axis(0);
    int16_t left_y_val = left_report.y;
    uint8_t left_y_axis = joystick_read_axis(1);
    int16_t right_x_val = right_report.x;
    uint8_t right_x_axis = joystick_read_axis(2);
    int16_t right_y_val = right_report.y;
    uint8_t right_y_axis = joystick_read_axis(3);

    if(left_report.x != 0) {
        left_x_val += left_report.x;
        left_x_axis += joystick_read_axis(0);
        
        joystick_set_axis(0, +left_x_axis+left_x_val);
    }
    if(left_report.y != 0) {
        left_y_val += left_report.y;
        left_y_axis += joystick_read_axis(1);
        
        joystick_set_axis(1, +left_y_axis+left_y_val);
    }
    if(right_report.x != 0) {
        right_x_val += right_report.x;
        right_x_axis += joystick_read_axis(2);
        
        joystick_set_axis(2, +right_x_axis+right_x_val);
    }
    if(right_report.y != 0) {
        right_y_val += right_report.y;
        right_y_axis += joystick_read_axis(3);
        
        joystick_set_axis(3, +right_y_axis+right_y_val);
    }
#endif
    return pointing_device_combine_reports(left_report, right_report);
}
#endif
// Encoders - Behaviour settings
#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
      return false; /* Don't process further events if user function exists and returns false */
    }
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_WH_D);
        } else {
            tap_code(KC_WH_U);
        }
    } else if (index == 2) { /* First encoder */
        if (clockwise) {
            tap_code(KC_WH_L);
        } else {
            tap_code(KC_WH_R);
        }
    } else if (index == 3) { /* Second encoder */
        if (clockwise) {
            register_code(KC_LCTL);
            tap_code(KC_PGUP);
            unregister_code(KC_LCTL);
        } else {
            register_code(KC_LCTL);
            tap_code(KC_PGDN);
            unregister_code(KC_LCTL);
        }
    }
    return true;
}
#endif
// Audio shutdown pin - Initialization
#ifdef AUDIO_ENABLE
void keyboard_pre_init_kb(void) {
    // ensure pin is set and enabled pre-audio init
    setPinOutput(SPEAKER_SHUTDOWN);
    writePinHigh(SPEAKER_SHUTDOWN);
    keyboard_pre_init_user();
}

void keyboard_post_init_kb(void) {
    // set pin based on active status
    writePin(SPEAKER_SHUTDOWN, audio_is_on());
    keyboard_post_init_user();
}

void audio_on_user(void) {
    writePinHigh(SPEAKER_SHUTDOWN);
}

void audio_off_user(void) {
    // needs a delay or it runs right after play note.
    wait_ms(200);
    writePinLow(SPEAKER_SHUTDOWN);
}
#endif
