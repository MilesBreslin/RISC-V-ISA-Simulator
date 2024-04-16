#include "test_main.h"
int main() {
    // XOR a4,a3,a0
    return !(IS_INSTRUCTION(0x00A6C733, r, xor));
}
