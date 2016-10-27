cmake_minimum_required(VERSION 3.6)
project(mcu_refactor)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c task/task-base.c task/task-base.h task/task-manager.c task/task-manager.h demo-module.c demo-module.h power-manager.c power-manager.h task/fake-system-task.c task/fake-system-task.h eeprom/eeprom-operation.c eeprom/eeprom-operation.h eeprom/eeprom-module.c eeprom/eeprom-module.h fault-led-event/fault-detection.c fault-led-event/fault-detection.h fault-led-event/led-control.c fault-led-event/led-control.h fault-led-event/led-test.h)
add_executable(mcu_refactor ${SOURCE_FILES})