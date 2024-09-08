#include QMK_KEYBOARD_H
#include "keyboard.h"

#if defined(CUSTOM_CODES)
#   include "custom_keycodes.c"
#   endif

#if defined(JOYSTICK_ENABLE)
#   include "joystick.h"
#   endif

#include "drivers/sensors/cirque_pinnacle.h"

#if __has_include( "layers.h" ) && defined(LAYER_MAP)
    #include "layers.h"
#endif

#ifdef JOYSTICK_ENABLE
    joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
    JOYSTICK_AXIS_VIRTUAL, // 0 - Left Stick, X
    JOYSTICK_AXIS_VIRTUAL // 1 - Left Stick, Y
};
#endif

//Inverting the circular scroll function on the right-hand side
#if defined(CIRQUE_PINNACLE_CIRCULAR_SCROLL_ENABLE) && defined(POINTING_DEVICE_COMBINED)
void pointing_device_init_user(void) {
cirque_pinnacle_configure_circular_scroll(33, 16, 9102, 18, !is_keyboard_left());
};
#endif

uint8_t cirque_cpi_setting = 1;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_ACL0:
      if (record->event.pressed) {
        pointing_device_set_cpi_on_side(false, 300);
        pointing_device_set_cpi_on_side(true, 300);
        cirque_cpi_setting = 0;
      }
      return false; // Skip all further processing of this key
    case KC_ACL1:
      if (record->event.pressed) {
        pointing_device_set_cpi_on_side(false, 600);
        pointing_device_set_cpi_on_side(true, 600);
        cirque_cpi_setting = 1;
      }
      return false; // Skip all further processing of this key
    case KC_ACL2:
      if (record->event.pressed) {
        pointing_device_set_cpi_on_side(false, 800);
        pointing_device_set_cpi_on_side(true, 800);
        cirque_cpi_setting = 2;

      }
      return false; // Skip all further processing of this key
    default:
      return true; // Process all other keycodes normally
  }
}

// Pointers - Dual pointer initialization
#ifdef POINTING_DEVICE_COMBINED

report_mouse_t pointing_device_task_combined_kb(report_mouse_t left_report, report_mouse_t right_report) {  
#ifdef JOYSTICK_ENABLE
pinnacle_data_t cirque_joystick_set = cirque_pinnacle_read_data();

uint16_t xCirqueTemp = ((cirque_joystick_set.xValue/8)-128);
uint16_t yCirqueTemp = ((cirque_joystick_set.yValue/6)-128);
if(cirque_joystick_set.touchDown||cirque_joystick_set.zValue!=0){
    joystick_set_axis(0, xCirqueTemp);
    joystick_set_axis(1, yCirqueTemp); 
}
#endif
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
    if(layer_state_is(_GAMES)) {
// Setting the non-joystick related pointer movements to zero when on a Joystick layer
        pointing_device_set_cpi_on_side(false, 2000);
        left_report.x = 0;
        left_report.y = 0;
        left_report.v = 0;
        left_report.h = 0;
        left_report.buttons &= ~MOUSE_BTN1;
        left_report.buttons &= ~MOUSE_BTN2;
        right_report.buttons &= ~MOUSE_BTN1;
        right_report.buttons &= ~MOUSE_BTN2;
    }
    else if(!layer_state_is(_GAMES)) {
    if(cirque_cpi_setting == 0) {
        pointing_device_set_cpi_on_side(false, 300);
    }else if(cirque_cpi_setting == 1) {
        pointing_device_set_cpi_on_side(false, 600);
    }else if(cirque_cpi_setting == 2) {
        pointing_device_set_cpi_on_side(false, 800);
    }
  }
#endif
 
    return pointing_device_combine_reports(left_report, right_report);
}

#endif
