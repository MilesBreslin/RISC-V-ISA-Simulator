#include "test_main.h"
int simulation_run(simulator* s) {
    // ADDI a5, zero, 5
    write_word(s, 0, 0x00500793);
    if (!execute_simulation_step(s))
        FAIL("Simulation stopped unexpectedly");
    uint32_t value = read_register(s, REG_A5);
    if (value != 5)
        FAIL("Expected 5, got %d", value);
    return 0;
}
