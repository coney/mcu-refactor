//
// Created by Coney on 25/10/2016.
//

#include <printf.h>
#include "demo-module.h"
#include "power-manager.h"
#include "eeprom/eeprom-operation.h"
#include "eeprom/eeprom-module.h"


static void demo_module_prepare_data(void *object);
static void demo_module_read_callback(void *object, eeprom_result_t result);

eeprom_operation_t demo_module_eeprom_ops[2] = {
        {EEPROM_NOP, (void *)0x1111, (void *)0x2222, (void *)0, 0, demo_module_prepare_data, NULL},
        {EEPROM_READ, (void *)0x4444, (void *)0x5555, (void *)0x6666, 20, NULL, demo_module_read_callback}
};

static void demo_module_prepare_data(void *object) {
    printf("demo module %p prepare data for write\n", object);
    demo_module_eeprom_ops[0].op = EEPROM_WRITE;
    demo_module_eeprom_ops[0].buffer = (void*)0x3333;
    demo_module_eeprom_ops[0].buffer_length = 10;
}

static void demo_module_read_callback(void *object, eeprom_result_t result) {
    printf("demo module %p read complete, result: %d\n", object, result);
}


static void demo_process_on_9k5(demo_module_t *module, int a, char *b) {
    printf("process for 9k5, input: %d %s\n", a, b);
}

static void demo_process_on_15k(demo_module_t *module, int a, char *b) {
    printf("process for 15, input: %d %s\n", a, b);
}

static void demo_module_init(demo_module_t *module) {
    if (get_power_manager()->power_version == POWER_VERSION_9K5) {
        printf("initialize demo module with 9.5k power version\n");
        module->process = demo_process_on_9k5;
    } else {
        printf("initialize demo module with 15k power version\n");
        module->process = demo_process_on_15k;
    }
    module->demo_data = 0x9527;
    get_eeprom_module()->register_operation(demo_module_eeprom_ops, 2, module);
}

static void demo_module_on_timer(demo_module_t *module) {
    printf("run in demo_module_on_timer, module %p\n", module);
}

demo_module_t demo_module = {
        .task = {.interval = 3, .init = (task_init_fn_t)demo_module_init, .run = (task_run_fn_t)demo_module_on_timer}
};

demo_module_t *get_demo_module() {
    return &demo_module;
}
