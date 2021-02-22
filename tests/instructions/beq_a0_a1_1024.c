#include "test_main.h"
int main() {
    // BEQ a0, a1, 1024
    return !(IS_INSTRUCTION(0x40B50063, b, beq));
}
