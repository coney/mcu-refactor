//
// Created by Coney on 25/10/2016.
//

#include <memory.h>
#include "task-manager.h"
#include "fake-system-task.h"

#define MAX_TASK_COUNT 10

typedef struct tag_task {
    task_base_t *task;
    void *data;
    int inited;
} task_t;

static task_t tasks[MAX_TASK_COUNT];
static int current_task_count = 0;

static void task_init() {
    memset(tasks, 0, sizeof(tasks));
}


static void task_run(task_t *task) {
    if (task->inited) {
        task->task->run(task->data);
    } else {
        task->task->init(task->data);
        task->inited = 1;
    }
}


static void task_register(task_base_t *task, void *object) {
    task_t *new_task = &tasks[current_task_count++];
    new_task->task = task;
    new_task->data = object;
    new_task->inited = 0;
    register_system_task(task->interval, &task->task_id, (system_task_callback_t) task_run, new_task);
}

static task_manager task_manager_instance = {
        .init = task_init,
        .run = task_run,
        .register_task = task_register
};

task_manager *get_task_manager() {
    return &task_manager_instance;
}
