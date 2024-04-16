#include "test_main.h"
int main() {
    // DIVU x5,x4,x3
    return !(IS_INSTRUCTION(0x023252B3, r, divu));
}
