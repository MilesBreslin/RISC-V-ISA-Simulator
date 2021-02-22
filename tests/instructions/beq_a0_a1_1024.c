#include "test_main.h"
int main() {
    // BEQ a0, a1, 1024
    //return !(IS_INSTRUCTION(0x40B50063, b, beq));
    B_INSTRUCTION decoded_instruction = as_b_instruction(0x40B50063);
    printf("opcode: %02X\n func3: %01X\n", decoded_instruction.opcode, decoded_instruction.func3);
    return is_beq_instruction(&decoded_instruction);
}
