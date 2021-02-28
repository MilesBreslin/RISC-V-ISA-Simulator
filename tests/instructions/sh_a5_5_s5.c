#include "test_main.h"
int main() {
    // SH a5, 5(s5)
    uint32_t encoded = 0x00FB1023;
    S_INSTRUCTION decoded = as_s_instruction(encoded);
    if (!is_sh_instruction(&decoded))
        FAIL("Not a SH  instruction");
    VALUE_CHECK(decoded, imm_s, 0);
    VALUE_CHECK(decoded, rs1, REG_S6);
    VALUE_CHECK(decoded, rs2, REG_A5);
    return 0;
}
