#include QMK_KEYBOARD_H
#include "keyboard.h"

//Including the joystick.h file only if joysticks are actually enabled
#if defined(JOYSTICK_ENABLE)
#   include "joystick.h"
#   endif

//Including the Cirque drivers. This is being used to poll the Absolute X and Absolute Y values.
//
//NOTE: Use <variable>.xValue,  <variable>.yValue,  <variable>.zValue, and  <variable>.touchDown to actually poll/manipulate the data sent by the Cirque(s).
#include "drivers/sensors/cirque_pinnacle.h"

//Defining 4 virtual joystick axes, but only if joysticks are actually enabled. 
//We will be mapping the data polled from the Cirques onto these 4 axes later on.
#if defined(JOYSTICK_ENABLE)
#   include "joystick.h"
joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
    JOYSTICK_AXIS_VIRTUAL, // 0 -  Left Stick, X
    JOYSTICK_AXIS_VIRTUAL, // 1 -  Left Stick, Y
    JOYSTICK_AXIS_VIRTUAL, // 2 - Right Stick, X
    JOYSTICK_AXIS_VIRTUAL  // 3 - Right Stick, Y
};
#   endif
//Layer maps: 
//
//Having your layers declared in a separate file makes it easier for several files to all employ layer-dependant behaviours.
//This is a non-standard feature I just made up, so it will only be included if the user decides to copy the idea.
#if __has_include( "layers.h" ) && defined(LAYER_MAP)
    #include "layers.h"
#endif

//Inverting the circular scroll function on the right-hand side:
//
//Circular scrolling starting from the side of a given Cirque that faces the opposite keyboard half is vertical scrolling,
//Circular scrolling starting from the outer side of a given Cirque is horizontal scrolling.
#if defined(CIRQUE_PINNACLE_CIRCULAR_SCROLL_ENABLE) && defined(POINTING_DEVICE_COMBINED)
void pointing_device_init_user(void) {
cirque_pinnacle_configure_circular_scroll(33, 16, 9102, 18, !is_keyboard_left());
};
#endif

//Cirque Joystick Modes:
//
//There are multiple ways one might want the pair of Cirque trackpads to behave.
//As such, two buttons (KC_CNCL and KC_SYRQ) alongside this integer are used to toggle between multiple Joystick Modes.
#ifdef JOYSTICK_ENABLE
uint8_t cirque_joystick_mode = 1;
#endif

//Cirque CPI Settings
//
//KC_ACL0, KC_ACL1, and KC_ACL2 do not normally affect the CPI/DPI of Cirque trackpads.
//This integer alongside the code that follows used the pointing_device_set_cpi_on_side function to change that!
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
//Joystick Mode Shifting
//
//This code simply checks whether KC_CNCL or KC_SYRQ have been pressed, and changes the Joystick Mode value accordingly.
#ifdef JOYSTICK_ENABLE
    case KC_SYRQ:
      if (record->event.pressed) {
      
        if(cirque_joystick_mode > 1){
            cirque_joystick_mode -= 1;
        }else if(cirque_joystick_mode == 1){
            cirque_joystick_mode = 3;
        }

      }
      return false; // Skip all further processing of this key
    case KC_CNCL:
      if (record->event.pressed) {
        
        if(cirque_joystick_mode < 3){
            cirque_joystick_mode += 1;
        }else if(cirque_joystick_mode == 3){
            cirque_joystick_mode = 1;
        }

      }
      return false; // Skip all further processing of this key
#endif
    default:
      return true; // Process all other keycodes normally
  }
}

