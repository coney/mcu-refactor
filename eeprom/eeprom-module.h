//
// Created by Coney on 25/10/2016.
//

#ifndef MCU_REFACTOR_EEPROM_MODULE_H
#define MCU_REFACTOR_EEPROM_MODULE_H

#include "eeprom-operation.h"
#include "../task/task-base.h"

typedef struct tag_eeprom_module {
    task_base_t task;
    void (*register_operation)(eeprom_operation_t *ops, int ops_count, void *object);
}eeprom_module_t;


#ifdef DATA_TABLE // only for generated datatable
extern eeprom_module_t eeprom_module;
#endif

eeprom_module_t *get_eeprom_module();

#endif //MCU_REFACTOR_EEPROM_MODULE_H
