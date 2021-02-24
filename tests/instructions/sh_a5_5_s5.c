#include "test_main.h"
int main() {
    // SH a5, 5(s5)
    uint32_t encoded = 0x00FB12A3;
    S_INSTRUCTION decoded = as_s_instruction(encoded);
    if (!is_sh_instruction(&decoded))
        FAIL("Not a SH  instruction");
    VALUE_CHECK(decoded, imm, 0);
    VALUE_CHECK(decoded, rd, REG_S5);
    VALUE_CHECK(decoded, rs1, REG_A5);
    return 0;
}
