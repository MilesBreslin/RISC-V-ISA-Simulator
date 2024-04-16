#include "test_main.h"
int main() {
    // MULHU x5,x4,x3
    return !(IS_INSTRUCTION(0x023232B3, r, mulhu));
}
