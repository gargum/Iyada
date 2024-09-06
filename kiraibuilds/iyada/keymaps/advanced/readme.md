# Advanced Iyada Layout - Text Explanation & Walkthrough

The advanced layout exists to showcase as many of the existing features
of the Iyada as possible, while at the same time still remaining accessible
to those who are new to QMK. Learning this keymap should help beginners 
become acquainted with concepts including Layers, Combos, and Tap Dance, 
without being too confusing or overwhelming for novices.

Each half of the keyboard has a small OLED screen. These screens are 
there to provide information to the user regarding the current state of 
the keyboard, including which layer the keyboard is currently in, and even
whether problems with keyboard output are being caused by one's system being
unresponsive, or whether the problem is instead to do with the keyboard.

The primary layer, labelled 'main' on the secondary OLED display, outputs
letters using a standard QWERTY keymap.

The secondary layer, labelled 'symbol' on the secondary OLED display, allows
the user to press the Function keys F1-F12, the digits 0-9, and all shifted
variants of the ten digits such as the exclamation point and the dollar sign.
To enter this layer, simply press the corresponding Layer shift key located on
the lefthand thumb cluster.

The third layer, labelled 'mouse' on the secondary OLED display, allows the
user to control mouse movements, more easily reach arrow keys, and even change 
keyboard settings. Available settings on this layer include changing the behaviour 
of the LEDs, changing the behaviour of the haptic feedback module, and adjusting 
one's mouse sensitivity. To enter this settings layer, simply press the corresponding
Layer shift key located on the righthand thumb cluster.

On each half of the keyboard are a rotary encoder and a scroll encoder. 

On any layer, the lefthand rotary encoder can be turned to turn the system 
volume up or down. Pressing down on the lefthand rotary encoder will mute and 
unmute the system.

On any layer, the righthand rotary encoder can be turned to go to the next or
to the previous tab in Chromium-based web browsers like Chrome and Vivaldi. 
Pressing down on the righthand rotary encoder will pause or unpause media.

On any layer, the lefthand scroll encoder can be used to scroll up and down,
just as one would do with a standard mouse wheel. Pressing down on this 
scroll encoder will trigger the back button on any web browser, assisting
with web navigation.

On any layer, the righthand scroll encoder can be used to scroll side to side,
which may come in handy for some applications. Pressing down on this scroll
encoder will trigger the forward button on any web browser, again assisting
with web navigation.

Pressing both Layer shift keys simultaneously will toggle a fourth layer,
labelled 'Game' on the secondary OLED display. This layer transforms the
Iyada into a gamepad, with each Cirque Pinnacle trackpad functioning as
its own analogue stick and the face buttons also being remapped appropriately
to gamepad buttons.

On each layer, the six thumb keys, the leftmost column of three keys, and the
rightmost column of three keys will always be the same, although they are
deactivated when one is using the Game layer.

The lefthand cluster of three thumb keys, in order from left to right, 
correspond to Space, Backspace, and Symbols layer key. These keys function
normally with the exception of the Backspace key, which registers as a normal
Backspace key when tapped but outputs Ctrl+Backspace when held down.

The righthand cluster of three thumb keys, in order from left to right,
correspond to the Mouse layer toggle, Enter, and Shift respectively. No
special functions have been mapped to the Enter or Shift key. In this keymap,
Shift corresponds to the Left Shift key, and Right Shift is entirely absent.

The key on the outer bottom corners of each keyboard half are called Space
Cadet keys. When held, they correspond to the Ctrl key. When tapped, they
correspond to the left and right brackets, ( and ). 

The keys just above the Space Cadet keys function similarly. When held, they
correspond to the left and right Windows keys respectively. When tapped, the
lefthand key corresponds to the Delete key, when the righthand key outputs
the apostrophe key, with the appropriate behaviour when Shift is also held.

Finally, at the top left and top right corners of the keyboard are keys with
three different functions known as Tap Dance keys. 
When the topmost leftmost key is tapped, it outputs the Tab key.
When this key is held, it outputs the Left Alt key.
When this key is quickly double-tapped, it outputs the Escape key.

When the topmost rightmost key is tapped, it outputs a Backslash.
When this key is held, it outputs the Right Alt key.
When this key is quickly double-tapped, it outputs the Grave key.

