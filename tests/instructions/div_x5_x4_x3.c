#include "test_main.h"
int main() {
    // DIV x5,x4,x3
    return !(IS_INSTRUCTION(0x023242B3, r, div));
}
