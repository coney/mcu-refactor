//
// Created by Coney on 25/10/2016.
//

#ifndef MCU_REFACTOR_FAKE_EVENT_H
#define MCU_REFACTOR_FAKE_EVENT_H

typedef void (*system_task_callback_t)(void *data);

void register_system_task(int interval, int *task_id, system_task_callback_t callback, void *data);

void run_system_task();

#endif //MCU_REFACTOR_FAKE_EVENT_H
