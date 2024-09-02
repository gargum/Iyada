//This file exists to allow keymaps to dynamically include or exclude various additional files based on rules.mk settings

#include QMK_KEYBOARD_H

//Layer Maps - Allows the user to define their layers in a separate file called layers.h
//Layer Maps are useful if you wish to have various files and features reference one's keymap layers.
#if __has_include( "layers.h" ) && LAYER_MAP == yes
    #include "layers.h"
#endif

//Combo Maps - Allows the user to dynamically include or exclude a combos.def file without having to add or remove the associated #include line from keymap.c
#if __has_include( "combos.def" ) && COMBO_MAP == yes
    #include "keyboards/gboards/g/keymap_combo.h"
#endif

//Tap Dance Maps - Allows the user to define Tap Dance functions in a separate file, making them easier to understand and easier to edit as a result.
#if __has_include( "tap_dance_map.c" ) && TAP_DANCE_MAP == yes
    #include <tap_dance_map.c>
#endif

//Default Configurations - Allows the user to choose whether or not to include default settings like the Cirque joysticks and RGB layering
#if DEFAULT_CONFIGURATIONS == yes
    #include "kiraibuilds/iyada/rev1/iyada_defaults.c"
#endif

//OS Detection - This is being used for the dynamic power draw code
#ifdef OS_DETECTION_ENABLE
    #include <os_detection.h>

/* Dynamic power draw:
*
*  When the keyboard boots, it draws little enough power to work across all platforms including iOS.
*  When the keyboard detects the Operating System of the system it has been plugged into, it changes its own maximum power draw
*  Power draw is left as-is if needed, but is increased as much as possible otherwise
*
*  NOTE - Mac OS has been given lower power consumption than Windows and Linux to ensure the Iyada plays nicely with Macbook laptops
*/
bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }
    switch (detected_os) {
        case OS_UNSURE:
                #undef USB_MAX_POWER_CONSUMPTION
                #define USB_MAX_POWER_CONSUMPTION USB_CONFIG_POWER_MA(100)
            break;
        case OS_IOS:
                #undef USB_MAX_POWER_CONSUMPTION
                #define USB_MAX_POWER_CONSUMPTION USB_CONFIG_POWER_MA(100)
            break;
        case OS_MACOS:
                #undef USB_MAX_POWER_CONSUMPTION
                #define USB_MAX_POWER_CONSUMPTION USB_CONFIG_POWER_MA(400)
            break;
        case OS_WINDOWS:
                #undef USB_MAX_POWER_CONSUMPTION
                #define USB_MAX_POWER_CONSUMPTION USB_CONFIG_POWER_MA(950)
            break;
        case OS_LINUX:
                #undef USB_MAX_POWER_CONSUMPTION
                #define USB_MAX_POWER_CONSUMPTION USB_CONFIG_POWER_MA(950)
            break;
    }
    
    return true;
}
#endif
