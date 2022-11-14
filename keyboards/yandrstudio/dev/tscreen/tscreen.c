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
#include "tscreen.h"
#include "qp.h"
#include "color.h"

void board_init(void) {
    AFIO->MAPR |= AFIO_MAPR_SPI1_REMAP;
}

// Initialisation
painter_device_t lcd;

void keyboard_post_init_kb(void) {
#ifdef EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN
    setPinOutput(EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN);
    writePinHigh(EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN);
#endif // EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN


    // Let the LCD get some power...
    wait_ms(150);

    // Initialise the LCD
    lcd = qp_st7735_make_spi_device(80, 160, ST7735_CS_PIN, ST7735_DC_PIN, ST7735_RES_PIN, 1, 0);
    qp_init(lcd, 0);

    // Turn on the LCD and clear the display
    qp_power(lcd, true);
    qp_rect(lcd, 0, 0, 80, 160, HSV_RED, true);

    // Turn on the LCD backlight
    backlight_enable();
    backlight_level(BACKLIGHT_LEVELS);

    // Allow for user post-init
    keyboard_post_init_user();
}

bool lcd_power_flag = false;

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user(keycode, record)) { return false; }
    switch(keycode) {
        case KC_A:
            if (record->event.pressed) {
                qp_power(lcd, lcd_power_flag);
                if (lcd_power_flag)
                    backlight_enable();
                else
                    backlight_disable();
                lcd_power_flag = !lcd_power_flag;
            }
            return false;
        default:
            break;
    }
    return true;
}
