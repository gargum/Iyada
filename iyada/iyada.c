/*
This file exists primarily to allow for more advanced Cirque/Pointer configuration options.
*/

#include "iyada.h"

report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
    /* Flipping the right-hand scroll wheel along the X-Axis */
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
    
    return pointing_device_combine_reports(left_report, right_report);
}

#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) { return false; }
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_A);
        } else {
            tap_code(KC_1);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_B);
        } else {
            tap_code(KC_2);
        }
    } else if (index == 2) {
        if (clockwise) {
            tap_code(KC_C);
        } else {
            tap_code(KC_3);
        }
    } else if (index == 3) {
        if (clockwise) {
            tap_code(KC_D);
        } else {
            tap_code(KC_4);
        }
    }
  return true;
}
#endif
