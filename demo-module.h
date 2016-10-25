//
// Created by Coney on 25/10/2016.
//

#ifndef MCU_REFACTOR_DEMO_TASK_H
#define MCU_REFACTOR_DEMO_TASK_H

#include "task/task-base.h"

typedef struct tag_demo_module {
    task_base_t task;
    int demo_data;
    void (*process)(struct tag_demo_module *module,int a, char *b);
} demo_module_t;

#ifdef DATA_TABLE // only for generated datatable
extern demo_module_t demo_module;
#endif

demo_module_t *get_demo_module();

#endif //MCU_REFACTOR_DEMO_TASK_H
