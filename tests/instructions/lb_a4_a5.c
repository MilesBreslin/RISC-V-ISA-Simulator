#include "test_main.h"
int main() {
    // LB a5, a5
    uint32_t encoded = 0x00078783;
    I_INSTRUCTION decoded = as_i_instruction(encoded);
    if (!is_lb_instruction(&decoded))
        FAIL("Not an LB  instruction");
    VALUE_CHECK(decoded, imm, 0);
    VALUE_CHECK(decoded, rd, REG_A5);
    VALUE_CHECK(decoded, rs1, REG_A5);
    return 0;
}
