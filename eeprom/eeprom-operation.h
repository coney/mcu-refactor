//
// Created by Coney on 25/10/2016.
//

#ifndef MCU_REFACTOR_EEPROM_BASE_H
#define MCU_REFACTOR_EEPROM_BASE_H

typedef enum tag_eeprom_op_type {
    EEPROM_NOP,
    EEPROM_READ,
    EEPROM_WRITE
}eeprom_op_type_t;

typedef int eeprom_result_t;

typedef void (*eeprom_io_callback_fn_t)(void *object);
typedef void (*eeprom_result_callback_fn_t)(void *object, eeprom_result_t result);

typedef struct tag_eeprom_opeartion {
    eeprom_op_type_t op;    // read or write or do nothing
    void *rom_address;
    void *io_address;
    void *buffer;
    int   buffer_length;
    eeprom_io_callback_fn_t io_callback;
    eeprom_result_callback_fn_t result_callback;
}eeprom_operation_t;


#endif //MCU_REFACTOR_EEPROM_BASE_H
