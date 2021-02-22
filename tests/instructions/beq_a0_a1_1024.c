#include "test_main.h"
int main() {
    // BEQ a0, a1, 1024
    //return !(IS_INSTRUCTION(0x40B50063, b, beq));
    B_INSTRUCTION decoded_instruction = as_b_instruction(0x00B500E3);
    printf("opcode: 0x%02X\nfunc3: 0x%01X\nrs1: x%d\nrs2: x%d\nimm: %d (decimal)\n", decoded_instruction.opcode, decoded_instruction.func3, decoded_instruction.rs1, decoded_instruction.rs2, decoded_instruction.imm);
    return is_beq_instruction(&decoded_instruction);
}
