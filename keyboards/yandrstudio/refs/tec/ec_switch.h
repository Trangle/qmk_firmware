/* Copyright 2022 Cipulot
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

//
// Scan EC switch matrix using 74HC7051
// Define MUX_SEL_PINS, DISCHARGE_PIN, and ANALOG_PORT to compile
//

#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "matrix.h"

typedef struct {
    uint16_t low_threshold;   // threshold for key release
    uint16_t high_threshold;  // threshold for key press
} ecs_config_t;

void     ecs_init(ecs_config_t const* const ecs_config);
bool     ecs_matrix_scan(matrix_row_t current_matrix[]);
void     ecs_print_matrix(void);
uint16_t ecs_readkey_raw(uint8_t row, uint8_t col);
bool     ecs_update_key(matrix_row_t* current_row, uint8_t col, uint16_t sw_value);
