//
// Created by Coney on 25/10/2016.
//

#include <stdlib.h>
#include "fault-detection.h"


static int has_fault = 0;

int check_system_fault() {
    has_fault = !has_fault;
    return has_fault;
}

void detect_fault(on_detect_callback_fn_t callback) {
    callback(check_system_fault());
}

