#include "rev1/settings.h"

// Keyboard layout
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_STENO] = LAYOUT_54(
STN_N1,   STN_N2,   STN_N3,   STN_N4,   STN_N5,   STN_N6,   STN_RES1,     STN_RES2, STN_N7,   STN_N8,   STN_N9,   STN_NA,   STN_NB,   STN_NC,
STN_FN,   STN_S1,   STN_TL,   STN_PL,   STN_HL,   STN_ST1,  STN_FN,       STN_FN,   STN_ST3,  STN_FR,   STN_PR,   STN_LR,   STN_TR,   STN_DR,
STN_FN,   STN_S2,   STN_KL,   STN_WL,   STN_RL,   STN_ST2,                          STN_ST4,  STN_RR,   STN_BR,   STN_GR,   STN_SR,   STN_ZR,
STN_ST2,  STN_ST1,                                                                                                          STN_ST3,  STN_ST4,

                                                  KC_NO,    STN_RES1,     STN_RES2, KC_NO,
                                        STN_A,    STN_O,    STN_ST1,      STN_ST3,  STN_E,    STN_U
)
};

// Encoder functions
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
//  Layer         - Left Rotary Encoder             - Left Scroll Encoder             - Right Scroll Encoder            - Right Rotary Encoder
    [_STENO] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(KC_WH_L, KC_WH_R), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) }
};
