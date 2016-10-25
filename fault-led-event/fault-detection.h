//
// Created by Coney on 25/10/2016.
//

#ifndef MCU_REFACTOR_FAULT_DETECTION_H
#define MCU_REFACTOR_FAULT_DETECTION_H

typedef void (*on_detect_callback_fn_t)(int has_fault);

void detect_fault(on_detect_callback_fn_t callback);

#endif //MCU_REFACTOR_FAULT_DETECTION_H
