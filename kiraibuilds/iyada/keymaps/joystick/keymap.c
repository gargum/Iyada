#include QMK_KEYBOARD_H
#include "custom_keycodes.h"
#include "graphics/default/default_oled.c"

// Layer definitions
enum { _GAMES };

// Keyboard layout
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_GAMES] = LAYOUT_54(
GC_HOM,   KC_NO,    KC_NO,    GC_L2,    GC_L1,    GC_L3,    GC_SEL,       GC_STA,   GC_R3,    GC_R1,    GC_R2,    KC_NO,    KC_NO,    GC_HOM,
KC_NO,    GC_L1,    GC_L2,    GC_R2,    GC_R1,    GC_DPU,   KC_NO,        KC_NO,    GC_DPD,   GC_CRO,   GC_CIR,   GC_SQU,   GC_TRI,   KC_NO,
KC_NO,    HF_PREV,  HF_COND,  HF_TOGG,  KC_NO,    GC_DPL,                           GC_DPR,   KC_NO,    HF_RST,   HF_CONU,  HF_NEXT,  KC_NO,
GC_SEL,   GC_SEL,                                                                                                           GC_STA,   GC_STA,

                                                  KC_NO,    KC_NO,        KC_NO,    KC_NO,
                                        GC_L1,    GC_L2,    GC_L3,        GC_R3,    GC_R2,    GC_R1
)
};

// Encoder functions
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
      return false; /* Don't process further events if user function exists and returns false */
    }
    if (index == 0) { /* LEFT ROTARY ENCODER */
        if (clockwise) { /* Volume Up */
            tap_code(KC_VOLU);
        } else { /* Volume Down */
            tap_code(KC_VOLD);
        }
    } else if (index == 1) { /* LEFT SCROLL ENCODER */
        if (clockwise) { /* Mouse wheel up */
            tap_code(KC_WH_U);
        } else { /* Mouse wheel down */
            tap_code(KC_WH_D);
        }
    } else if (index == 2) { /* RIGHT SCROLL ENCODER */
        if (clockwise) { /* Mouse wheel right */
            tap_code(KC_WH_R);
        } else { /* Mouse wheel left */
            tap_code(KC_WH_L);
        }
    } else if (index == 3) { /* RIGHT ROTARY ENCODER */
        if (clockwise) { /* Browser tab right */
            tap_code16(KC_MNXT);
        } else { /* Browser tab left */
            tap_code16(KC_MPRV);
        }
    }
    return true;
}
