#include QMK_KEYBOARD_H

// Layer name declarations
enum layers {
	_QWERTY,	// Default layer
	_SYMBOL,	// Symbols
	_MOUSE,		// Pointer & Settings
#ifdef JOYSTICK_ENABLE
	_GAMES,     // Gamepad layer
#endif
#ifdef STENO_ENABLE
    _STENO,     // Steno/Plover layer
#endif
};

#ifdef JOYSTICK_ENABLE
enum custom_keycodes {      
	GC_DPU = SAFE_RANGE,
	GC_DPD,
	GC_DPL,
	GC_DPR,
	GC_SQU,
	GC_CRO,
	GC_CIR,
	GC_TRI,
	GC_L1,
	GC_L2,
	GC_L3,
	GC_R1,
	GC_R2,
	GC_R3,
	GC_STA,
	GC_SEL,
	GC_HOM
};
#endif

#ifdef TAP_DANCE_ENABLE
// Enumerating the different types of button press (single tap, double tap, etc)
typedef enum presses {
TD_NONE,
TD_UNKNOWN,
TD_SINGLE_TAP,
TD_SINGLE_HOLD,
TD_DOUBLE_TAP,
TD_DOUBLE_HOLD,
TD_DOUBLE_SINGLE_TAP, //send two single taps
} td_state_t;

// Creating a system to detect keydown and keyup events
typedef struct {
bool is_press_action;
td_state_t state;
} td_tap_t;

// Enumerating the existing tap dances
enum {
ESC_DANCE,
GRV_DANCE,
BCK_DANCE
};

// Tap dance function declarations
td_state_t cur_dance (tap_dance_state_t *state);
td_state_t rig_dance (tap_dance_state_t *state);
void x_finished (tap_dance_state_t *state, void *user_data);
void y_finished (tap_dance_state_t *state, void *user_data);
void z_finished (tap_dance_state_t *state, void *user_data);
void x_reset (tap_dance_state_t *state, void *user_data);
void y_reset (tap_dance_state_t *state, void *user_data);
void z_reset (tap_dance_state_t *state, void *user_data);
#endif

// Keyboard layout
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT(
TD(ESC_DANCE), KC_Q,          KC_W,          KC_E,          KC_R,          KC_T,          KC_LBRC,           KC_RBRC,       KC_Y,          KC_U,          KC_I,          KC_O,          KC_P,          TD(GRV_DANCE),
GUI_T(KC_DEL), KC_A,          KC_S,          KC_D,          KC_F,          KC_G,          KC_MINS,           KC_EQL,        KC_H,          KC_J,          KC_K,          KC_L,          KC_SCLN,       RGUI_T(KC_QUOT),
SC_LCPO,       KC_Z,          KC_X,          KC_C,          KC_V,          KC_B,          KC_WBAK,           KC_WFWD,       KC_N,          KC_M,          KC_COMM,       KC_DOT,        KC_SLSH,       SC_RCPC,
KC_DOWN,       KC_LEFT,                      KC_SPC,        TD(BCK_DANCE), TT(_SYMBOL),   KC_MUTE,           KC_MPLY,       TT(_MOUSE),    KC_ENT,        KC_LSFT,                      KC_RGHT,       KC_UP
),

[_SYMBOL] = LAYOUT(
KC_TRNS,       KC_F1,         KC_F2,         KC_F3,         KC_F4,         KC_F5,         KC_F6,             KC_F7,         KC_F8,         KC_F9,         KC_F10,        KC_F11,        KC_F12,        KC_TRNS,
KC_TRNS,       KC_1,          KC_2,          KC_3,          KC_4,          KC_5,          KC_TRNS,           KC_TRNS,       KC_6,          KC_7,          KC_8,          KC_9,          KC_0,          KC_TRNS,
KC_TRNS,       KC_EXLM,       KC_AT,         KC_HASH,       KC_DLR,        KC_PERC,       KC_TRNS,           KC_TRNS,       KC_CIRC,       KC_AMPR,       KC_ASTR,       KC_DOT,        KC_QUES,       KC_TRNS,
KC_TRNS,       KC_TRNS,                      KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,           KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,                      KC_TRNS,       KC_TRNS
),

