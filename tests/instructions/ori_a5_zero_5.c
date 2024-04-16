#include "test_main.h"
int main() {
    // ORI a5, zero, 5
    uint32_t encoded = 0x00506793;
    I_INSTRUCTION decoded = as_i_instruction(encoded);
    if (!is_ori_instruction(&decoded))
        FAIL("Not an ori instruction");
    VALUE_CHECK(decoded, imm_s, 5);
    VALUE_CHECK(decoded, rd, REG_A5);
    VALUE_CHECK(decoded, rs1, REG_ZERO);
    return 0;
}
