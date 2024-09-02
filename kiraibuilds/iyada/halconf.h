/*
 * This file exists to configure features of HAL/ChibiOS, like expanded serial buffer sizes and PWM audio.
 */
#pragma once

#define HAL_USE_USB TRUE
#define USB_USE_WAIT TRUE
#define HAL_USE_SERIAL_USB TRUE
#define SERIAL_BUFFERS_SIZE 128
#define SERIAL_USB_BUFFERS_SIZE 256
#define HAL_USE_PAL TRUE
#define PAL_USE_CALLBACKS TRUE
#define PAL_USE_WAIT TRUE
#define HAL_USE_I2C TRUE
#define HAL_USE_SPI TRUE
#define SPI_USE_WAIT TRUE
#define SPI_SELECT_MODE SPI_SELECT_MODE_PAD
#define HAL_USE_PWM TRUE

#include_next <halconf.h>
