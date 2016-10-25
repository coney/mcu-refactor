//
// Created by Coney on 25/10/2016.
//

#include "power-manager.h"


power_manager_t power_manager = {
        // maybe init by datatable or something else
        .power_version = POWER_VERSION_9K5
};

power_manager_t *get_power_manager() {
    return &power_manager;
}
