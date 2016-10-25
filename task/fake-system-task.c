//
// Created by Coney on 25/10/2016.
//

#include <unistd.h>
#include "fake-system-task.h"


typedef struct tag_system_task {
    system_task_callback_t callback;
    void *data;
    int interval;
} system_task_t;
static system_task_t system_tasks[10] = {{0}};

void register_system_task(int interval, int *task_id, system_task_callback_t callback, void *data) {
    system_task_t *new_task = system_tasks;
    while (new_task->callback) {
        new_task++;
    }
    new_task->callback = callback;
    new_task->data = data;
    new_task->interval = interval;
}

void run_system_task() {
    static int ticks = 0;
    while (1) {
        system_task_t *task = system_tasks;
        while (task->callback) {
            if (ticks % task->interval == 0) {
                task->callback(task->data);
            }
            task++;
        }
        sleep(1);
        ticks++;
    }
}
