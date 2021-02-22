#include "test_main.h"
int main() {
    // BEQ a0, a1, 1024
    return !(IS_INSTRUCTION(0x00B500E3, b, beq));
}
