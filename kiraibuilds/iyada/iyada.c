/*
* This file exists to facilitate the use of a speaker shutdown pin, thereby preventing noise when the speaker is not in use.
*/

#include QMK_KEYBOARD_H
#include <iyada.h>
#include <ch.h>
#include <hal.h>

// Audio shutdown pin - Initialization
#ifdef AUDIO_ENABLE
void keyboard_pre_init_kb(void) {
    // ensure pin is set and enabled pre-audio init
    setPinOutput(SPEAKER_SHUTDOWN);
    writePinHigh(SPEAKER_SHUTDOWN);
    keyboard_pre_init_user();
}

void keyboard_post_init_kb(void) {
    // set pin based on active status
    writePin(SPEAKER_SHUTDOWN, audio_is_on());
    keyboard_post_init_user();
}

void audio_on_user(void) {
    writePinHigh(SPEAKER_SHUTDOWN);
}

void audio_off_user(void) {
    // needs a delay or it runs right after play note.
    wait_ms(200);
    writePinLow(SPEAKER_SHUTDOWN);
}
#endif
