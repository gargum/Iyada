/*
This file exists primarily to allow for more advanced Cirque/Pointer configuration options.
*/

#include QMK_KEYBOARD_H
#include <iyada.h>
#include <ch.h>
#include <hal.h>
#include "joystick.h"
#include "drivers/sensors/cirque_pinnacle.h"

// Joysticks - Dual joystick initialization
#ifdef JOYSTICK_ENABLE
joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
    JOYSTICK_AXIS_VIRTUAL, // 0 - Left Stick, X
    JOYSTICK_AXIS_VIRTUAL, // 1 - Left Stick, Y
    JOYSTICK_AXIS_VIRTUAL, // 2 - Right Stick, X
    JOYSTICK_AXIS_VIRTUAL  // 3 - Right Stick, Y
};

int16_t JOYSTICK_SPEED = 5;

#endif
// Pointers - Dual pointer initialization
#ifdef POINTING_DEVICE_COMBINED
report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {

    /* Inverting the Scroll Wheel on the right-hand side */
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
    if(left_report.x != 0) {
        joystick_set_axis(0, +left_report.x+(JOYSTICK_SPEED*joystick_read_axis(0)));
    }
    if(left_report.y != 0) {
        joystick_set_axis(1, +left_report.y+(JOYSTICK_SPEED*joystick_read_axis(1)));
    }
    if(right_report.x != 0) {
        joystick_set_axis(2, +right_report.x+(JOYSTICK_SPEED*joystick_read_axis(2)));
    }
    if(right_report.y != 0) {
        joystick_set_axis(3, +right_report.y+(JOYSTICK_SPEED*joystick_read_axis(3)));
    } 
#endif
    return pointing_device_combine_reports(left_report, right_report);
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
