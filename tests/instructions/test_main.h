#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "../../src/instructions.h"
#include "../../src/simulator.h"
#include "../../src/core.h"

#pragma GCC diagnostic error "-Wincompatible-pointer-types"

#define IS_INSTRUCTION(encoded_instruction, instruction_type, operation_type) ({\
    __auto_type decoded_instruction = as_##instruction_type##_instruction(encoded_instruction);\
    bool ret = is_##operation_type##_instruction(&decoded_instruction);\
    if (ret && count_all_instruction_matches(encoded_instruction) != 1)\
        FAIL("Instruction decode matches multiple instructions: %08X", encoded_instruction);\
    ret;\
})

#define VALUE_CHECK(instruction, field, value) ({\
    if (instruction.field != value)\
        FAIL(#field " is invalid. Expected %d (" #value "). Got %d", value, instruction.field);\
})
