#include "test_main.h"
int main() {
    // SUB a4,a3,a0
    return !(IS_INSTRUCTION(0x40A68733, r, sub));
}
