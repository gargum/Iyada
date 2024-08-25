// This file exists for the sake of convenience, and to make the keymap.c file(s) more readable and more easily edited.
//
// Remember, never put sensitive information like a password into this file!
#include "layers.h"

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
BCK_DANCE,
QWE_DANCE,
SYM_DANCE,
MOU_DANCE,
GAM_DANCE,
STE_DANCE,
};

// Tap dance function declarations
td_state_t cur_dance (tap_dance_state_t *state); 
void esc_finished (tap_dance_state_t *state, void *user_data);
void grv_finished (tap_dance_state_t *state, void *user_data);
void bck_finished (tap_dance_state_t *state, void *user_data);
void qwe_finished (tap_dance_state_t *state, void *user_data);
void sym_finished (tap_dance_state_t *state, void *user_data);
void mou_finished (tap_dance_state_t *state, void *user_data);
void esc_reset (tap_dance_state_t *state, void *user_data);
void grv_reset (tap_dance_state_t *state, void *user_data);
void bck_reset (tap_dance_state_t *state, void *user_data);
void qwe_reset (tap_dance_state_t *state, void *user_data);
void sym_reset (tap_dance_state_t *state, void *user_data);
void mou_reset (tap_dance_state_t *state, void *user_data);
void gam_finished (tap_dance_state_t *state, void *user_data);
void gam_reset (tap_dance_state_t *state, void *user_data);
void ste_finished (tap_dance_state_t *state, void *user_data);
void ste_reset (tap_dance_state_t *state, void *user_data);

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

void esc_finished (tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case TD_SINGLE_TAP: register_code(KC_TAB); break;
    case TD_SINGLE_HOLD: register_code(KC_LALT); break;
    case TD_DOUBLE_TAP: register_code(KC_ESC); break;
    case TD_DOUBLE_HOLD: register_code(KC_LALT); unregister_code(KC_LALT); register_code(KC_LALT); break;
    case TD_DOUBLE_SINGLE_TAP: register_code(KC_TAB); unregister_code(KC_TAB); register_code(KC_TAB); break;
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
};

void esc_reset (tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case TD_SINGLE_TAP: unregister_code(KC_TAB); break;
    case TD_SINGLE_HOLD: unregister_code(KC_LALT); break;
    case TD_DOUBLE_TAP: unregister_code(KC_ESC); break;
    case TD_DOUBLE_HOLD: unregister_code(KC_LALT); break;
    case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_TAB); break;
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
  }
  xtap_state.state = TD_NONE;
}

void grv_finished (tap_dance_state_t *state, void *user_data) {
 xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case TD_SINGLE_TAP: register_code(KC_BSLS); break;
    case TD_SINGLE_HOLD: register_code(KC_RALT); break;
    case TD_DOUBLE_TAP: register_code(KC_GRV); break;
    case TD_DOUBLE_HOLD: register_code(KC_RALT); unregister_code(KC_RALT); register_code(KC_RALT); break;
    case TD_DOUBLE_SINGLE_TAP: register_code(KC_BSLS); unregister_code(KC_BSLS); register_code(KC_BSLS); break;
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
 }
};

void grv_reset (tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case TD_SINGLE_TAP: unregister_code16(KC_BSLS); break;
    case TD_SINGLE_HOLD: unregister_mods(KC_RALT); break;
    case TD_DOUBLE_TAP: unregister_code(KC_GRV); break;
    case TD_DOUBLE_HOLD: unregister_code(KC_RALT); break;
    case TD_DOUBLE_SINGLE_TAP: unregister_code16(KC_BSLS); break;
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
  }
  xtap_state.state = TD_NONE;
}

void bck_finished (tap_dance_state_t *state, void *user_data) {
 xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case TD_SINGLE_TAP: register_code(KC_BSPC); break;
    case TD_SINGLE_HOLD: register_code(KC_LCTL); register_code(KC_BSPC); break;
    case TD_DOUBLE_TAP: register_code(KC_BSPC); unregister_code(KC_BSPC); register_code(KC_BSPC); break;
    case TD_DOUBLE_HOLD: register_code(KC_LCTL); register_code(KC_BSPC); unregister_code(KC_LCTL); unregister_code(KC_BSPC); register_code(KC_LCTL); register_code(KC_BSPC); break;
    case TD_DOUBLE_SINGLE_TAP: register_code(KC_BSPC); unregister_code(KC_BSPC); register_code(KC_BSPC); break;
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
 }
};

void bck_reset (tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case TD_SINGLE_TAP: unregister_code(KC_BSPC); break;
    case TD_SINGLE_HOLD: unregister_code(KC_LCTL); unregister_code(KC_BSPC); break;
    case TD_DOUBLE_TAP: unregister_code(KC_BSPC); break;
    case TD_DOUBLE_HOLD: unregister_code(KC_LCTL); unregister_code(KC_BSPC); break;
    case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_BSPC);
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
  }
  xtap_state.state = TD_NONE;
}

