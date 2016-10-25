//
// Created by Coney on 25/10/2016.
//

#include <memory.h>
#include <printf.h>
#include "eeprom-module.h"

// simulate eeprom lib functions
static eeprom_result_t lib_eeprom_write(void *rom_address, void *io_address, void *buffer, int length) {
    printf("lib_eeprom_write rom:%04X io:%04X buffer:%04x length:%d\n",
           (int)rom_address, (int)io_address, (int)buffer, length);
    return 0;
}

static eeprom_result_t lib_eeprom_read(void *rom_address, void *io_address, void *buffer, int length) {
    printf("lib_eeprom_read rom:%04X io:%04X buffer:%04x length:%d\n",
           (int)rom_address, (int)io_address, (int)buffer, length);
    return 1;
}


typedef struct tag_eeprom_io_request {
    eeprom_operation_t *ops;
    int ops_count;
    void *data;
} eeprom_io_request_t;

eeprom_io_request_t eeprom_io_requests[10];

static void eeprom_register_operation(eeprom_operation_t *ops, int ops_count, void *object) {
    eeprom_io_request_t *new_request = eeprom_io_requests;
    while (new_request->ops) {
        new_request++;
    }
    new_request->ops = ops;
    new_request->ops_count = ops_count;
    new_request->data = object;
}

static void eeprom_init(void *data) {
    printf("initialize eeprom\n");
    memset(eeprom_io_requests, 0, sizeof(eeprom_io_requests));
}

static void process_eeprom_request(eeprom_io_request_t *request) {
    for (int i = 0; i < request->ops_count; ++i) {
        eeprom_operation_t opeartion = request->ops[i];
        if (opeartion.io_callback) {
            opeartion.io_callback(request->data);
        }

        // no read or write
        if (opeartion.op == EEPROM_NOP) continue;

        eeprom_result_t result = 0;

        if (opeartion.op == EEPROM_READ) {
            result = lib_eeprom_read(
                    opeartion.rom_address, opeartion.io_address,
                    opeartion.buffer, opeartion.buffer_length);
        } else if (opeartion.op == EEPROM_WRITE) {
            result = lib_eeprom_write(
                    opeartion.rom_address, opeartion.io_address,
                    opeartion.buffer, opeartion.buffer_length);
        }
        if (opeartion.result_callback) {
            opeartion.result_callback(request->data, result);
        }
    }
}


static void eeprom_run(void *data) {
    eeprom_io_request_t *request = eeprom_io_requests;
    while (request->ops) {
        process_eeprom_request(request++);
    }
}

eeprom_module_t eeprom_module = {
        .task ={.interval = 2, .init = eeprom_init, .run = eeprom_run},
        .register_operation = eeprom_register_operation
};

eeprom_module_t *get_eeprom_module() {
    return &eeprom_module;
}
