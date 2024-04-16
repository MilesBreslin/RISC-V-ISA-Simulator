#include "test_main.h"
int main() {
    // SRLI x4, x2, 8
    return !(IS_INSTRUCTION(0x00815213, i, srli));
}
