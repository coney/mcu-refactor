//
// Created by Coney on 25/10/2016.
//

#include <printf.h>
#include "led-control.h"

void turn_led(led_type_t type, led_state_t state) {
    printf("turn %s led %d\n", state == LED_ON? "on" : "off", type);
}
