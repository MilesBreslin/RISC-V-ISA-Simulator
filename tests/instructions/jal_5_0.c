#include "test_main.h"
int main() {
    // JAL 5 
    return !(IS_INSTRUCTION(0x000000EF, j, jal));
}
