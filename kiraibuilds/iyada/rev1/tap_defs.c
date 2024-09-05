// This file is used to define all of the subtypes of tap available for use in user-defined Tap Dances
// This file exists to make the process of creating and customizing Tap Dances more user-friendly.

// Enumerating the different types of button press (single tap, double tap, etc)
typedef enum presses {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP,
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD,
    TD_TRIPLE_SINGLE_TAP
} td_state_t;

// Creating a system to detect keydown and keyup events
typedef struct {
bool is_press_action;
td_state_t state;
} td_tap_t;

// Tap dance function declarations - Current Dance
td_state_t current_dance (tap_dance_state_t *state); 

// Converting the subtype of tap event that has been detected into a number
td_state_t current_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }
    if (state->count == 3) {
        if (state->interrupted) return TD_TRIPLE_SINGLE_TAP;
        else if (state->pressed) return TD_TRIPLE_HOLD;
        else return TD_TRIPLE_TAP;
    } else return TD_UNKNOWN;
}

//initialise an instance of 'tap' for the tap dances.
static td_tap_t tap_state = {
  .is_press_action = true,
  .state = TD_NONE
};
