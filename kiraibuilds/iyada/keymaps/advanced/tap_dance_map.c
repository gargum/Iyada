// This file exists to make custom tap dances easier to define, edit, and understand.
//
// The available tap types are TD_<NUMBER>_TAP, TD_<NUMBER>_HOLD, and TD_<NUMBER>_SINGLE_TAP.
// The available <NUMBER> values are SINGLE, DOUBLE and TRIPLE.
//
// This means any user-defined Tap Dance Map may map a maximum of 8 separate functions to a single key, excluding TD_NONE and/or TD_UNKNOWN.

#include "rev1/tap_defs.c"

#if __has_include( "layers.h" ) && LAYER_MAP == yes
    #include "layers.h"
#endif

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
// ESC_DANCE
void esc_keydown (tap_dance_state_t *state, void *user_data);
void esc_keyup (tap_dance_state_t *state, void *user_data);

// GRV_DANCE
void grv_keydown (tap_dance_state_t *state, void *user_data);
void grv_keyup (tap_dance_state_t *state, void *user_data);

// BCK_DANCE
void bck_keydown (tap_dance_state_t *state, void *user_data);
void bck_keyup (tap_dance_state_t *state, void *user_data);

// QWE_DANCE
void qwe_keydown (tap_dance_state_t *state, void *user_data);
void qwe_keyup (tap_dance_state_t *state, void *user_data);

// SYM_DANCE
void sym_keydown (tap_dance_state_t *state, void *user_data);
void sym_keyup (tap_dance_state_t *state, void *user_data);

// MOU_DANCE
void mou_keydown (tap_dance_state_t *state, void *user_data);
void mou_keyup (tap_dance_state_t *state, void *user_data);

// GAM_DANCE
void gam_keydown (tap_dance_state_t *state, void *user_data);
void gam_keyup (tap_dance_state_t *state, void *user_data);

// STE_DANCE
void ste_keydown (tap_dance_state_t *state, void *user_data);
void ste_keyup (tap_dance_state_t *state, void *user_data);

// Tap dance functions
void esc_keydown (tap_dance_state_t *state, void *user_data) {
  tap_state.state = current_dance(state);
  switch (tap_state.state) {
    case TD_SINGLE_TAP: register_code(KC_TAB); break;
    case TD_SINGLE_HOLD: register_code(KC_LALT); break;
    case TD_DOUBLE_TAP: register_code(KC_ESC); break;
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
  }
};

void esc_keyup (tap_dance_state_t *state, void *user_data) {
  switch (tap_state.state) {
    case TD_SINGLE_TAP: unregister_code(KC_TAB); break;
    case TD_SINGLE_HOLD: unregister_code(KC_LALT); break;
    case TD_DOUBLE_TAP: unregister_code(KC_ESC); break;
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
  }
  tap_state.state = TD_NONE;
}

void grv_keydown (tap_dance_state_t *state, void *user_data) {
 tap_state.state = current_dance(state);
  switch (tap_state.state) {
    case TD_SINGLE_TAP: register_code(KC_BSLS); break;
    case TD_SINGLE_HOLD: register_code(KC_RALT); break;
    case TD_DOUBLE_TAP: register_code(KC_GRV); break;
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
 }
};

void grv_keyup (tap_dance_state_t *state, void *user_data) {
  switch (tap_state.state) {
    case TD_SINGLE_TAP: unregister_code16(KC_BSLS); break;
    case TD_SINGLE_HOLD: unregister_mods(KC_RALT); break;
    case TD_DOUBLE_TAP: unregister_code(KC_GRV); break;
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
  }
  tap_state.state = TD_NONE;
}

void bck_keydown (tap_dance_state_t *state, void *user_data) {
 tap_state.state = current_dance(state);
  switch (tap_state.state) {
    case TD_SINGLE_TAP: register_code(KC_BSPC); break;
    case TD_SINGLE_HOLD: register_code(KC_LCTL); register_code(KC_BSPC); break;
    case TD_DOUBLE_TAP: register_code(KC_BSPC); unregister_code(KC_BSPC); register_code(KC_BSPC); break;
    case TD_DOUBLE_SINGLE_TAP: register_code(KC_BSPC); unregister_code(KC_BSPC); register_code(KC_BSPC); break;
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
 }
};

void bck_keyup (tap_dance_state_t *state, void *user_data) {
  switch (tap_state.state) {
    case TD_SINGLE_TAP: unregister_code(KC_BSPC); break;
    case TD_SINGLE_HOLD: unregister_code(KC_LCTL); unregister_code(KC_BSPC); break;
    case TD_DOUBLE_TAP: unregister_code(KC_BSPC); break;
    case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_BSPC); break;
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
  }
  tap_state.state = TD_NONE;
}

