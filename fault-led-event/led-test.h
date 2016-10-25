//
// Created by Coney on 25/10/2016.
//

#ifndef MCU_REFACTOR_LED_TEST_H
#define MCU_REFACTOR_LED_TEST_H

#include "led-control.h"
#include "fault-detection.h"

static led_on_fault_callback(int has_fault) {
    if (has_fault) {
        turn_led(FAULT_LED, LED_ON);
    }else {
        turn_led(FAULT_LED, LED_OFF);
    }
}

static void test_fault_detection_with_led() {
    detect_fault(led_on_fault_callback);
}

#endif //MCU_REFACTOR_LED_TEST_H
