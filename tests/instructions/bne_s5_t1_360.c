#include "test_main.h"
int main() {
    // BNE s5, t1, 360
   // B_INSTRUCTION decoded = as_b_instruction(0x2C6A9863);
    //printf("op:0x%02X\nfunct3:0x%01X\nrs1:x%d\nrs2:x%d\nimm:%d\n",decoded.opcode,decoded.func3,decoded.rs1,decoded.rs2,decoded.imm);
    //return is_bne_instruction(&decoded);
    return !(IS_INSTRUCTION(0x2C6A9863, b, bne));
}
