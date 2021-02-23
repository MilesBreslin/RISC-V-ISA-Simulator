#include "test_main.h"
int main() {
    // SLLI a5, a6, 5
    uint32_t encoded = 0x00581793;
    I_INSTRUCTION decoded = as_i_instruction(encoded);
    if (!is_slli_instruction(&decoded))
        FAIL("Not an slli instruction");
    VALUE_CHECK(decoded, imm, 5);
    VALUE_CHECK(decoded, rd, REG_A5);
    VALUE_CHECK(decoded, rs1, REG_A^);
    return 0;
}
