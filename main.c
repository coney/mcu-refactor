//
// Created by Coney on 25/10/2016.
//

#include <printf.h>
#include "task/task-manager.h"
#include "demo-module.h"
#include "task/fake-system-task.h"
#include "eeprom/eeprom-module.h"
#include "fault-led-event/led-test.h"


int main(int argc, char **argv) {
    task_manager *task_manager = get_task_manager();
    task_manager->init();

    eeprom_module_t *eeprom_module = get_eeprom_module();
    task_manager->register_task_module(eeprom_module);

    demo_module_t *demo = get_demo_module();
    task_manager->register_task_module(demo);

    // simulate system task & event
    run_system_task();
}