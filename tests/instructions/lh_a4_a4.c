#include "test_main.h"
int main() {
    // Lh a4, a4
    uint32_t encoded = 0x00071703;
    I_INSTRUCTION decoded = as_i_instruction(encoded);
    if (!is_lh_instruction(&decoded))
        FAIL("Not an LH instruction");
    VALUE_CHECK(decoded, imm, 0);
    VALUE_CHECK(decoded, rd, REG_A4);
    VALUE_CHECK(decoded, rs1, REG_A4);
    return 0;
}