[_MOUSE] = LAYOUT(
KC_TRNS,       RGB_VAD,       AC_TOGG,       KC_MS_U,       AS_TOGG,       DM_REC1,       DT_UP,             DT_DOWN,       KC_ACL0,       KC_BTN1,       KC_UP,         KC_BTN2,       RGB_VAI,       KC_TRNS,
KC_TRNS,       RGB_TOG,       KC_MS_L,       KC_MS_D,       KC_MS_R,       DM_RSTP,       KC_TRNS,           KC_TRNS,       KC_ACL1,       KC_LEFT,       KC_DOWN,       KC_RGHT,       AU_TOGG,       KC_TRNS,
KC_TRNS,       HF_PREV,       HF_COND,       HF_TOGG,       CW_TOGG,       DM_PLY1,       KC_TRNS,           KC_TRNS,       KC_ACL2,       QK_LOCK,       HF_RST,        HF_CONU,       HF_NEXT,       KC_TRNS,
KC_TRNS,       KC_TRNS,                      KC_TRNS,       KC_TRNS,       TT(_MOUSE),    KC_TRNS,           KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,                      KC_TRNS,       KC_TRNS
) 
#ifdef JOYSTICK_ENABLE
,

[_GAMES] = LAYOUT(
GC_HOM,        KC_NO,         KC_NO,         GC_L2,         GC_L1,         GC_L3,         GC_SEL,            GC_STA,        GC_R3,         GC_R1,         GC_R2,         KC_NO,         KC_NO,         TT(_GAMES),
KC_NO,         GC_L1,         GC_L2,         GC_R2,         GC_R1,         GC_DPU,        KC_NO,             KC_NO,         GC_DPD,        GC_CRO,        GC_CIR,        GC_SQU,        GC_TRI,        KC_NO,
KC_NO,         HF_PREV,       HF_COND,       HF_TOGG,       KC_NO,         GC_DPL,        KC_TRNS,           KC_TRNS,       GC_DPR,        KC_NO,         HF_RST,        HF_CONU,       HF_NEXT,       KC_NO,
GC_SEL,        GC_SEL,                       GC_L1,         GC_L2,         GC_L3,         KC_TRNS,           KC_TRNS,       GC_R3,         GC_R2,         GC_R1,                        GC_STA,        GC_STA
)  
#endif

#ifdef STENO_ENABLE
,

[_STENO] = LAYOUT(
STN_N1,        STN_N2,        STN_N3,        STN_N4,        STN_N5,        STN_N6,        STN_RES1,          STN_RES2,      STN_N7,        STN_N8,        STN_N9,        STN_NA,        STN_NB,        STN_NC,
STN_FN,        STN_S1,        STN_TL,        STN_PL,        STN_HL,        STN_ST1,       STN_FN,            STN_FN,        STN_ST3,       STN_FR,        STN_PR,        STN_LR,        STN_TR,        STN_DR,
STN_FN,        STN_S2,        STN_KL,        STN_WL,        STN_RL,        STN_ST2,       KC_NO,             KC_NO,         STN_ST4,       STN_RR,        STN_BR,        STN_GR,        STN_SR,        STN_ZR,
STN_ST2,       STN_ST1,                      STN_A,         STN_O,         STN_ST1,       STN_RES1,          STN_RES2,      STN_ST3,       STN_E,         STN_U,                        STN_ST3,       STN_ST4
)  
#endif
};

