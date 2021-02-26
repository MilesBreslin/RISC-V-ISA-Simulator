#include "test_main.h"
int simulation_run(simulator* s) {
    // ADDI zero, zero, 0xAA
    uint32_t instruction = 0x0AA00013;
    // Write a instruction to write to each RD
    // ADDI REG_i, zero, 0xAA
    for (int i = 0; i < 32; i++)
        write_word(s, i*4, instruction + (i << 7));
    // Execute until stopped
    while (execute_simulation_step(s)) {}
    // Read ZERO
    if (read_register(s, REG_ZERO) != 0)
        FAIL("REG_ZERO has unexpected value");
    // Real all other registers
    for (int i = 1; i < 32; i++) {
        if (read_register(s, i) != 0xAA)
            FAIL("REG_x%d has unexpected value", i);
    }
    return 0;
}
