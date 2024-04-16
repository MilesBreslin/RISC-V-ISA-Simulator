#include "test_main.h"
int main() {
    // ADD a5, zero, a5
    return !(IS_INSTRUCTION(0x00f007b3, r, add));
}
