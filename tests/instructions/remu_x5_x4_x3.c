#include "test_main.h"
int main() {
    // REMU x5,x4,x3
    return !(IS_INSTRUCTION(0x023272B3, r, remu));
}
