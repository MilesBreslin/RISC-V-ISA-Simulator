#include "test_main.h"
int main() {
    // MULHSU x5,x4,x3
    return !(IS_INSTRUCTION(0x023222B3, r, mulhsu));
}
