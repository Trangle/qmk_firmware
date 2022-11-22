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
#include "flash_spi.h"
#include "print.h"

#include "ikun_switch_st7735s.qgf.h"

void board_init(void) {
    AFIO->MAPR |= AFIO_MAPR_SPI1_REMAP;
}

// Initialisation
static painter_device_t lcd;
static painter_image_handle_t my_image;
static deferred_token my_anim;

void keyboard_post_init_kb(void) {
    debug_enable=true;
#ifdef EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN
    setPinOutput(EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN);
    writePinHigh(EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN);
#endif // EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN


    // Let the LCD get some power...
    wait_ms(150);

    // Initialise the LCD
    lcd = qp_st7735s_make_spi_device(80, 160, ST7735_CS_PIN, ST7735_DC_PIN, ST7735_RES_PIN, 1, 0);
    qp_init(lcd, 0);

    // Turn on the LCD and clear the display
    qp_power(lcd, true);

    // init gif
    my_image = qp_load_image_mem(gfx_ikun_switch_st7735s);
    // if (my_image != NULL) {
        my_anim = qp_animate(lcd, 0, 0, my_image);
    // }
    // qp_rect(lcd, 0, 0, 80, 160, HSV_RED, true);

    // Turn on the LCD backlight
    backlight_enable();
    backlight_level(BACKLIGHT_LEVELS);

    // For w25qx
    flash_init();

    // Allow for user post-init
    keyboard_post_init_user();
}

static bool lcd_power_flag = false;

uint8_t temp_w25q_data[32];
flash_status_t fa;

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
        case KC_B:
            if (record->event.pressed) {
                temp_w25q_data[10] = 5;
                flash_erase_block(0);
                fa = flash_write_block(0,temp_w25q_data,sizeof(temp_w25q_data));
            }
            return false;
        case KC_C:
            if (record->event.pressed) {
                temp_w25q_data[10] = 6;
                flash_erase_block(0);
                fa = flash_write_block(0,temp_w25q_data,sizeof(temp_w25q_data));
            }
            return false;
        case KC_D:
            if (record->event.pressed) {
                fa = flash_read_block(0,temp_w25q_data,sizeof(temp_w25q_data));

                dprintf("%d string", temp_w25q_data[10]);
                if (temp_w25q_data[10] == 5) {
                    qp_rect(lcd, 0, 0, 10, 10, HSV_CYAN, true);
                } else if (temp_w25q_data[10] == 6) {
                    qp_rect(lcd, 0, 0, 50, 50, HSV_GREEN, true);
                }
            }
            return false;
        default:
            break;
    }
    return true;
}


// static uint8_t last_backlight = BACKLIGHT_LIMIT_VAL;
// void suspend_power_down_user(void) {
//     if (last_backlight == BACKLIGHT_LIMIT_VAL) {
//         last_backlight = get_backlight_level();
//     }
//     backlight_set(0);
//     qp_power(lcd, false);
// }

// void suspend_wakeup_init_user(void) {
//     qp_power(lcd, true);
//     if (last_backlight != BACKLIGHT_LIMIT_VAL) {
//         backlight_set(last_backlight);
//     }
//     last_backlight = BACKLIGHT_LIMIT_VAL;
// }
