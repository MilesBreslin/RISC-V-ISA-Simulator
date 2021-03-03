#include "test_main.h"
int main() {
    // LUI x5, 2
    return !(IS_INSTRUCTION(0x000022b7, u, lui));
}
