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
    qp_init(lcd, QP_ROTATION_0);

    // Turn on the LCD and clear the display
    qp_power(lcd, true);
    qp_rect(lcd, 0, 0, 239, 319, 0,0,0, true);

    // Allow for user post-init
    keyboard_post_init_user();
}