#ifdef JOYSTICK_ENABLE
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case GC_DPU:
			if (record->event.pressed) {
				register_joystick_button(18);
			} else {
				unregister_joystick_button(18);
			}
			return false;
		case GC_DPD:
			if (record->event.pressed) {
				register_joystick_button(16);
			} else {
				unregister_joystick_button(16);
			}
			return false;
		case GC_DPL:
			if (record->event.pressed) {
				register_joystick_button(15);
			} else {
				unregister_joystick_button(15);
			}
			return false;
		case GC_DPR:
			if (record->event.pressed) {
				register_joystick_button(17);
			} else {
				unregister_joystick_button(17);
			}
			return false;
		case GC_SQU:
			if (record->event.pressed) {
				register_joystick_button(0);
			} else {
				unregister_joystick_button(0);
			}
			return false;
		case GC_CRO:
			if (record->event.pressed) {
				register_joystick_button(1);
			} else {
				unregister_joystick_button(1);
			}
			return false;
		case GC_CIR:
			if (record->event.pressed) {
				register_joystick_button(2);
			} else {
				unregister_joystick_button(2);
			}
			return false;
		case GC_TRI:
			if (record->event.pressed) {
				register_joystick_button(3);
			} else {
				unregister_joystick_button(3);
			}
			return false;
		case GC_L1:
			if (record->event.pressed) {
				register_joystick_button(4);
			} else {
				unregister_joystick_button(4);
			}
			return false;
		case GC_R1:
			if (record->event.pressed) {
				register_joystick_button(5);
			} else {
				unregister_joystick_button(5);
			}
			return false;
		case GC_L2:
			if (record->event.pressed) {
				register_joystick_button(6);
			} else {
				unregister_joystick_button(6);
			}
			return false;
		case GC_R2:
			if (record->event.pressed) {
				register_joystick_button(7);
			} else {
				unregister_joystick_button(7);
			}
			return false;
		case GC_SEL:
			if (record->event.pressed) {
				register_joystick_button(8);
			} else {
				unregister_joystick_button(8);
			}
			return false;
		case GC_STA:
			if (record->event.pressed) {
				register_joystick_button(9);
			} else {
				unregister_joystick_button(9);
			}
			return false;
		case GC_L3:
			if (record->event.pressed) {
				register_joystick_button(10);
			} else {
				unregister_joystick_button(10);
			}
			return false;
		case GC_R3:
			if (record->event.pressed) {
				register_joystick_button(11);
			} else {
				unregister_joystick_button(11);
			}
			return false;
		case GC_HOM:
			if (record->event.pressed) {
				register_joystick_button(12);
			} else {
				unregister_joystick_button(12);
			}
			return false;
		default:
			return true;
	}
};

#endif

#ifdef COMBO_ENABLE
// Defining the keyboard combos
const uint16_t PROGMEM combo1[]  =  {RGUI_T(KC_QUOT), SC_RCPC,         COMBO_END};
const uint16_t PROGMEM combo2[]  =  {GUI_T(KC_DEL),   SC_LCPO,         COMBO_END};
const uint16_t PROGMEM combo3[]  =  {KC_MUTE,         KC_MPLY,         COMBO_END};
const uint16_t PROGMEM combo4[]  =  {KC_MUTE,         KC_WBAK,         COMBO_END};
const uint16_t PROGMEM combo5[]  =  {KC_MPLY,         KC_WFWD,         COMBO_END};
const uint16_t PROGMEM combo6[]  =  {KC_WBAK,         KC_WFWD,         COMBO_END};
const uint16_t PROGMEM combo7[]  =  {KC_EQL,          KC_RBRC,         COMBO_END};
const uint16_t PROGMEM combo8[]  =  {KC_MINS,         KC_LBRC,         COMBO_END};
const uint16_t PROGMEM combo9[]  =  {KC_MINS,         KC_WBAK,         COMBO_END};
const uint16_t PROGMEM combo10[] =  {KC_EQL,          KC_WFWD,         COMBO_END};
const uint16_t PROGMEM combo11[] =  {KC_BTN1,         KC_UP,           COMBO_END};
#ifdef JOYSTICK_ENABLE
const uint16_t PROGMEM comboglr[] = {TT(_MOUSE),      TT(_SYMBOL),     COMBO_END};
#endif
#ifdef STENO_ENABLE
const uint16_t PROGMEM comboslr[] = {KC_LSFT,         TT(_MOUSE),      TT(_SYMBOL),    COMBO_END};
const uint16_t PROGMEM comboslx[] = {STN_N1,          STN_NC,          COMBO_END};
const uint16_t PROGMEM combopwr[] = {STN_RES1,        STN_RES2,        COMBO_END};
#endif
// Defining the outputs that result from the above keyboard combos
combo_t key_combos [] = {
	COMBO(combo1,  KC_END),
	COMBO(combo2,  KC_HOME),
	COMBO(combo3,  KC_PSCR),
	COMBO(combo4,  KC_SCRL),
	COMBO(combo5,  KC_NUM),
	COMBO(combo6,  KC_INS),
	COMBO(combo7,  KC_PGUP),
	COMBO(combo8,  KC_PGDN),
	COMBO(combo9,  EH_LEFT),
	COMBO(combo10, EH_RGHT),
	COMBO(combo11, KC_BTN3),
#ifdef JOYSTICK_ENABLE
	COMBO(comboglr, TT(_GAMES)),
#endif
#ifdef STENO_ENABLE
    COMBO(comboslr, TT(_STENO)),
    COMBO(comboslx, TT(_STENO)),
    COMBO(combopwr, STN_PWR),
#endif
}; 