This layout is recommended for those who have not previously owned a custom
mechanical keyboard, and for those who have not previously used a keyboard
that includes a built-in trackball or touchpad.

# Default Iyada Layout - Diagrams & Legend

<tt>

                                  MAIN LAYER

    ,---,---,---,---,---,---,                          ,---,---,---,---,---,---,
    |ESC| Q | W | E | R | T |---,                  ,---| Y | U | I | O | P | \ |
    '---'---'---'---'---'---| [ |                  | ] |---'---'---'---'---'---'
    |DEL| A | S | D | F | G '---'                  '---' H | J | K | L | ; | ' |
    '---'---'---'---'---'---| - |                  | = |---'---'---'---'---'---'
    |CTL| Z | X | C | V | B '---'                  '---' N | M | , | . | / |CTL|
    '---'---'---'---'---'---'                          '---'---'---'---'---'---'
      | V | < |            (EC1)(EC2)          (EC3)(EC4)            | > | ^ |
      '---'---'         ,---,---,---,          ,---,---,---,         '---'---'
                        |SPC|BCK|LSY|          |LMO|ENT|SFT|
                        '---'---'---'          '---'---'---'


                                     SYMBOL LAYER

    ,---,---,---,---,---,---,                          ,---,---,---,---,---,---,
    |ESC|F1 |F2 |F3 |F4 |F5 |---,                  ,---|F8 |F9 |F10|F11|F12| \ |
    '---'---'---'---'---'---|F6 |                  |F7 |---'---'---'---'---'---'
    |DEL| 1 | 2 | 3 | 4 | 5 '---'                  '---' 6 | 7 | 8 | 9 | 0 | ' |
    '---'---'---'---'---'---| - |                  | = |---'---'---'---'---'---'
    |CTL| ! | @ | # | $ | % '---'                  '---' ^ | & | * | . | ? |CTL|
    '---'---'---'---'---'---'                          '---'---'---'---'---'---'
      | V | < |            (EC1)(EC2)          (EC3)(EC4)            | > | ^ |
      '---'---'         ,---,---,---,          ,---,---,---,         '---'---'
                        |SPC|BCK|LMA|          |LMO|ENT|SFT|
                        '---'---'---'          '---'---'---'


                                     MOUSE LAYER

    ,---,---,---,---,---,---,                          ,---,---,---,---,---,---,
    |ESC|LVD|CWT|MSU|AST|REC|---,                  ,---|AC0|MS1| ^ |MS2|LVI| \ |
    '---'---'---'---'---'---|DTU|                  |DTD|---'---'---'---'---'---'
    |DEL|RGB|MSL|MSD|MSR|STP'---'                  '---'AC1| < | V | > |AUD| ' |
    '---'---'---'---'---'---| - |                  | = |---'---'---'---'---'---'
    |CTL|PRV|HDN|HTG|AON|PLY'---'                  '---'AC2|AOF|HRS|HUP|NXT|CTL|
    '---'---'---'---'---'---'                          '---'---'---'---'---'---'
      | V | < |            (EC1)(EC2)          (EC3)(EC4)            | > | ^ |
      '---'---'         ,---,---,---,          ,---,---,---,         '---'---'
                        |SPC|BCK|LPR|          |LPR|ENT|SFT|
                        '---'---'---'          '---'---'---'


                                     GAME LAYER

    ,---,---,---,---,---,---,                          ,---,---,---,---,---,---,
    |HOM|   |   |L2 |L1 |L3 |---,                  ,---|R3 |R1 |R2 |   |   |LPR|
    '---'---'---'---'---'---|SEL|                  |STA|---'---'---'---'---'---'
    |   |L1 |L2 |R2 |R1 |DUP'---'                  '---'DDN|CRO|CIR|SQU|TRI|   |
    '---'---'---'---'---'---|   |                  |   |---'---'---'---'---'---'
    |   |PRV|HDN|HTG|   |DLT'---'                  '---'DRT|   |HRS|HUP|NXT|   |
    '---'---'---'---'---'---'                          '---'---'---'---'---'---'
      |SEL|SEL|            (EC1)(EC2)          (EC3)(EC4)            |STA|STA|
      '---'---'         ,---,---,---,          ,---,---,---,         '---'---'
                        |L1 |L2 |L3 |          |R3 |R2 |R1 |
                        '---'---'---'          '---'---'---'


                                     STENO LAYER

    ,---,---,---,---,---,---,                          ,---,---,---,---,---,---,
    | 1 | 2 | 3 | 4 | 5 | 6 |---,                  ,---| 7 | 8 | 9 | A | B | C |
    '---'---'---'---'---'---|RES|                  |RES|---'---'---'---'---'---'
    |FN1| S | T | P | H | * '---'                  '---' * | F | P | L | T | D |
    '---'---'---'---'---'---|FN1|                  |FN2|---'---'---'---'---'---'
    |FN2| S | K | W | R | * '---'                  '---' * | R | B | G | S | Z |
    '---'---'---'---'---'---'                          '---'---'---'---'---'---'
      | * | * |            (EC1)(EC2)          (EC3)(EC4)            | * | * |
      '---'---'         ,---,---,---,          ,---,---,---,         '---'---'
                        | A | O | * |          | * | E | U |
                        '---'---'---'          '---'---'---'

                        
  
   ,---,  - Tap:               Tab key
   |ESC|  - Hold:              Left Alt key
   '---'  - Double-tap:        Escape key
 
   ,---,  - Tap:               Delete key
   |DEL|  - Hold:              Left GUI/OS key
   '---'

   ,---,  - Tap (Left Side):   Left parenthesis - (
   |CTL|  - Hold (Left Side):  Left Control key
   '---'

   ,---,  - Tap:               Backslash key - \
   | \ |  - Hold:              Right Alt key
   '---'  - Double-tap:        Grave key - '

   ,---,  - Tap:               Apostrophe/Quote key - '
   | ' |  - Hold:              Right GUI/OS key
   '---'

   ,---,  - Tap (Right Side):  Right parenthesis - )
   |CTL|  - Hold (Right Side): Right Control key
   '---'

   ,---,  - Tap:               Backspace key
   |BCK|  - Hold:              Control + Backspace key
   '---'

   ,---,  - Tap:               Browser - Back Button
   |EC1|  - Scroll Up:         Mouse Wheel - Up
   '---'  - Scroll Down:       Mouse Wheel - Down

   ,---,  - Tap:               Mute / Unmute
   |EC2|  - Scroll Left:       Volume Down
   '---'  - Scroll Right:      Volume Up

   ,---,  - Tap:               Media - Play / Pause
   |EC3|  - Scroll Left:       Browser - Tab Left
   '---'  - Scroll Right:      Browser - Tab Right

   ,---,  - Tap:               Browser - Forward Button
   |EC4|  - Scroll Up:         Mouse Wheel - Right
   '---'  - Scroll Down:       Mouse Wheel - Left

   ,---,  - Tap:               Enter Symbol Layer - Toggle on/off
   |LSY|  - Hold:              Enter Symbol Layer - Only while held
   '---'

   ,---,  - Tap:               Enter Mouse Layer - Toggle on/off
   |LMO|  - Hold:              Enter Mouse Layer - Only while held
   '---'

   ,---,  - Tap:               Enter Main Layer - Toggle on/off
   |LMA|  - Hold:              Enter Main Layer - Only while held
   '---'

   ,---,  - Tap:               Enter Previous Layer - Toggle
   |LPR|  - Hold:              Enter Previous Layer - Only while held
   '---'

   ,---, 
   |PRV|  - Tap or Hold:       Haptic feedback modules - Previous waveform
   '---'

   ,---, 
   |HDN|  - Tap or Hold:       Haptic feedback modules - Decrease strength
   '---'

   ,---, 
   |HTG|  - Tap or Hold:       Haptic feedback modules - Toggle on/off
   '---'

   ,---, 
   |HRS|  - Tap or Hold:       Haptic feedback modules - Reset waveform and strength to default
   '---'

   ,---, 
   |HUP|  - Tap or Hold:       Haptic feedback modules - Increase strength
   '---'

   ,---,
   |NXT|  - Tap or Hold:       Haptic feedback modules - Next waveform
   '---'

   ,---, 
   |RGB|  - Tap or Hold:       LED Lighting - Toggle on/off
   '---'

   ,---, 
   |LVI|  - Tap or Hold:       LED Value (Brightness) - Increase value
   '---'

   ,---,
   |LVD|  - Tap or Hold:       LED Value (Brightness) - Decrease value
   '---'

   ,---, 
   |DTU|  - Tap or Hold:       Dynamic Tapping Term - Increase value - This feature is disabled by default
   '---'

   ,---, 
   |DTD|  - Tap or Hold:       Dynamic Tapping Term - Decrease value - This feature is disabled by default
   '---'

   ,---, 
   |CWT|  - Tap or Hold:       Caps Word - Toggle on/off
   '---'

   ,---, 
   |AON|  - Tap or Hold:       Autocorrect - Turn on
   '---'

   ,---, 
   |AOF|  - Tap or Hold:       Autocorrect - Turn off
   '---'

   ,---, 
   |AUD|  - Tap or Hold:       PWM speakers - Toggle on/off
   '---'

   ,---, 
   |REC|  - Tap or Hold:       Begin recording a Dynamic Macro - This feature is disabled by default
   '---'

   ,---, 
   |STP|  - Tap or Hold:       Stop recording a Dynamic Macro - This feature is disabled by default
   '---'

   ,---,
   |PLY|  - Tap or Hold:       Play one's previously recorded Dynamic Macro - This feature is disabled by default
   '---'

   ,---, 
   |AC0|  - Tap or Hold:       Adjust the mouse acceleration or DPI to its lowest setting
   '---'

   ,---, 
   |AC1|  - Tap or Hold:       Adjust the mouse acceleration or DPI to its medium setting
   '---'

   ,---, 
   |AC2|  - Tap or Hold:       Adjust the mouse acceleration or DPI to its highest setting
   '---'

   ,---,
   |MS1|  - Tap or Hold:       Left-click, also known as Mouse Button 1
   '---'

   ,---,
   |MS2|  - Tap or Hold:       Right-click, also known as Mouse Button 2
   '---'

   ,---,
   |MSD|  - Tap or Hold:       Move the mouse cursor downwards
   '---'

   ,---,
   |MSU|  - Tap or Hold:       Move the mouse cursor upwards
   '---'

   ,---,
   |MSL|  - Tap or Hold:       Move the mouse cursor to the left
   '---'

   ,---,
   |MSR|  - Tap or Hold:       Move the mouse cursor to the right
   '---'

   ,---,
   |STA|  - Tap or Hold:       Press the Start button - Joystick
   '---'

   ,---,
   |SEL|  - Tap or Hold:       Press the Select button - Joystick
   '---'

   ,---,
   |HOM|  - Tap or Hold:       Press the Home button - Joystick
   '---'

   ,---,
   |DUP|  - Tap or Hold:       Press Up on the D-Pad - Joystick
   '---'

   ,---,
   |DDN|  - Tap or Hold:       Press Down on the D-Pad - Joystick
   '---'

   ,---,
   |DLT|  - Tap or Hold:       Press Left on the D-Pad - Joystick
   '---'

   ,---,
   |DRT|  - Tap or Hold:       Press Right on the D-Pad - Joystick
   '---'

   ,---,
   |CRO|  - Tap or Hold:       Press the Cross or 'X' button - Joystick
   '---'

   ,---,
   |CIR|  - Tap or Hold:       Press the Circle or 'O' button - Joystick
   '---'

   ,---,
   |SQU|  - Tap or Hold:       Press the Square button - Joystick
   '---'

   ,---,
   |TRI|  - Tap or Hold:       Press the Triangle button - Joystick
   '---'

   ,---,
   |L1 |  - Tap or Hold:       Press the L1 button - Joystick
   '---'

   ,---,
   |L2 |  - Tap or Hold:       Press the L2 button - Joystick
   '---'

   ,---,
   |L3 |  - Tap or Hold:       Press the L3 button - Joystick
   '---'

   ,---,
   |R1 |  - Tap or Hold:       Press the R1 button - Joystick
   '---'

   ,---,
   |R2 |  - Tap or Hold:       Press the R2 button - Joystick
   '---'

   ,---,
   |R3 |  - Tap or Hold:       Press the R3 button - Joystick
   '---'

</tt>

