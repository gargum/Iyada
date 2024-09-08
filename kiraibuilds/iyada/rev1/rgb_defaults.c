#include QMK_KEYBOARD_H
#include "keyboard.h"

#if __has_include( "layers.h" ) && defined(LAYER_MAP)
    #include "layers.h"
#endif

#ifdef AUDIO_ENABLE
    #include "song_list.h"
#endif

//Audio - Parsing songs already available in QMK itself into their own variables
#ifdef AUDIO_ENABLE
float qwe_song[][2] = SONG(TERMINAL_SOUND);
float sym_song[][2] = SONG(UNICODE_WINDOWS);
float mou_song[][2] = SONG(UNICODE_LINUX);
float gam_song[][2] = SONG(AUDIO_ON_SOUND);
float ste_song[][2] = SONG(QWERTY_SOUND);
#endif

//Layers - Detecting the current active layer, then responding accordingly
layer_state_t layer_state_set_kb(layer_state_t state) {
    switch (get_highest_layer(state)) {
    #ifdef _SYMBOL
        case _SYMBOL:
            rgblight_sethsv(125, 255, 160); /* RGB - TEAL */
        
        #ifdef AUDIO_ENABLE
            PLAY_SONG(sym_song);
        #endif
            break;
    #endif
    #ifdef _SYM
        case _SYM:
            rgblight_sethsv(125, 255, 160); /* RGB - TEAL */
        
        #ifdef AUDIO_ENABLE
            PLAY_SONG(sym_song);
        #endif
            break;
    #endif
    #ifdef _LOWER
        case _LOWER:
            rgblight_sethsv(125, 255, 160); /* RGB - TEAL */
            
        #ifdef AUDIO_ENABLE
            PLAY_SONG(sym_song);
        #endif
            break;
    #endif
    #ifdef _MOUSE
        case _MOUSE:
            rgblight_sethsv(183, 255, 255); /* RGB - PURPLE */ 
            
        #ifdef AUDIO_ENABLE
            PLAY_SONG(mou_song);
        #endif
            break;
    #endif
    #ifdef _MOU
        case _MOU:
            rgblight_sethsv(183, 255, 255); /* RGB - PURPLE */ 
            
        #ifdef AUDIO_ENABLE
            PLAY_SONG(mou_song);
        #endif
            break;
    #endif
    #ifdef _RAISE
        case _RAISE:
            rgblight_sethsv(183, 255, 255); /* RGB - PURPLE */ 
            
        #ifdef AUDIO_ENABLE
            PLAY_SONG(mou_song);
        #endif
            break;
    #endif
    #ifdef _GAMES
        case _GAMES:
            rgblight_sethsv(160, 255, 255); /* RGB - BLUE */
            
         #ifdef AUDIO_ENABLE
            PLAY_SONG(gam_song);
         #endif
            break;
    #endif
    #ifdef _GAM
        case _GAM:
            rgblight_sethsv(160, 255, 255); /* RGB - BLUE */
            
        #ifdef AUDIO_ENABLE
            PLAY_SONG(gam_song);
        #endif
            break;
    #endif
    #ifdef _ADJUST
        case _ADJUST:
            rgblight_sethsv(160, 255, 255); /* RGB - BLUE */
            
        #ifdef AUDIO_ENABLE
            PLAY_SONG(gam_song);
        #endif
            break;
    #endif
    #ifdef _STENO
        case _STENO:
            rgblight_sethsv(85, 255, 255);  /* RGB - GREEN */
            
        #ifdef AUDIO_ENABLE
            PLAY_SONG(ste_song);
        #endif
            break;
    #endif
    #ifdef _STE
        case _STE:
            rgblight_sethsv(85, 255, 255);  /* RGB - GREEN */
            
        #ifdef AUDIO_ENABLE
            PLAY_SONG(ste_song);
        #endif
            break;
    #endif
    #ifdef _PLOVER
        case _PLOVER:
            rgblight_sethsv(85, 255, 255);  /* RGB - GREEN */
        
        #ifdef AUDIO_ENABLE
            PLAY_SONG(ste_song);
        #endif
            break;
    #endif
    #ifdef _MAIN
        case _MAIN:
            rgblight_sethsv(150, 30, 255);  /* RGB - AZURE */
            
        #ifdef AUDIO_ENABLE
            PLAY_SONG(ste_song);
        #endif
            break;
    #endif
    #ifdef _QWERTY
        case _QWERTY:
            rgblight_sethsv(150, 30, 255);  /* RGB - AZURE */
            
        #ifdef AUDIO_ENABLE
            PLAY_SONG(qwe_song);
        #endif
            break;
    #endif
        default: // Primary/default layer
            rgblight_sethsv(150, 30, 255);  /* RGB - AZURE */
            
            #ifdef AUDIO_ENABLE
                PLAY_SONG(qwe_song);
            #endif
            break;
    }
  return state;
}
