#include "test_main.h"
int main() {
    // SRA a4,a3,a0
    return !(IS_INSTRUCTION(0x40A6D733, r, sra));
}
