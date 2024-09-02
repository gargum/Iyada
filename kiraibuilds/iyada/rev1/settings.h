//This file exists for the sake of convenience, specifically in order to make creating user-generated keymaps with a large number of layers less difficult.

#include QMK_KEYBOARD_H

#if __has_include( "layers.h" ) && LAYER_MAP == yes
    #include "layers.h"
#endif

#if __has_include( "combos.def" ) && COMBO_MAP == yes
    #include "keyboards/gboards/g/keymap_combo.h"
#endif

#if __has_include( "tap_dance_map.c" ) && TAP_DANCE_MAP == yes
    #include <tap_dance_map.c>
#endif

#if DEFAULT_CONFIGURATIONS == yes
    #include "kiraibuilds/iyada/rev1/iyada_defaults.c"
#endif

#ifdef OS_DETECTION_ENABLE
    #include <os_detection.h>

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
