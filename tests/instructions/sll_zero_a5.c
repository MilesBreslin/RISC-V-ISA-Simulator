#include "test_main.h"
int main() {
    // SUB a5, zero, 5
    return !(IS_INSTRUCTION(0x405007b3, r, sub));
}