#endif

#ifdef RGBLIGHT_LAYERS
const rgblight_segment_t PROGMEM my_qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 30, HSV_WHITE}
);
const rgblight_segment_t PROGMEM my_symbol_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 30, HSV_AZURE}
);
const rgblight_segment_t PROGMEM my_mouse_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 30, HSV_MAGENTA}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_qwerty_layer,
    my_symbol_layer,
    my_mouse_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _SYMBOL));
    rgblight_set_layer_state(2, layer_state_cmp(state, _MOUSE));
    return state;
}
#endif

#ifdef TAP_DANCE_ENABLE

// Converting the subtype of tap event that has been detected into a number
td_state_t cur_dance(tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return TD_SINGLE_TAP;
    //key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
    else return TD_SINGLE_HOLD;
  }
  else if (state->count == 2) {
    if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
    else if (state->pressed) return TD_DOUBLE_HOLD;
    else return TD_DOUBLE_TAP;
  } else return TD_UNKNOWN;
}

//initialise an instance of 'tap' for the 'x' tap dance.
static td_tap_t xtap_state = {
  .is_press_action = true,
  .state = TD_NONE
};

td_state_t rig_dance(tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return TD_SINGLE_TAP;
    else return TD_SINGLE_HOLD;
  }
  else if (state->count == 2) {
    if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
    else if (state->pressed) return TD_DOUBLE_HOLD;
    else return TD_DOUBLE_TAP;
  } else return TD_UNKNOWN;
}

void x_finished (tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case TD_SINGLE_TAP: register_code(KC_TAB); break;
    case TD_SINGLE_HOLD: register_code(KC_LALT); break;
    case TD_DOUBLE_TAP: register_code(KC_ESC); break;
    case TD_DOUBLE_HOLD: register_code(KC_LALT); unregister_code(KC_LALT); register_code(KC_LALT); break;
    case TD_DOUBLE_SINGLE_TAP: register_code(KC_TAB); unregister_code(KC_TAB); register_code(KC_TAB);
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
};

void x_reset (tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case TD_SINGLE_TAP: unregister_code(KC_TAB); break;
    case TD_SINGLE_HOLD: unregister_code(KC_LALT); break;
    case TD_DOUBLE_TAP: unregister_code(KC_ESC); break;
    case TD_DOUBLE_HOLD: unregister_code(KC_LALT); break;
    case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_TAB);
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
  }
  xtap_state.state = TD_NONE;
}

//instanalize an instance of 'tap' for the 'y' tap dance.
static td_tap_t ytap_state = {
  .is_press_action = true,
  .state = TD_NONE
};

void y_finished (tap_dance_state_t *state, void *user_data) {
 ytap_state.state = rig_dance(state);
  switch (ytap_state.state) {
    case TD_SINGLE_TAP: register_code(KC_BSLS); break;
    case TD_SINGLE_HOLD: register_code(KC_RALT); break;
    case TD_DOUBLE_TAP: register_code(KC_GRV); break;
    case TD_DOUBLE_HOLD: register_code(KC_RALT); unregister_code(KC_RALT); register_code(KC_RALT); break;
    case TD_DOUBLE_SINGLE_TAP: register_code(KC_BSLS); unregister_code(KC_BSLS); register_code(KC_BSLS);
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
 }
};

void y_reset (tap_dance_state_t *state, void *user_data) {
  switch (ytap_state.state) {
    case TD_SINGLE_TAP: unregister_code16(KC_BSLS); break;
    case TD_SINGLE_HOLD: unregister_mods(KC_RALT); break;
    case TD_DOUBLE_TAP: unregister_code(KC_GRV); break;
    case TD_DOUBLE_HOLD: unregister_code(KC_RALT); break;
    case TD_DOUBLE_SINGLE_TAP: unregister_code16(KC_BSLS);
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
  }
  ytap_state.state = TD_NONE;
}

