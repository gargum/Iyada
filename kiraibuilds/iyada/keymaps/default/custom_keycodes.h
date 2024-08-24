// Remember, never put sensitive information like a password into this file!

//Layer shift button keycodes - Used to make keymap.c files look tidier
    #define TT_SYM TT(_SYMBOL)
    #define TT_MOU TT(_MOUSE)
    #define TT_GAM TT(_GAMES)
    #define TT_STE TT(_STENO)
    #define TT_QWE TT(_QWERTY)
    
//Button combination keycodes - Used for the sake of convenience
    #define GUI_DEL GUI_T(KC_DEL)
    #define GUI_QUO RGUI_T(KC_QUOT)
    #define KC_TABL LCTL(KC_PGUP)
    #define KC_TABR LCTL(KC_PGDN)
    
//Tap Dance trigger keycodes - Used to save space in keymap.c files
    #define TD_ESC TD(ESC_DANCE)
    #define TD_GRV TD(GRV_DANCE)
    #define TD_BCK TD(BCK_DANCE)
    #define TD_QWE TD(QWE_DANCE)
    #define TD_SYM TD(SYM_DANCE)
    #define TD_MOU TD(MOU_DANCE)
    #define TD_GAM TD(GAM_DANCE)
    #define TD_STE TD(STE_DANCE)

//Joystick button keycodes - Simplified, more easily understood namings
    #define GC_DPU JS_18
	#define GC_DPD JS_16
	#define GC_DPL JS_15
	#define GC_DPR JS_17
	#define GC_SQU JS_0
	#define GC_CRO JS_1
	#define GC_CIR JS_2
	#define GC_TRI JS_3
	#define GC_L1 JS_4
	#define GC_L2 JS_5
	#define GC_L3 JS_6
	#define GC_R1 JS_7
	#define GC_R2 JS_8
	#define GC_R3 JS_9
	#define GC_STA JS_10
	#define GC_SEL JS_11
	#define GC_HOM JS_12
