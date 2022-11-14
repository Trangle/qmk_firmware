/* Copyright 2022 JasonRen(biu)
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
#define PRODUCT_ID      0xBB01
#define DEVICE_VER      0x0001
#define MANUFACTURER    "YR"
#define PRODUCT         "test"

/* key matrix size */
#define MATRIX_ROWS 1
#define MATRIX_COLS 1

#define MATRIX_COL_PINS { B12 }
#define MATRIX_ROW_PINS { B11 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

/* W25Q128 */
#define EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN B10
#define EXTERNAL_FLASH_PAGE_SIZE 256
#define EXTERNAL_FLASH_SIZE (16 * 1024 * 1024)
#define EXTERNAL_FLASH_SECTOR_SIZE (4 * 1024)
#define EXTERNAL_FLASH_BLOCK_SIZE (64 * 1024)
// #define EXTERNAL_FLASH_BLOCK_SIZE (32 * 1024)
#define EXTERNAL_FLASH_SPI_CLOCK_DIVISOR 1
#define EXTERNAL_FLASH_ADDRESS_SIZE 3

/* ST7735 TFT*/
// reset
#define ST7735_RES_PIN B1
// display/command rs pin
#define ST7735_DC_PIN B0
// chip select
#define ST7735_CS_PIN A7
// LED Anode
#define ST7735_BLK_PIN A6

/* SPI For Flash and TFT*/
#define SPI_DRIVER SPID1
#define SPI_SCK_PIN B3
#define SPI_MOSI_PIN B5
#define SPI_MISO_PIN B4

// Backlight driver (to control LCD backlight)
#define BACKLIGHT_PIN A6
#define BACKLIGHT_LEVELS 4
#define BACKLIGHT_PWM_DRIVER PWMD3
#define BACKLIGHT_PWM_CHANNEL 1
#define BACKLIGHT_LIMIT_VAL 196
