#include QMK_KEYBOARD_H
#include "joystick.h"
#include "keyboard.h"

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

//Layers - Detecting the current active layer, then responding accordingly
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case 0:
            rgblight_sethsv(160, 255, 255); /* RGB - BLUE */
            JOYSTICK_ON = true;             /* Cirque Joystick - True */
            break;
        default: // QWERTY layer
            rgblight_sethsv(150, 30, 255);  /* RGB - AZURE */
            JOYSTICK_ON = false;            /* Cirque Joystick - False */
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
 
    return pointing_device_combine_reports(left_report, right_report);
}
#endif