void z_finished (tap_dance_state_t *state, void *user_data) {
 ytap_state.state = rig_dance(state);
  switch (ytap_state.state) {
    case TD_SINGLE_TAP: register_code(KC_BSPC); break;
    case TD_SINGLE_HOLD: register_code(KC_LCTL); register_code(KC_BSPC); break;
    case TD_DOUBLE_TAP: register_code(KC_BSPC); unregister_code(KC_BSPC); register_code(KC_BSPC); break;
    case TD_DOUBLE_HOLD: register_code(KC_LCTL); register_code(KC_BSPC); unregister_code(KC_LCTL); unregister_code(KC_BSPC); register_code(KC_LCTL); register_code(KC_BSPC); break;
    case TD_DOUBLE_SINGLE_TAP: register_code(KC_BSPC); unregister_code(KC_BSPC); register_code(KC_BSPC);
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
 }
};

void z_reset (tap_dance_state_t *state, void *user_data) {
  switch (ytap_state.state) {
    case TD_SINGLE_TAP: unregister_code(KC_BSPC); break;
    case TD_SINGLE_HOLD: unregister_code(KC_LCTL); unregister_code(KC_BSPC); break;
    case TD_DOUBLE_TAP: unregister_code(KC_BSPC); break;
    case TD_DOUBLE_HOLD: unregister_code(KC_LCTL); unregister_code(KC_BSPC); break;
    case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_BSPC);
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
  }
  ytap_state.state = TD_NONE;
}


// define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
tap_dance_action_t tap_dance_actions[] = {
  [ESC_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset),
  [GRV_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, y_finished, y_reset),
  [BCK_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, z_finished, z_reset)
};

#endif

#ifdef OLED_ENABLE

#define FRAME_DURATION 333
#define LOGO_INTERVAL 20000
#define GLITCH_INTERVAL 21998

uint8_t current_frame = 0;

static void render_logo(void);
static void render_animation(void);

static void render_logo(void) {

    uint32_t utime = 0;
    
    const char PROGMEM iyada_logo [] = {
            0,  0,  0,  0,120,104,104,232,208,208,160,160, 64, 64,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,248,  8,232,232,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,232,232,232,248,  0,120,104,104,232,208,208,160,160, 64, 64,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128, 64,160,160,208,120,  0,248,  8,248,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,248,  8,248,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  3,  7,  7, 14,254,253,253,250, 26, 52, 52,104,232,208,208,224,224,  0,255,  0,255,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,255,255,255,  0,  0,  0,  0,  0,  1,  1,  3,  3,  7,  7, 14,254,253,253,250, 26, 52, 52,104,232,208,208,224,  0,192, 64, 64, 64, 64, 64, 64,160,160,208,104,104, 52, 26, 26, 13,  6,  6,  3,  1,  1,  0,  0,  0,255,  0,127, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,127,  0,255,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,128,128,192,192,224,224,240,255,255,255,127,120, 60, 60, 30, 31, 15, 15,  7,  7,  0,127,255,255,255,192,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,192,255,255,255,127,  0,  0,  0,  0,  0,128,128,192,192,224,224,240,255,255,255,127,120, 60, 60, 30, 31, 15, 15,  7,  0,  3,  3,  3,  3,  3,  3,  3,  7,  7, 15, 30, 30, 60,120,120,240,224,224,192,128,128,  0,  0,  0,255,255,255,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,255,255,255,  0,  0,  0,  0, 
        0,  0,  0,  0, 30, 30, 30, 31, 15, 15,  7,  7,  3,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  3,  7, 15, 31, 30, 30, 30, 30, 30, 30, 30, 30, 30, 31, 15,  7,  3,  1,  0,  0,  0, 30, 30, 30, 31, 15, 15,  7,  7,  3,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7,  7, 15, 30,  0, 31, 31, 31,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 31, 31, 31,  0,  0,  0,  0,
    };
    
   if (timer_elapsed(utime) < LOGO_INTERVAL) {
       utime = timer_read();
       oled_write_raw_P(iyada_logo, sizeof(iyada_logo));    
    } else {
       render_animation();
    }
}


static void render_main(void) {
 static const char PROGMEM main_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 60,252,252,236,  0,  0,128,192,192,192,192,192,192,192,128,  0,128,192,192,128,  0,  0,224,240,248, 60, 28, 28, 28, 28, 28, 60,120,240,224,192,  0,  0,140,140,140,140,140,140,140,140,140,140,220,252,252,180,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 60, 31, 15,  7,  0,  0,  1,  3,  3,  3,  3,  3,  3,  3,  1,  0,  1,  3,  3,  1,  0,  0, 59, 31, 15, 30, 28, 28, 28, 28, 28, 28, 30, 15,  7,  3,  0,  0, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 59, 63, 31, 13,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
};

