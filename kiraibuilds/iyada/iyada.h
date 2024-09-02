/* 
* This file exists to make code in keymap.c files cleaner and more readable.
* The file may also be used to allow users to create and define a custom LED matrix or RGB matrix for the Iyada using a non-standard style of LED.
*/

#pragma once

    #include "quantum.h"
    #include <stdint.h>
    #include <stdbool.h>
    
#if __has_include( <iyada/rev1/custom_keycodes.c> ) && CUSTOM_CODES == yes
    #include <iyada/rev1/custom_keycodes.c>
#endif

void init_iyada(void);
