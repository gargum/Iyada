// This file exists for the sake of convenience, specifically to make adding and changing RGB light layers more straight-forward.

// QWERTY layer - RGB Colour Default
const rgblight_segment_t PROGMEM my_qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 30, HSV_WHITE}
);
// SYMBOL layer - RGB Colour Default
const rgblight_segment_t PROGMEM my_symbol_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 30, HSV_AZURE}
);
// MOUSE layer - RGB Colour Default
const rgblight_segment_t PROGMEM my_mouse_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 30, HSV_MAGENTA}
);
#ifdef JOYSTICK_ENABLE
// GAMES layer - RGB Colour Default
const rgblight_segment_t PROGMEM my_games_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 30, HSV_PURPLE}
);
#endif
#ifdef STENO_ENABLE
// STENO layer - RGB Colour Default
const rgblight_segment_t PROGMEM my_steno_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 30, HSV_CHARTREUSE}
);
#endif

// Collecting the previously defined layers via the use of a pointer
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_qwerty_layer,
    my_symbol_layer,
    my_mouse_layer
    #ifdef JOYSTICK_ENABLE
    ,
    my_games_layer
    #endif
    #ifdef STENO_ENABLE
    ,
    my_steno_layer
    #endif
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
    return state;
}

// Displaying the RGB colours at the appropriate times
layer_state_t layer_state_set_user(layer_state_t state) {

    rgblight_set_layer_state(1, layer_state_cmp(state, _SYMBOL));
    rgblight_set_layer_state(2, layer_state_cmp(state, _MOUSE));
    #ifdef JOYSTICK_ENABLE
    rgblight_set_layer_state(3, layer_state_cmp(state, _GAMES));
    #endif
    #ifdef STENO_ENABLE
    #ifndef JOYSTICK_ENABLE
    rgblight_set_layer_state(3, layer_state_cmp(state, _STENO));
    #endif
    #ifdef JOYSTICK_ENABLE
    rgblight_set_layer_state(4, layer_state_cmp(state, _STENO));
    #endif
    #endif
    return state;
}
