#pragma once

#undef MIN
#undef MAX
#include "nrf_delay.h"

#define wait_ms(ms)       \
    do {                  \
        nrf_delay_ms(ms); \
    }  while (0)

#define wait_us(us)       \
    do {                  \
        nrf_delay_us(us); \
    }  while (0)

// the nrf sdk use 4us for io delay
#ifndef GPIO_INPUT_PIN_DELAY
#    define GPIO_INPUT_PIN_DELAY 5
#endif

#define waitInputPinDelay() wait_us(GPIO_INPUT_PIN_DELAY)
