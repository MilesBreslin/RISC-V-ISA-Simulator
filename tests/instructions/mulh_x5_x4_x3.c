#include "test_main.h"
int main() {
    // MULH x5,x4,x3
    return !(IS_INSTRUCTION(0x023212B3, r, mulh));
}
