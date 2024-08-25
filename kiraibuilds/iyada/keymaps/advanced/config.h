/* Copyright 2024 Gareth Gummow <ggummow@uwaterloo.ca> (@gargum)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// Setting which half is master
    #define EE_HANDS

// Setting behaviour for Tap Dance
    #define TAPPING_TERM 185
    #define TAPPING_TOGGLE 1

// Pointer (Cirque Pinnacle) initialization settings
    #define CIRQUE_PINNACLE_TAP_ENABLE
    #define CIRQUE_PINNACLE_CIRCULAR_SCROLL_ENABLE

// RGB initialization settings
    #define RGBLIGHT_LAYERS
// Removing unused RGB animations
    #undef RGBLIGHT_EFFECT_RAINBOW_MOOD
    #undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #undef RGBLIGHT_EFFECT_SNAKE
    #undef RGBLIGHT_EFFECT_KNIGHT
    #undef RGBLIGHT_EFFECT_CHRISTMAS
    #undef RGBLIGHT_EFFECT_STATIC_GRADIENT
    #undef RGBLIGHT_EFFECT_RGB_TEST
    #undef RGBLIGHT_EFFECT_ALTERNATING
    #undef RGBLIGHT_EFFECT_TWINKLE

// Haptic feedback behaviour settings - Vibrations
    #define DRV2605L_GREETING 82
    #define DRV2605L_DEFAULT_MODE 7
//  #define NO_HAPTIC_MOD
    #define NO_HAPTIC_ALPHA
    #define NO_HAPTIC_PUNCTUATION
    #define NO_HAPTIC_LOCKKEYS
    #define NO_HAPTIC_NAV
    #define NO_HAPTIC_NUMERIC

// Audio feedback behaviour settings - Default sounds
    #define AUDIO_ON_SONG SONG(PLOVER_SOUND)
    #define AUDIO_OFF_SONG SONG(PLOVER_GOODBYE_SOUND)
