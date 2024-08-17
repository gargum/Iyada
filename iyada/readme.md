# Iyada

![Iyada]([imgur.com image replace me!](https://imgur.com/Xc4qR9p))

*The Iyada is a keyboard, mouse, space mouse, and a gamepad in one unit*

* Keyboard Maintainer: [Gareth Gummow](https://github.com/gargum)
* Hardware Supported: *2 Iyada top PCBs, 2 Iyada bottom PCBs, 2 Iyada base plates, 2 Iyada mounting rings, 2 Iyada Cirque holders, 2 RP2040 Pro Micro microcontrollers, 2 EC12 low profile rotary encoders, 2 EVQWGD001 scroll encoders, 2 OLEDs (32x128), 2 Cirque Pinnacle trackpads (40mm / TM040040 is recommended), 2 FPC 12-pin cables, 2 FPC reverse side solder-mount connectors, 100 Hotswap sockets (50 Choc & 50 MX, or 50 Choc & 50 Gateron), 30 WS2812B LEDs (WS2812B-2020 is recommended), 2 DRV2605L haptic drivers, 2 Haptic motors, 2 TP4056 lipo chargers, 2 lipo batteries, 6 SPDT switches, 2 TRRS connectors, 1 TRRS cable, 62 Diodes (62 1N4148 or 62 LL4148), 34 screws (M2.2), 2 heat-set inserts (M2.2), 16 M.2 SSD standoffs (All 16 must be the same height), Wires (30 Gauge), Solder (paste and/or wire), UV resin or hot glue or double-sided tape*
* Hardware Availability: [AliExpress](https://aliexpress.com), [Mouser](https://mouser.com), [DigiKey](https://digikey.com), [JLCPCB](https://jlcpcb.com), [PCBWay](https://pcbway.com)

Make example for this keyboard (after setting up your build environment):

    make kiraibuilds/iyada:default

Alternative make example for this keyboard using QMK:

    qmk compile -kb kiraibuilds/iyada -km default

Flashing example for this keyboard using QMK:

    qmk flash -kb kiraibuilds/iyada -km default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. 

Brand new to QMK? Start with the [Complete Newbs Guide](https://docs.qmk.fm/#/newbs)

## Bootloader

One can enter the bootloader of each keyboard half separately if one so chooses. This is necessary when flashing a newly constructed Iyada for the first time, and when one wishes to alter the default behaviours of the RGB LEDs.

One may also use a TRRS cable to connect both halves, before entering the bootloader on the master half alone. Flashing both halves simultaneously in this fashion is convenient when one is simply flashing a new keymap onto a pre-existing Iyada without making any other changes.

One is able to enter the bootloader in 5 ways:

* **Bootloader button**: First, unplug the Iyada from one's computer. Then, press and hold the button labelled 'Boot' on the front of the PCB, and keep it held down as one plugs the Iyada into the computer once more. This should cause the Iyada to enter the bootloader.
* **Reset button**: Simply double-tap the button labelled 'reset' on the front of the PCB. This should cause the Iyada to enter the bootloader.
* **Paperclip reset**: Take a screwdriver or paperclip, then use it to connect the RST and GND pins on the microcontroller. Please be careful, as one can accidentally short the MCU. By quickly doing this twice in a row, one is able to enter the bootloader using the reset button method without actually pressing the physical reset button.
* **Bootmagic reset**: Bootmagic is enabled by default. With Bootmagic, one can hold the top right key on the right half of the keyboard and plug it in. If using the left half by itself, or if holding the top right key on the right half of the board simply is not working, then instead hold the top left key on the left half of the keyboard.
* **Keycode in layout**: If one has included the keycode `QK_BOOT` somewhere in a custom keymap, then triggering it will enter the bootloader. This is unavailable on the default keymap.

## Additional Information

* **Cirque Sizing**: Although 40mm Cirque trackpads are recommended, one may use any size that one so desires. 40mm Cirque trackpads are used only because they are popularly considered to be the most comfortable variety. The only issue associated with using a smaller Cirque is that it may not be possible to attach these Cirques to the Iyada Cirque holders perfectly centred.
* **Cirque Holder**: UV resin is used to attach a Cirque to the Iyada Cirque holder. All 40mm Cirques have been confirmed to be able to attach to the standard Cirque holder regardless of the type of overlay it comes with. To attach a Cirque to the Iyada Cirque holder, it is recommended that one first attaches the Cirque holder to the Iyada top PCB using a heat-set insert and M2.2 screw, then connects the Cirque to the Iyada top PCB, before using something like hot glue or tape to test what position and orientation is most comfortable for use. After one is happy with the position and orientation, and after one is sure the Cirque has been connected to the Iyada top PCB properly, a very small amount of UV resin can then be used to permanently secure the trackpad to its holder. After this, the hot glue or tape may be removed. 
* **Curved Overlay**: All features including secondary click functions and scrolling functions work with the curved overlay, however the attenuation in config.h must be set to its maximum value of 1 for this to work consistently. It does still technically work if the attenuation is set to a value of 2, but in testing was reported as being frustrating to use.
* **Cirque Attenuation**: If one is not using the curved overlay, setting the attenuation in config.h to 3 or 4 generally works best. If one does have curved overlays on one's Cirque trackpads, then setting the attenuation to 1 or 2 generally works best.
* **Cirque Positioning**: It is recommended to mount each Cirque trackpad to the keyboard such that it is angled away from the MCU by an angle of between 20 degrees and 40 degrees. Mounting the Cirques perfectly straight tends to make it more difficult for one to use one's thumbs to control mouse pointing.
* **Cirque Conflicts**: It is worth noting that using the Steno and/or Joystick functionality may cause the Cirques to become less accurate, more prone to drifting, and overall more painful to use.
* **Cirque Problems**: If a Cirque trackpad is only partially connected, then the mouse pointer should jitter erratically when one attempts to use it. If SDA or SCL are not connected properly at all, then the Cirque trackpad will only be able to move in the X direction or in the Y direction but not both. If there is jittering in the X direction but not the Y direction, or vice versa, then either SDA or SCL is partially connected while the other is fully connected. If the Cirque drops user input periodically when the attenuation is set to 1, almost like stuttering or lagging, then 5V or GND are not properly connected. If the Cirque does not respond at all despite the correct solder jumpers being closed, then either that half is not receiving sufficient power, or the Cirque is not properly connected. To resolve every single one of these problems, use 3.3V Cirques, reconnect/resolder the Cirques, add the battery/charging accessories, and use either WS2812B-2020 LEDs or no LEDs at all before testing again. In case one simply removes a pad or trace by accident while adding a Cirque trackpad, each half of the keyboard has 3 places where it is possible to solder a Cirque alongside 2 places where an FPC connecter for a Cirque can be added. If none of this works, disconnect any LEDs and try using the Cirque. If it suddenly works fine, the problem was insufficient power. If nothing changes, the problem is the connection between the Cirque and the PCB.
* **Mounting Compatibility**: The internal tenting puck system is primarily for the purposes of attaching the Iyada to either a tripod, or of making it easier to secure the Iyada to an office chair. As the name implies, This also makes it possible to simply tent one's Iyada.
* **Haptic Compatibility**: The Iyada is designed to support all haptic feedback drivers that are compatible with QMK. By default, it is configured to use the DRV2605L, however the Iyada is also natively compatible with solenoid drivers if one would prefer to use that instead.
* **Audio**: The Iyada natively supports the use of piezo speakers for the purposes of audio feedback. Simply hand-wire one's speaker to the appropriately on each half of the Iyada in order to utilise this feature.
* **SPI Peripherals**: The Iyada supports direct control of SPI-based peripherals, including Cirque trackpads that have been configured to communicate via SPI. If one wants to use any such peripheral, simply hand-wire the appropriate connections the corresponding 4 pins located on the bottom of the MCU.
* **Power Draw**: If one uses two 5V Cirque trackpads in tandem with WS2812B-5050 LEDs, the battery and charging accessories are required to provide all components with sufficient power simultaneously. Neglecting to do so when using this configuration will result in the 5V Cirque present on the secondary half of the keyboard to become non-responsive. Even with the additional battery and charging accessories, it is possible that there will still be insufficient power if one is using an Iyada with two 5V Cirque trackpads, WS2812B-5050 LEDs, and additional non-standard peripherals connected via an SPI to I2C bus-bridge such as the SC18IS604.
* **Battery Connections**: The Iyada natively supports the use of a lipo battery on each half to help power more energy-intensive configurations. Simply solder the battery wires to the TP4056 units on each half, and position the battery so as to not block any of the Iyada's LEDs.
* **Dual Analogue Support**: The Iyada natively supports virtual dual analogue sticks. This means, using software such as a video game emulator, one is able to map each Cirque Pinnacle trackpad to its own
separate analogue stick for use in modern games. By default, flicking or swiping in a direction will toggle that direction, and tapping will reset it. This is to allow those with RSI or arthritis that prevents
one from holding down a standard analogue stick to use a dual analogue input method. As a side-effect, this method also frees up one's thumbs, better allowing one to use gamepad buttons mapped to the thumb cluster.
