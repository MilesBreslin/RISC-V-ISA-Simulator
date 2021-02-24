#include "test_main.h"
int main() {
    // SW a5, 5(s5)
    uint32_t encoded = 0x00FB22A3;
    S_INSTRUCTION decoded = as_s_instruction(encoded);
    if (!is_sw_instruction(&decoded))
        FAIL("Not a SW  instruction");
    VALUE_CHECK(decoded, imm, 5);
    VALUE_CHECK(decoded, rd, REG_S5);
    VALUE_CHECK(decoded, rs1, REG_A5);
    return 0;
}
