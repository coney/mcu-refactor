//
// Created by Coney on 25/10/2016.
//

#ifndef MCU_REFACTOR_LED_CONTROL_H
#define MCU_REFACTOR_LED_CONTROL_H

typedef enum tag_led_type {
    POWER_LED,
    FAULT_LED
} led_type_t;

typedef enum tag_led_state {
    LED_ON,
    LED_OFF
} led_state_t;

void turn_led(led_type_t type, led_state_t state);

#endif //MCU_REFACTOR_LED_CONTROL_H
