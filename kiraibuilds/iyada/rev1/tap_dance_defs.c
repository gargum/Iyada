// This file exists for the sake of convenience, and to make the keymap.c file(s) more readable and more easily edited.
//
// Remember, never put sensitive information like a password into this file!

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

// Tap dance function declarations
td_state_t cur_dance (tap_dance_state_t *state); 

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
static td_tap_t tap_state = {
  .is_press_action = true,
  .state = TD_NONE
};