void qwe_keydown (tap_dance_state_t *state, void *user_data) {
 tap_state.state = current_dance(state);
  switch (tap_state.state) {
    case TD_SINGLE_TAP: layer_move(_QWERTY); break;
    case TD_SINGLE_HOLD: layer_move(_QWERTY); break;
    case TD_DOUBLE_TAP: layer_move(_QWERTY); break;
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
 }
};

void qwe_keyup (tap_dance_state_t *state, void *user_data) {
  switch (tap_state.state) {
    case TD_SINGLE_TAP: break;
    case TD_SINGLE_HOLD: layer_move(_MOUSE); break;
    case TD_DOUBLE_TAP: break;
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
  }
  tap_state.state = TD_NONE;
}

void sym_keydown (tap_dance_state_t *state, void *user_data) {
 tap_state.state = current_dance(state);
  switch (tap_state.state) {
    case TD_SINGLE_TAP: layer_move(_SYMBOL); break;
    case TD_SINGLE_HOLD: layer_move(_SYMBOL); break;
    case TD_DOUBLE_TAP: layer_move(_SYMBOL); break;
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
 }
};

void sym_keyup (tap_dance_state_t *state, void *user_data) {
  switch (tap_state.state) {
    case TD_SINGLE_TAP: break;
    case TD_SINGLE_HOLD: layer_move(_MOUSE); break;
    case TD_DOUBLE_TAP: break;
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
  }
  tap_state.state = TD_NONE;
}

void mou_keydown (tap_dance_state_t *state, void *user_data) {
 tap_state.state = current_dance(state);
  switch (tap_state.state) {
    case TD_SINGLE_TAP: layer_move(_MOUSE); break;
    case TD_SINGLE_HOLD: layer_move(_MOUSE); break;
    case TD_DOUBLE_TAP: layer_move(_MOUSE); break;
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
 }
};

void mou_keyup (tap_dance_state_t *state, void *user_data) {
  switch (tap_state.state) {
    case TD_SINGLE_TAP: break;
    case TD_SINGLE_HOLD: layer_move(_SYMBOL); break;
    case TD_DOUBLE_TAP: break;
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
  }
  tap_state.state = TD_NONE;
}

void gam_keydown (tap_dance_state_t *state, void *user_data) {
 tap_state.state = current_dance(state);
  switch (tap_state.state) {
    case TD_SINGLE_TAP: layer_move(_GAMES); break;
    case TD_SINGLE_HOLD: layer_move(_GAMES); break;
    case TD_DOUBLE_TAP: layer_move(_GAMES); break;
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
 }
};

void gam_keyup (tap_dance_state_t *state, void *user_data) {
  switch (tap_state.state) {
    case TD_SINGLE_TAP: break;
    case TD_SINGLE_HOLD: layer_move(_QWERTY); break;
    case TD_DOUBLE_TAP: break;
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
  }
  tap_state.state = TD_NONE;
}

void ste_keydown (tap_dance_state_t *state, void *user_data) {
 tap_state.state = current_dance(state);
  switch (tap_state.state) {
    case TD_SINGLE_TAP: layer_move(_STENO); break;
    case TD_SINGLE_HOLD: layer_move(_STENO); break;
    case TD_DOUBLE_TAP: layer_move(_STENO); break;
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
 }
};

void ste_keyup (tap_dance_state_t *state, void *user_data) {
  switch (tap_state.state) {
    case TD_SINGLE_TAP: break;
    case TD_SINGLE_HOLD: layer_move(_QWERTY); break;
    case TD_DOUBLE_TAP: break;
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
  }
  tap_state.state = TD_NONE;
}

// Defining an 'ACTION_TAP_DANCE_FN_ADVANCED()' function for each Tap Dance, passing in 'keydown' and 'keyup' functions to combine them into completed Tap Dances.
tap_dance_action_t tap_dance_actions[] = {
  [ESC_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, esc_keydown, esc_keyup),
  [GRV_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, grv_keydown, grv_keyup),
  [BCK_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, bck_keydown, bck_keyup),
  [QWE_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, qwe_keydown, qwe_keyup),
  [SYM_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sym_keydown, sym_keyup),
  [MOU_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, mou_keydown, mou_keyup),
  [GAM_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, gam_keydown, gam_keyup),
  [STE_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ste_keydown, ste_keyup)
};
