//This file exists for the sake of convenience, specifically in order to make creating user-generated keymaps with multiple layers less difficult.

#include QMK_KEYBOARD_H

// Keymap Layer Declarations
//
#define _QWERTY 0
#define _SYMBOL 1
#define _MOUSE 2
#ifdef JOYSTICK_ENABLE
#define _GAMES 3
#ifdef STENO_ENABLE
#define _STENO 4
#endif
#endif
#ifndef JOYSTICK_ENABLE
#ifdef STENO_ENABLE
#define _STENO 3
#endif
#endif
