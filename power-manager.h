//
// Created by Coney on 25/10/2016.
//

#ifndef MCU_REFACTOR_POWER_MANAGER_H
#define MCU_REFACTOR_POWER_MANAGER_H

typedef enum tag_power_version {
    POWER_VERSION_9K5,
    POWER_VERSION_15K,
} power_version;

typedef struct tag_power_manager {
    int power_version;
} power_manager_t;

#ifdef DATA_TABLE // only for generated datatable
extern power_manager_t power_manager;
#endif

power_manager_t *get_power_manager();

#endif //MCU_REFACTOR_POWER_MANAGER_H
