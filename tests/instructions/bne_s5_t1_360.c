#include "test_main.h"
int main() {
    // BNE s5, t1, 360
    return !(IS_INSTRUCTION(0x2C6A9863, b, bne));
}
