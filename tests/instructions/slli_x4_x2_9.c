#include "test_main.h"
int main() {
    // SLLI x4, x2, 9
    return !(IS_INSTRUCTION(0x00911213, i, slli));
}
