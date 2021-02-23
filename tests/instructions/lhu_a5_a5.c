#include "test_main.h"
int main() {
    // LHU a5, a5
    uint32_t encoded = 0x0007D783;
    I_INSTRUCTION decoded = as_i_instruction(encoded);
    if (!is_lhu_instruction(&decoded))
        FAIL("Not an LHU  instruction");
    VALUE_CHECK(decoded, imm, 0);
    VALUE_CHECK(decoded, rd, REG_A5);
    VALUE_CHECK(decoded, rs1, REG_A5);
    return 0;
}
