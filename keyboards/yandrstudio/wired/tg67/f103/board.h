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

#include_next "board.h"


#undef STM32_HSECLK
#define STM32_HSECLK 16000000

#undef VAL_GPIOCCRH
#define VAL_GPIOCCRH 0x88888888

#undef VAL_GPIOBCRH
#define VAL_GPIOBCRH 0x88888888

#define BOARD_YANDR_BIU_F103
