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

#undef MIN
#undef MAX
#include "pin_defs.h"
#include "nrf_gpio.h"

typedef uint32_t pin_t;

/* Operation of GPIO by pin. */

#define setPinInput(pin) nrf_gpio_cfg_input((pin), NRF_GPIO_PIN_NOPULL)
#define setPinInputHigh(pin) nrf_gpio_cfg_input((pin), NRF_GPIO_PIN_PULLUP)
#define setPinInputLow(pin) nrf_gpio_cfg_input((pin), NRF_GPIO_PIN_PULLDOWN)
#define setPinOutputPushPull(pin) nrf_gpio_cfg(pin,\
                                               NRF_GPIO_PIN_DIR_OUTPUT,\
                                               NRF_GPIO_PIN_INPUT_DISCONNECT,\
                                               NRF_GPIO_PIN_NOPULL,\
                                               NRF_GPIO_PIN_S0S1,\
                                               NRF_GPIO_PIN_NOSENSE)
#define setPinOutputOpenDrain(pin) nrf_gpio_cfg(pin,\
                                               NRF_GPIO_PIN_DIR_OUTPUT,\
                                               NRF_GPIO_PIN_INPUT_DISCONNECT,\
                                               NRF_GPIO_PIN_NOPULL,\
                                               NRF_GPIO_PIN_S0D1,\
                                               NRF_GPIO_PIN_NOSENSE)
#define setPinOutput(pin) nrf_gpio_cfg_output(pin)

#define writePinHigh(pin) nrf_gpio_pin_set(pin)
#define writePinLow(pin) nrf_gpio_pin_clear(pin)
#define gpio_write_pin(pin, level) ((level) ? (nrf_gpio_pin_write(pin, 1)) : (nrf_gpio_pin_write(pin, 0)))

#define readPin(pin) nrf_gpio_pin_read(pin)

#define togglePin(pin) nrf_gpio_pin_toggle(pin)