// Pointers - Initialization
//
// This is the beginning of the Cirque & Cirque Joystick code block
#ifdef POINTING_DEVICE_COMBINED
report_mouse_t pointing_device_task_combined_kb(report_mouse_t left_report, report_mouse_t right_report) {

//Cirque Joystick Code - Mode 1 Code
//
//Mode 1 - Polling the Absolute X and Absolute Y values from one Cirque trackpad, while treating the other as a mouse
#ifdef JOYSTICK_ENABLE
if(cirque_joystick_mode == 1){

//The is_keyboard_left() function is used here because the cirque_pinnacle_read_data() function ONLY returns the data corresponding to the Master half's Cirque*
if(is_keyboard_left()){
//Left Stick Code
pinnacle_data_t left_joystick_set = cirque_pinnacle_read_data();

uint16_t xLeftTemp = ((left_joystick_set.xValue/8)-128);
uint16_t yLeftTemp = ((left_joystick_set.yValue/8)-128);

        if(left_joystick_set.touchDown!=0||left_joystick_set.zValue!=0){
            joystick_set_axis(0, +xLeftTemp);
            joystick_set_axis(1, +yLeftTemp);
        }
        

}else{
//Right Stick Code
pinnacle_data_t right_joystick_set = cirque_pinnacle_read_data();

uint16_t xRightTemp = ((right_joystick_set.xValue/8)-128);
uint16_t yRightTemp = ((right_joystick_set.yValue/8)-128);

        if(right_joystick_set.touchDown!=0||right_joystick_set.zValue!=0){
            joystick_set_axis(2, +xRightTemp);
            joystick_set_axis(3, +yRightTemp);
        }


}
//Cirque Joystick Code - Mode 2 Code
//
//Mode 2 - Swiping in a direction on a given Cirque holds the corresponding joystick in that direction, while tapping resets it.
} else if (cirque_joystick_mode == 2) {
    //Left Stick Code
    uint16_t LeftCirqueX  = joystick_read_axis(0)+left_report.x;
    uint16_t LeftCirqueY  = joystick_read_axis(1)+left_report.y;
        //Left Stick - X Axis
        if(left_report.x!=0){
            joystick_set_axis(0, LeftCirqueX);
        }
        //Left Stick - Y Axis
        if(left_report.y!=0){
            joystick_set_axis(1, LeftCirqueY);
        }
    //Right Stick Code   
    uint16_t RightCirqueX = joystick_read_axis(2)+right_report.x;
    uint16_t RightCirqueY = joystick_read_axis(3)+right_report.y;
        //Right Stick - X Axis
        if(right_report.x!=0){
            joystick_set_axis(2, RightCirqueX);
        }
        //Right Stick - Y Axis
        if(right_report.y!=0){
            joystick_set_axis(3, RightCirqueY);
        }
//Cirque Joystick Code - Mode 3 Code
//
//Mode 3 - Polling the Absolute X and Absolute Y values from one Cirque trackpad, while putting the other into Mode 2
} else if (cirque_joystick_mode == 3) {
    if(is_keyboard_left()){
    
//Left Side Master - Code
    pinnacle_data_t left_joystick_set = cirque_pinnacle_read_data();
    //Left Stick Code
    uint16_t xLeftTemp = ((left_joystick_set.xValue/8)-128);
    uint16_t yLeftTemp = ((left_joystick_set.yValue/8)-128);

        if(left_joystick_set.touchDown!=0||left_joystick_set.zValue!=0){
            joystick_set_axis(0, +xLeftTemp);
            joystick_set_axis(1, +yLeftTemp);
        }
    //Right Stick Code  
    uint16_t RightCirqueX = joystick_read_axis(2)+right_report.x;
    uint16_t RightCirqueY = joystick_read_axis(3)+right_report.y;
        if(right_report.x!=0){
            joystick_set_axis(2, RightCirqueX);
        }
        
        if(right_report.y!=0){
            joystick_set_axis(3, RightCirqueY);
        }
    
    }else{
    
//Right Side Master - Code
    pinnacle_data_t right_joystick_set = cirque_pinnacle_read_data();
    //Right Stick Code
    uint16_t xRightTemp = ((right_joystick_set.xValue/8)-128);
    uint16_t yRightTemp = ((right_joystick_set.yValue/8)-128);

        if(right_joystick_set.touchDown!=0||right_joystick_set.zValue!=0){
            joystick_set_axis(2, +xRightTemp);
            joystick_set_axis(3, +yRightTemp);
        }
    //Left Stick Code
    uint16_t LeftCirqueX  = joystick_read_axis(0)+left_report.x;
    uint16_t LeftCirqueY  = joystick_read_axis(1)+left_report.y;
        if(left_report.x!=0){
            joystick_set_axis(0, LeftCirqueX);
        }
        
        if(left_report.y!=0){
            joystick_set_axis(1, LeftCirqueY);
        }
        
    }
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
// Setting the non-joystick related pointer movements to zero when appropriate
    if(cirque_joystick_mode == 1){
        left_report.x = 0;
        left_report.y = 0;
        left_report.v = 0;
        left_report.h = 0;
        right_report.v = 0;
        right_report.h = 0;
        left_report.buttons &= ~MOUSE_BTN1;
        left_report.buttons &= ~MOUSE_BTN2;
        right_report.buttons &= ~MOUSE_BTN1;
        right_report.buttons &= ~MOUSE_BTN2;
    }else if(cirque_joystick_mode == 2){
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
    }else if(cirque_joystick_mode == 3){
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
  } 
#endif
 
    return pointing_device_combine_reports(left_report, right_report);
}

#endif

// *ADDITIONAL INFORMATION:
//
//As previously mentioned, cirque_pinnacle_read_data() provides data associated with the Master half.
//
//It is technically possible to poll the Absolute X and Y values from both Cirques separately and simultaneously, however...
//
//1: When two Cirque trackpads are connected via I2C, they will both have the same I2C address unless reconfigured. If connected in this way, one can only poll the Absolute touch data from the Cirque connected to the Master half.
//2: The I2C address of a Cirque trackpad can be changed from the default address of 0x2A over to the address 0x2C by connecting the two pins labelled ADR using a 470K resistor.
//3: When two Cirque trackpads are connected via SPI, one can poll the Absolute X and Y values from them separately and simultaneously by connecting each Cirque to a different SS/CS pin on their respective keyboard half
//4: The code to accomplish these things is not technically part of QMK, so everything mentioned will be added externally using files like this such that those using the master QMK repository can still use it.
