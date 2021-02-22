#include "test_main.h"
int main() {
    // SLT a1, a3, a4
    return !(IS_INSTRUCTION(0x0041A133, r, slt));
}