oled_write_raw_P(main_logo, sizeof(main_logo));
}

static void render_symbol(void) {
    static const char PROGMEM symbol_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,192,192,192,192,192,192,224,224,224,240,240,  0,  0,224,240,248, 60, 28, 28, 28, 28, 28, 28, 60,248,240,224,  0,  0,236,252,124, 60, 28, 28, 28, 60,124,236,204, 12, 12, 12,  0,  0,140,140,140,140,140,140,140,140,140,140,220,252,252,180,  0,  0,192,128,  0,  0,  0,  0,240,248, 60, 28, 28, 28, 28, 12,  0,  0,224,240,248, 28, 12,  0,240,248, 60, 28, 60,248,240,224,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 15, 15,  7,  7,  7,  3,  3,  3,  3,  3,  3,  3,  1,  1,  0,  0,  7, 15, 31, 60, 56, 56, 56, 56, 56, 56, 60, 31, 15,  7,  0,  0,  7, 15, 28, 56, 48, 48, 48, 56, 28, 15,  7,  0,  0,  0,  0,  0, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 59, 63, 31, 13,  0,  0,  1,  3,  7, 14, 28, 56, 63, 63, 60, 56, 56, 56, 56, 48,  0,  0,  7, 15, 31, 56, 48, 56, 31, 15,  0,  0, 48, 63, 31, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    };
    oled_write_raw_P(symbol_logo, sizeof(symbol_logo));
}

static void render_mouse(void) {
    static const char PROGMEM mouse_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,224,240,248, 60, 28, 28,252,252,252, 28, 60,248,240,224,  0,  0,224,240, 56, 28, 12,  0,224,240, 56, 28, 28, 56,240,224,  0,  0,240,248,252, 60, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,  0,  0,224,240,248,124, 60, 28, 28, 28, 28, 60,124,248,240,224,  0,  0,140,140,140,140,140,140,140,140,140,140,220,252,252,108,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  7, 15, 31, 60, 56,  0, 63, 63, 63, 56, 60, 31, 15,  7,  0,  0,  7, 15, 28, 56, 56, 28, 15,  3,  0, 48, 56, 28, 15,  7,  0,  0, 15, 31, 63, 60, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56,  0,  0,  7, 15, 31, 62, 60, 56, 56, 56, 56, 60, 62, 31, 15,  7,  0,  0, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 59, 63, 31, 13,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    };
    oled_write_raw_P(mouse_logo, sizeof(mouse_logo));
}
#ifdef JOYSTICK_ENABLE
static void render_games(void) {
    static const char PROGMEM mouse_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,240,248, 28, 14,  6,  6,254,254,  6,  6, 14, 28,248,240,  0,  0,134,134,134,134,134,134,134,134,134,134,206,238,254,182,  0,  0,224,240,248, 60, 30, 14, 14, 14, 14, 30, 60,120,240,224,  0,  0,240,248, 28, 14,  6,  6,  6,  6,  6,  6, 14, 28,248,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 31, 63,112, 96,  0,  0, 63,127, 96, 96,112, 56, 31, 15,  0,  0, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97,115, 59, 31, 13,  0,  0,103,111,127,120,112,112,112,112,112,112,120, 60, 31, 15,  0,  0, 15, 31, 56,112, 96, 96,126,126,  0, 96,112, 56, 31, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    };
    oled_write_raw_P(mouse_logo, sizeof(mouse_logo));
}
#endif

