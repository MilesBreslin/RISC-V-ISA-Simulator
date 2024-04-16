#include "test_main.h"
int main() {
    // auipc x5, 2
    return !(IS_INSTRUCTION(0x00002297, u, auipc));
}
