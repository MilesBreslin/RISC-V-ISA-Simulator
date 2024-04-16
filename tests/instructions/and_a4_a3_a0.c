#include "test_main.h"
int main() {
    // AND a4,a3,a0
    return !(IS_INSTRUCTION(0x00A6F733, r, and));
}
