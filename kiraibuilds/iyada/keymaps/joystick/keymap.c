#include "rev1/settings.h"

// Keyboard layout
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_GAMES] = LAYOUT_54(
GC_HOM,   KC_NO,    GC_L3,    GC_L2,    GC_L1,    GC_L3,    GC_SEL,       GC_STA,   GC_R3,    GC_R1,    GC_R2,    GC_R3,    KC_NO,    GC_HOM,
KC_NO,    GC_L1,    GC_L2,    GC_R2,    GC_R1,    GC_DPU,   KC_NO,        KC_NO,    GC_DPD,   GC_CRO,   GC_CIR,   GC_SQU,   GC_TRI,   KC_NO,
KC_NO,    HF_PREV,  HF_COND,  HF_TOGG,  KC_NO,    GC_DPL,                           GC_DPR,   KC_NO,    HF_RST,   HF_CONU,  HF_NEXT,  KC_NO,
GC_SEL,   GC_SEL,                                                                                                           GC_STA,   GC_STA,

                                                  KC_TRNS,  KC_SYRQ,      KC_CNCL,  KC_TRNS,
                                        GC_L1,    GC_L2,    GC_L3,        GC_R3,    GC_R2,    GC_R1
)
};

// Encoder functions
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
//  Layer         - Left Rotary Encoder             - Left Scroll Encoder             - Right Scroll Encoder            - Right Rotary Encoder
    [_GAMES] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(GC_DPD, GC_DPU), ENCODER_CCW_CW(GC_DPL, GC_DPR), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
