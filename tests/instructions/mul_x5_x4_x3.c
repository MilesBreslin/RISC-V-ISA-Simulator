#include "test_main.h"
int main() {
    // MUL x5,x4,x3
    return !(IS_INSTRUCTION(0x023202B3, r, mul));
}
