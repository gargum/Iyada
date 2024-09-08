#include "rev1/settings.h"

// Keyboard layout
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_54(
TD_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_LBRC,      KC_RBRC,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     TD_GRV,
GUI_DEL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_MINS,      KC_EQL,   KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  GUI_QUO,
SC_LCPO,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                             KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  SC_RCPC,
KC_DOWN,  KC_LEFT,                                                                                                          KC_RGHT,  KC_UP,

                                                  KC_WBAK,  KC_MUTE,      KC_MPLY, KC_WFWD,
                                        KC_SPC,   TD_BCK,   TT_SYM,       TT_MOU,  KC_ENT,   KC_LSFT 
),

[_SYMBOL] = LAYOUT_54(
KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,        KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,
KC_TRNS,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_TRNS,      KC_TRNS,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_TRNS,
KC_TRNS,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,                          KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_DOT,   KC_QUES,  KC_TRNS,
KC_TRNS,  KC_TRNS,                                                                                                          KC_TRNS,  KC_TRNS,

                                                  KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,
                                        KC_TRNS,  KC_TRNS,  KC_TRNS,      TD_MOU,   KC_TRNS,  KC_TRNS 
),

[_MOUSE] = LAYOUT_54(
KC_TRNS,  RGB_VAD,  CW_TOGG,  KC_MS_U,  AS_TOGG,  DM_REC1,  DT_UP,        DT_DOWN,  KC_ACL0,  KC_BTN1,  KC_UP,    KC_BTN2,  RGB_VAI,  KC_TRNS,
KC_TRNS,  RGB_TOG,  KC_MS_L,  KC_MS_D,  KC_MS_R,  DM_RSTP,  KC_TRNS,      KC_TRNS,  KC_ACL1,  KC_LEFT,  KC_DOWN,  KC_RGHT,  AU_TOGG,  KC_TRNS,
KC_TRNS,  HF_PREV,  HF_COND,  HF_TOGG,  AC_ON,    DM_PLY1,                          KC_ACL2,  AC_OFF,   HF_RST,   HF_CONU,  HF_NEXT,  KC_TRNS,
KC_TRNS,  KC_TRNS,                                                                                                          KC_TRNS,  KC_TRNS,

                                                  KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,
                                        KC_TRNS,  KC_TRNS,  TD_SYM,       TD_QWE,   KC_TRNS,  KC_TRNS
),

[_GAMES] = LAYOUT_54(
GC_HOM,   KC_NO,    GC_L3,    GC_L2,    GC_L1,    GC_L3,    GC_SEL,       GC_STA,   GC_R3,    GC_R1,    GC_R2,    GC_R3,    KC_NO,    TT_GAM,
KC_NO,    GC_L1,    GC_L2,    GC_R2,    GC_R1,    GC_DPU,   KC_NO,        KC_NO,    GC_DPD,   GC_CRO,   GC_CIR,   GC_SQU,   GC_TRI,   KC_NO,
KC_NO,    HF_PREV,  HF_COND,  HF_TOGG,  KC_NO,    GC_DPL,                           GC_DPR,   KC_NO,    HF_RST,   HF_CONU,  HF_NEXT,  KC_NO,
GC_SEL,   GC_SEL,                                                                                                           GC_STA,   GC_STA,

                                                  KC_TRNS,  KC_SYRQ,      KC_CNCL,  KC_TRNS,
                                        GC_L1,    GC_L2,    GC_L3,        GC_R3,    GC_R2,    GC_R1
),

[_STENO] = LAYOUT_54(
STN_N1,   STN_N2,   STN_N3,   STN_N4,   STN_N5,   STN_N6,   STN_RES1,     STN_RES2, STN_N7,   STN_N8,   STN_N9,   STN_NA,   STN_NB,   STN_NC,
STN_FN,   STN_S1,   STN_TL,   STN_PL,   STN_HL,   STN_ST1,  STN_FN,       STN_FN,   STN_ST3,  STN_FR,   STN_PR,   STN_LR,   STN_TR,   STN_DR,
STN_FN,   STN_S2,   STN_KL,   STN_WL,   STN_RL,   STN_ST2,                          STN_ST4,  STN_RR,   STN_BR,   STN_GR,   STN_SR,   STN_ZR,
STN_ST2,  STN_ST1,                                                                                                          STN_ST3,  STN_ST4,

                                                  KC_NO,    STN_RES1,     STN_RES2, KC_NO,
                                        STN_A,    STN_O,    STN_ST1,      STN_ST3,  STN_E,    STN_U
)
};

// Encoders - Behaviour settings
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
//  Layer         - Left Rotary Encoder             - Left Scroll Encoder             - Right Scroll Encoder            - Right Rotary Encoder
    [_QWERTY] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(KC_WH_L, KC_WH_R), ENCODER_CCW_CW(KC_TABL, KC_TABR) },
    [_SYMBOL] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(KC_WH_L, KC_WH_R), ENCODER_CCW_CW(KC_TABL, KC_TABR) },
    [_MOUSE]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(KC_WH_L, KC_WH_R), ENCODER_CCW_CW(KC_TABL, KC_TABR) },
    [_GAMES]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(GC_DPU, GC_DPD), ENCODER_CCW_CW(GC_DPL, GC_DPR), ENCODER_CCW_CW(KC_TABL, KC_TABR) },
    [_STENO]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(KC_WH_L, KC_WH_R), ENCODER_CCW_CW(KC_TABL, KC_TABR) },
};