#ifdef STENO_ENABLE
static void render_steno(void) {
    static const char PROGMEM plover_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 60,252,252,204,  0,  0,224,240,248, 60, 28, 28,252,252,252, 28, 60,248,240,224,  0,  0,128,192,224,224,112,112,112, 56, 56, 56, 56, 28, 28, 28,  0,  0,224,240,248, 60, 28, 28, 28, 28, 28, 28, 60,248,240,224,  0,  0,128,128,192,192,192,192,192,192,192,224,224,224,240,240,  0,  0, 12, 28, 28, 28,220,252, 60, 28, 28, 28, 60,124,236,204,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 56, 63, 31, 15,  0,  0,  7, 15, 31, 56,  0,  0, 63, 63, 63, 56, 60, 31, 15,  7,  0,  0,  1,  3,  7,  7, 14, 14, 14, 28, 28, 28, 28, 56, 56, 56,  0,  0,  7, 15, 31, 60, 56, 56, 56, 56, 56, 56, 60, 31, 15,  7,  0,  0, 15, 15,  7,  7,  7,  3,  3,  3,  3,  3,  3,  3,  1,  1,  0,  0,  0,  0,  0,  0, 15, 31, 56, 48, 48, 48, 48, 56, 31, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    };
    oled_write_raw_P(plover_logo, sizeof(plover_logo));
}
#endif
static void render_animation(void) {

    uint32_t timer = 0;

    static const char PROGMEM frame_0 [] = {
        0,  0,  0,  0,120,104,104,232,208,208,160,160, 64, 64,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,248,  8,232,232,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,232,232,232,248,  0,120,104,104,232,208,208,160,160, 64, 64,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128, 64,160,160,208,120,  0,248,  8,248,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,248,  8,248,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  3,  7,  7, 14,254,253,253,250, 26, 52, 52,104,232,208,208,224,224,  0,255,  0,255,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,255,255,255,  0,  0,  0,  0,  0,  1,  1,  3,  3,  7,  7, 14,254,253,253,250, 26, 52, 52,104,232,208,208,224,  0,192, 64, 64, 64, 64, 64, 64,160,160,208,104,104, 52, 26, 26, 13,  6,  6,  3,  1,  1,  0,  0,  0,255,  0,127, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,127,  0,255,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,128,128,192,192,224,224,240,255,255,255,127,120, 60, 60, 30, 31, 15, 15,  7,  7,  0,127,255,255,255,192,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,192,255,255,255,127,  0,  0,  0,  0,  0,128,128,192,192,224,224,240,255,255,255,127,120, 60, 60, 30, 31, 15, 15,  7,  0,  3,  3,  3,  3,  3,  3,  3,  7,  7, 15, 30, 30, 60,120,120,240,224,224,192,128,128,  0,  0,  0,255,255,255,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,255,255,255,  0,  0,  0,  0, 
        0,  0,  0,  0, 30, 30, 30, 31, 15, 15,  7,  7,  3,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  3,  7, 15, 31, 30, 30, 30, 30, 30, 30, 30, 30, 30, 31, 15,  7,  3,  1,  0,  0,  0, 30, 30, 30, 31, 15, 15,  7,  7,  3,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7,  7, 15, 30,  0, 31, 31, 31,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 31, 31, 31,  0,  0,  0,  0,
    };
    
    static const char PROGMEM frame_1 [] = {
            0,  0,  0,  0,120, 52,104,232,160,208,144,  0, 64,  0,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,252,  0,232,  0,104, 64,104,  0,104,208,104,104, 52,104,160,104,104,208,208,232,  0,250,248,  0,120, 52,  0,232,208,160, 14,160, 64, 64,  0,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,  0, 52,160,208,120,  0,248,  8,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,252,  0,248,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  3,  1,  1,  0,  7,232, 14,254,  0,253,250, 52,104,  0,104,250,208,208,192,240,  0,255,  8,255,  0,  0,  3,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,255,  0,255,255,  0,  0,  0,  0,  0,  1,  3,  0,  3,  7,  7,208,254,  0,253,250,104,  0, 52,104,232,  0,160,224,  0,192,128, 64,  0, 64,208, 64,160,128,208,104,104,  0, 26,160, 13,  6,  6,160,  0,  1,  0,  0,  0,255,  0,255,  0, 64, 64,  0, 64,160,128, 26, 64, 64, 64,  0, 64, 64, 64, 64,  0,127,  0,255,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,128,224,  0,224,  1,240,255,  0,255,127,240,120,  0, 30,  7, 15, 15, 15,  3,  0, 63,128,255,  0,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,255,  0, 63,127,  0,  0,  0,  0,  0,128,  0, 31,192,224,224,  0,255,  0,255,127,224,  0, 60, 30, 31,  0, 31,  7,  0,  3,  6,  3,  0,  3,  0,  3,  7, 30, 15, 30, 30,  0,120,129,240,224,224,  1,128,128,  0,  0,  0,255,255,251, 13,  3,  3,  0,  3,  1,  6,  0,  3,  3,  3,208,  3,  3,  3,  3,  0,255,252,255,  0,  0,  0,  0, 
        0,  0,  0,  0, 30, 15, 30, 31, 31, 15,  3,  0,  3,124,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,127,  1,  0,  7,124, 31,  0, 30, 60, 30, 30, 15, 30,120, 30, 31, 15, 15,  3,  0,  0,  0,  0, 30, 15,  0, 31, 15, 31,  0,  7,  3,  3, 62,  1,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  0,  1,  1,  0,  7,  7, 30, 30,  0, 31, 31,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 15,127, 31,  0,  0,  0,  0,
    };
    
    static const char PROGMEM frame_2 [] = {
        0,  0,  0,  0,120, 52,104,232,160,  0,  0,  0, 64,  0,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,252,  0,  0,  0,  0, 64,104,  0,  0,  0,104,104, 52,104,160,104,104,208,  0,  0,  0,250,  0,  0,  0, 52,  0,  0,  0,160, 14,160, 64, 64,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,  0, 52,160,208,120,  0,248,  8,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,252,  0,248,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  3,  0,  0,  0,  7,232, 14,  0,  0,  0,250, 52,  0,  0,  0,250,208,  0,  0,  0,  0,255,  8,  0,  0,  0,  3,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,255,  0,  0,  0,  0,  0,  0,  0,  3,  0,  3,  7,  7,208,  0,  0,  0,250,  0,  0,  0,104,  0,  0,  0,224,  0,  0,128,  0,  0,  0,208, 64,  0,  0,  0,104,  0,  0,  0,160, 13,  6,  6,160,  0,  1,  0,  0,  0,255,  0,255,  0, 64,  0,  0,  0,160,128, 26, 64, 64,  0,  0,  0, 64, 64, 64,  0,127,  0,255,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,224,  1,240,  0,  0,  0,127,240,  0,  0,  0,  7, 15,  0,  0,  0,  0, 63,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,  0,  0,  0, 63,  0,  0,  0,  0,  0,  0,  0,  0, 31,192,224,224,  0,  0,  0,  0,127,  0,  0,  0, 30,  0,  0,  0,  7,  0,  0,  6,  0,  0,  0,  0,  3,  0,  0,  0, 30,  0,  0,  0,129,240,224,224,  1,128,128,  0,  0,  0,255,255,251, 13,  3,  0,  0,  0,  1,  6,  0,  3,  3,  0,  0,  0,  3,  3,  3,  0,255,252,255,  0,  0,  0,  0, 
        0,  0,  0,  0, 30, 15, 30, 31, 31,  0,  0,  0,  3, 60,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 63,  0,  0,  0, 60, 31,  0,  0,  0, 30, 30, 15, 30, 56, 30, 31, 15,  0,  0,  0,  0,  0,  0,  0, 15,  0,  0,  0, 31,  0,  7,  3,  3, 62,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  0,  1,  1,  0,  7,  7, 30, 30,  0, 31, 31, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 15, 63, 31,  0,  0,  0,  0,
    };
    
    static const char* bitmap_allArray[3] = {
       frame_0,
       frame_1,
       frame_2
    };
    
    uint16_t frame_sizes[3] = {
    sizeof(frame_0),
    sizeof(frame_1),
    sizeof(frame_2)
    };
    
    if (timer_elapsed(timer) > FRAME_DURATION && timer_elapsed(timer) < GLITCH_INTERVAL) {
    timer = timer_read();
    current_frame = (current_frame + 1) % (sizeof(bitmap_allArray) / sizeof(bitmap_allArray[0]));
    oled_write_raw_P(bitmap_allArray[current_frame], frame_sizes[current_frame]);
    }
    if (timer_elapsed(timer) > GLITCH_INTERVAL) {
    current_frame = 0;
    oled_write_raw_P(bitmap_allArray[current_frame], frame_sizes[current_frame]);
    }
}

//Draw to OLED
bool oled_task_user() {
 // Set cursor position
 oled_set_cursor(0, 0);

if (is_keyboard_left()) {
 // Write current layer to OLED display
switch (get_highest_layer(layer_state)) {
 case _QWERTY :
 render_main();
  break;
 case _SYMBOL :
 render_symbol();
  break;
 case _MOUSE :
 render_mouse();
  break;
  
#ifdef JOYSTICK_ENABLE
 case _GAMES :
 render_games();
  break;
#endif

#ifdef STENO_ENABLE
 case _STENO :
 render_steno();
  break;
#endif

 }
} else {
 render_logo();
}
return false;
}

#endif
