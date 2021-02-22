#include "test_main.h"
int main() {
    // SLL a5, zero, 5 bad instruction code
    return (IS_INSTRUCTION(0x405007b3, r, sll));
}