void qwe_finished (tap_dance_state_t *state, void *user_data) {
 xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case TD_SINGLE_TAP: layer_move(_QWERTY); break;
    case TD_SINGLE_HOLD: layer_move(_QWERTY); break;
    case TD_DOUBLE_TAP: layer_move(_QWERTY); break;
    case TD_DOUBLE_HOLD: layer_move(_QWERTY); break;
    case TD_DOUBLE_SINGLE_TAP: layer_move(_QWERTY); break;
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
 }
};

void qwe_reset (tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case TD_SINGLE_TAP: break;
    case TD_SINGLE_HOLD: layer_move(_MOUSE); break;
    case TD_DOUBLE_TAP: break;
    case TD_DOUBLE_HOLD: layer_move(_MOUSE); break;
    case TD_DOUBLE_SINGLE_TAP: break;
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
  }
  xtap_state.state = TD_NONE;
}

void sym_finished (tap_dance_state_t *state, void *user_data) {
 xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case TD_SINGLE_TAP: layer_move(_SYMBOL); break;
    case TD_SINGLE_HOLD: layer_move(_SYMBOL); break;
    case TD_DOUBLE_TAP: layer_move(_SYMBOL); break;
    case TD_DOUBLE_HOLD: layer_move(_SYMBOL); break;
    case TD_DOUBLE_SINGLE_TAP: layer_move(_SYMBOL); break;
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
 }
};

void sym_reset (tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case TD_SINGLE_TAP: break;
    case TD_SINGLE_HOLD: layer_move(_MOUSE); break;
    case TD_DOUBLE_TAP: break;
    case TD_DOUBLE_HOLD: layer_move(_MOUSE); break;
    case TD_DOUBLE_SINGLE_TAP: break;
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
  }
  xtap_state.state = TD_NONE;
}

void mou_finished (tap_dance_state_t *state, void *user_data) {
 xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case TD_SINGLE_TAP: layer_move(_MOUSE); break;
    case TD_SINGLE_HOLD: layer_move(_MOUSE); break;
    case TD_DOUBLE_TAP: layer_move(_MOUSE); break;
    case TD_DOUBLE_HOLD: layer_move(_MOUSE); break;
    case TD_DOUBLE_SINGLE_TAP: layer_move(_MOUSE); break;
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
 }
};

void mou_reset (tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case TD_SINGLE_TAP: break;
    case TD_SINGLE_HOLD: layer_move(_SYMBOL); break;
    case TD_DOUBLE_TAP: break;
    case TD_DOUBLE_HOLD: layer_move(_SYMBOL); break;
    case TD_DOUBLE_SINGLE_TAP: break;
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
  }
  xtap_state.state = TD_NONE;
}

void gam_finished (tap_dance_state_t *state, void *user_data) {
 xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case TD_SINGLE_TAP: layer_move(_GAMES); break;
    case TD_SINGLE_HOLD: layer_move(_GAMES); break;
    case TD_DOUBLE_TAP: layer_move(_GAMES); break;
    case TD_DOUBLE_HOLD: layer_move(_GAMES); break;
    case TD_DOUBLE_SINGLE_TAP: layer_move(_GAMES); break;
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
 }
};

void gam_reset (tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case TD_SINGLE_TAP: break;
    case TD_SINGLE_HOLD: layer_move(_QWERTY); break;
    case TD_DOUBLE_TAP: break;
    case TD_DOUBLE_HOLD: layer_move(_QWERTY); break;
    case TD_DOUBLE_SINGLE_TAP: break;
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
  }
  xtap_state.state = TD_NONE;
}

void ste_finished (tap_dance_state_t *state, void *user_data) {
 xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case TD_SINGLE_TAP: layer_move(_STENO); break;
    case TD_SINGLE_HOLD: layer_move(_STENO); break;
    case TD_DOUBLE_TAP: layer_move(_STENO); break;
    case TD_DOUBLE_HOLD: layer_move(_STENO); break;
    case TD_DOUBLE_SINGLE_TAP: layer_move(_STENO); break;
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
 }
};

void ste_reset (tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case TD_SINGLE_TAP: break;
    case TD_SINGLE_HOLD: layer_move(_QWERTY); break;
    case TD_DOUBLE_TAP: break;
    case TD_DOUBLE_HOLD: layer_move(_QWERTY); break;
    case TD_DOUBLE_SINGLE_TAP: break;
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
  }
  xtap_state.state = TD_NONE;
}

// define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
tap_dance_action_t tap_dance_actions[] = {
  [ESC_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, esc_finished, esc_reset),
  [GRV_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, grv_finished, grv_reset),
  [BCK_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, bck_finished, bck_reset),
  [QWE_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, qwe_finished, qwe_reset),
  [SYM_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sym_finished, sym_reset),
  [MOU_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, mou_finished, mou_reset),
  [GAM_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, gam_finished, gam_reset),
  [STE_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ste_finished, ste_reset)
};
