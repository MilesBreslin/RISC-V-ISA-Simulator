#include "test_main.h"
int main() {
    // ADDI a5, zero, -5
    return !(IS_INSTRUCTION(0xffb00793, i, addi));
}
