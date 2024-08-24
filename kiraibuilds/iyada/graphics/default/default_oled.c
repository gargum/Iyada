// This file exists for the sake of convenience, specifically to make adding and changing OLED graphics more straight-forward.

#include <hal.h>
#include <string.h>
#include <ctype.h>
#include <printf.h>

#include "iyada_frame_0.h"
#include "iyada_frame_1.h"
#include "iyada_frame_2.h"
#include "main_graphic.h"
#include "symbol_graphic.h"
#include "mouse_graphic.h"
#include "game_graphic.h"
#include "plover_graphic.h"

#define FRAME_DURATION 333
#define LOGO_INTERVAL 20000
#define GLITCH_INTERVAL 21998

uint8_t current_frame = 0;

static void render_logo(void);
static void render_animation(void);

static void render_logo(void) {

    uint32_t utime = 0;
    
   if (timer_elapsed(utime) < LOGO_INTERVAL) {
       utime = timer_read();
       oled_write_raw_P(iyada_logo_0, iyada_logo_0_length);    
    } else {
       render_animation();
    }
}


static void render_main(void) {
    oled_write_raw_P(main_logo, main_logo_length);
}

static void render_symbol(void) {
    oled_write_raw_P(symbol_logo, symbol_logo_length);
}

static void render_mouse(void) {
    oled_write_raw_P(mouse_logo, mouse_logo_length);
}
#ifdef JOYSTICK_ENABLE
static void render_games(void) {
    oled_write_raw_P(mouse_logo, mouse_logo_length);
}
#endif

#ifdef STENO_ENABLE
static void render_steno(void) {
    oled_write_raw_P(plover_logo, plover_logo_length);
}
#endif
static void render_animation(void) {

    uint32_t timer = 0;
    
    static const char* bitmap_allArray[3] = {
        iyada_logo_0,
        iyada_logo_1,
        iyada_logo_2
    };
    
    uint16_t frame_sizes[3] = {
        iyada_logo_0_length,
        iyada_logo_1_length,
        iyada_logo_2_length
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
