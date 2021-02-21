#include "test_main.h"
int main() {
    // ADD a5, zero, 5
    return !(IS_INSTRUCTION(0x005007b3, r, add));
}
