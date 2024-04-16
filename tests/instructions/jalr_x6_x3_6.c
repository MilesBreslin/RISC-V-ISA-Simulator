#include "test_main.h"
int main() {
    // JALR x6, x3, 6 
    return !(IS_INSTRUCTION(0x00618367, i, jalr));
}
