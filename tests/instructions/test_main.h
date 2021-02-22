#include <stdint.h>
#include <stdio.h>
#include "../../src/instructions.h"

#pragma GCC diagnostic error "-Wincompatible-pointer-types"

#define IS_INSTRUCTION(encoded_instruction, instruction_type, operation_type) ({\
    __auto_type decoded_instruction = as_##instruction_type##_instruction(encoded_instruction);\
    is_##operation_type##_instruction(&decoded_instruction);\
})
