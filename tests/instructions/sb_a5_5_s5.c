#include "test_main.h"
int main() {
    // SB a5, 5(s5)
    uint32_t encoded = 0x00FB02A3;
    S_INSTRUCTION decoded = as_s_instruction(encoded);
    if (!is_sb_instruction(&decoded))
        FAIL("Not a SB  instruction");
    VALUE_CHECK(decoded, imm, 5);
    VALUE_CHECK(decoded, rd, REG_S5);
    VALUE_CHECK(decoded, rs1, REG_A5);
    return 0;
}
