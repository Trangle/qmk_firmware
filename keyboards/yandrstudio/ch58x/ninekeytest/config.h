/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xAA96 // YP
#define PRODUCT_ID      0x6666
#define DEVICE_VER      0x0001
#define MANUFACTURER    Y&R
#define PRODUCT         CH582TPad

/* key matrix size */
#define MATRIX_ROWS 3
#define MATRIX_COLS 3


#define MATRIX_ROW_PINS { P0_5, P0_6, P0_7 }
#define MATRIX_COL_PINS { P0_1, P0_2, P0_3 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5
