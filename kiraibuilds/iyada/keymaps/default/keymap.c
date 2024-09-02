#include "rev1/settings.h"

// Keyboard layout
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWE] = LAYOUT_54(
KC_DEL,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_LBRC,      KC_RBRC,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
KC_TAB,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_MINS,      KC_EQL,   KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
SC_LCPO,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                             KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  SC_RCPC,
KC_DOWN,  KC_LEFT,                                                                                                          KC_RGHT,  KC_UP,

                                                  KC_WBAK,  KC_MUTE,      KC_MPLY,  KC_WFWD,
                                        KC_SPC,   KC_BSPC,  TO(_SYM),     TO(_MOU), KC_ENT,   KC_LSFT 
),

[_SYM] = LAYOUT_54(
KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,        KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_GRV,
KC_LGUI,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_TRNS,      KC_TRNS,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_RGUI,
KC_LALT,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,                          KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_DOT,   KC_QUES,  KC_RALT,
KC_TRNS,  KC_TRNS,                                                                                                          KC_TRNS,  KC_TRNS,

                                                  KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,
                                        KC_TRNS,  KC_TRNS,  TO(_QWE),     TO(_MOU), KC_TRNS,  KC_TRNS 
),

[_MOU] = LAYOUT_54(
EH_LEFT,  RGB_VAD,  KC_BTN2,  KC_UP,    KC_BTN1,  KC_ACL0,  EH_RGHT,      EH_LEFT,  KC_ACL0,  KC_BTN1,  KC_UP,    KC_BTN2,  RGB_VAI,  EH_RGHT,
KC_HOME,  RGB_TOG,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_ACL1,  KC_PSCR,      KC_INS,   KC_ACL1,  KC_LEFT,  KC_DOWN,  KC_RGHT,  AU_TOGG,  KC_END,
KC_PGDN,  HF_PREV,  HF_COND,  HF_TOGG,  RGB_SAD,  KC_ACL2,                          KC_ACL2,  RGB_SAI,  HF_RST,   HF_CONU,  HF_NEXT,  KC_PGUP,
KC_TRNS,  KC_TRNS,                                                                                                          KC_TRNS,  KC_TRNS,

                                                  KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,
                                        KC_TRNS,  KC_TRNS,  TO(_SYM),     TO(_QWE), KC_TRNS,  KC_TRNS
)
};

// Encoder functions
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
//  Layer         - Left Rotary Encoder             - Left Scroll Encoder             - Right Scroll Encoder            - Right Rotary Encoder
    [_QWE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(KC_WH_L, KC_WH_R), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_SYM] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(KC_WH_L, KC_WH_R), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_MOU] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(KC_WH_L, KC_WH_R), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) }
};
