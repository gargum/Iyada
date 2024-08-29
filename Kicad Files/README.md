# Iyada PCB

![Iyada](https://raw.githubusercontent.com/gargum/Iyada/main/photos/iyada_pcb.jpg)

*The Iyada comes in four parts - Top Left, Bottom Left, Top Right, and Bottom Right*

All PCBs used are reversible. This means a bottom PCB will function as both a bottom left and as a bottom right half, while a top PCB will function as both a top left and top right half.

## PCB Fabrication

The iyada_top and iyada_bottom directories each contain a .zip file, iyada_top.zip and iyada_bottom.zip respectively.

To fabricate the Iyada, simply take these .zip files, go to a website such as [JLCPCB](jlcpcb.com/) or [PCBWay](pcbway.com/), and upload them when prompted to provide a gerber file.

## Features

* **Reversible PCBs**: As previously mentioned, all PCBs are reversible, so only the top PCB functions as the top half of both sides, and the bottom PCB functions as the bottom half of both sides.
* **Simultaneous Choc & MX Hotswap Support**: Each key simultaneously accomodates Choc and MX hotswaps. This is to allow every key to accept a low-profile Choc switch, or a standard MX switch, without the need to resolder anything or reflash any firmware.
* **Two Rotary Encoders**: Each top PCB has a reversible slot for either an EC11 or EC12 rotary encoder, complete with intact click functionality!
* **Two Scroll Encoders**: Each top PCB has a reversible slot for a EVQWGD001 scroll encoder, also complete with intact click functionality!
* **Support for Multiple Sizes of LED**: The bottom PCB is designed to accomodate WS2812 RGB LEDs in multiple sizes, including WS2812 RGB LEDs cut from RGB LED strips!
* **TP4056 Slot**: Features like large LEDs and haptic feedback can take quite a lot of power. That's why the bottom PCB has a dedicated slot for a TP4056, which is used to safely provide more than enough additional electricity!
