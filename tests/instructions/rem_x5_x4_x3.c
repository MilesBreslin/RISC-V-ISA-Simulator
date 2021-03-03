#include "test_main.h"
int main() {
    // REM x5,x4,x3
    return !(IS_INSTRUCTION(0x023262B3, r, rem));
}
