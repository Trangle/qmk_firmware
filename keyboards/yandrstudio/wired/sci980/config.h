/* Copyright 2021 JasonRen(biu)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xAA96
#define PRODUCT_ID      0xAAC1
#define MANUFACTURER    yr_sci
#define PRODUCT         sci980

/* key matrix size */
#define MATRIX_ROWS 7
#define MATRIX_COLS 14

/* key matrix pins */
/*                         0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17*/
#define MATRIX_ROW_PINS { E6, B0, B1, B2, B3, D0, F5}
#define MATRIX_COL_PINS { D1, D2, D3, D5, D4, D6, D7, B4, B5, B6, C6, C7, F7, F6 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW


/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5


#define RGB_DI_PIN B7
#ifdef RGB_DI_PIN
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM (114)
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_LIMIT_VAL 160
#endif


#define DYNAMIC_KEYMAP_LAYER_COUNT 2


/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define LED_NUM_LOCK_PIN F0
#define LED_CAPS_LOCK_PIN F4
#define LED_SCROLL_LOCK_PIN F1
#define LED_PIN_ON_STATE 0
