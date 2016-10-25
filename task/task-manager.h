//
// Created by Coney on 25/10/2016.
//

#ifndef MCU_REFACTOR_TASK_MANAGER_H
#define MCU_REFACTOR_TASK_MANAGER_H


#include "task-base.h"

#define register_task_module(module) register_task(&module->task, module)

typedef struct tag_task_manager {
    void (*init)();
    void (*register_task)(task_base_t *task, void *object);
    void (*run)();
} task_manager;

task_manager *get_task_manager();

#endif //MCU_REFACTOR_TASK_MANAGER_H
