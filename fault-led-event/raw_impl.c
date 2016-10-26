//
// Created by Coney on 26/10/2016.
//

#include <stdlib.h>
#include "led-control.h"

int g_has_fault = 0;

static int check_system_fault() {
    return rand();
}

void detectFault() {
    g_has_fault = check_system_fault();
}

static void update_led_status() {
    turn_led(FAULT_LED, g_has_fault ? LED_ON : LED_OFF);
}

void run_system_task() {
    detectFault();
    update_led_status();
}