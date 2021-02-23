#include <stdint.h>
#include <stdio.h>
#include "../../src/instructions.h"
#include "../../src/simulator.h"
#include "../../src/core.h"

#pragma GCC diagnostic error "-Wincompatible-pointer-types"

#define IS_INSTRUCTION(encoded_instruction, instruction_type, operation_type) ({\
    __auto_type decoded_instruction = as_##instruction_type##_instruction(encoded_instruction);\
    is_##operation_type##_instruction(&decoded_instruction);\
})

#define VALUE_CHECK(instruction, field, value) ({\
    if (instruction.field != value)\
        FAIL(#field " is invalid. Expected %d (" #value "). Got %d", value, instruction.field);\
})
