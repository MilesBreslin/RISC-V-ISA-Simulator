#include "test_main.h"
int main() {
    // SLT a4, a3, a0
    return !(IS_INSTRUCTION(0x00A6A733, r, slt));
}
