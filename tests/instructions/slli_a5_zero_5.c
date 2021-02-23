#include "test_main.h"
int main() {
    // SLLI a5, zero, 5
    uint32_t encoded = 0x00501793;
    I_INSTRUCTION decoded = as_i_instruction(encoded);
    if (!is_slli_instruction(&decoded))
        FAIL("Not an slli instruction");
    VALUE_CHECK(decoded, imm, 5);
    VALUE_CHECK(decoded, rd, REG_A5);
    VALUE_CHECK(decoded, rs1, REG_ZERO);
    return 0;
}
