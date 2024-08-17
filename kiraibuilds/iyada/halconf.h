/* Copyright 2021 QMK
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
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
