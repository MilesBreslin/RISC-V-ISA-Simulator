#include "test_main.h"
int simulation_run(simulator* s) {
    // Write all registers
    for (int i = 0; i < 32; i++)
        write_register(s, i, 0xAA);
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
