#include "test_main.h"
int main() {
    // SLTU a4, a3, a0
    return !(IS_INSTRUCTION(0x00A6B733, r, slt));
}
