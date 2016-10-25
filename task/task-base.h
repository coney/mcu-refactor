//
// Created by Coney on 25/10/2016.
//

#ifndef MCU_REFACTOR_TASKBASE_H
#define MCU_REFACTOR_TASKBASE_H

typedef void (*task_init_fn_t)(void *object);
typedef void (*task_run_fn_t)(void *object);

typedef struct tag_task_base {
    int task_id;
    int interval;
    task_init_fn_t init;
    task_run_fn_t  run;
}task_base_t;


#endif //MCU_REFACTOR_TASKBASE_H
