#define PC_INIT 0
#define SIMULATION_SIZE 1 << 20
#include "test_main.h"
int simulation_run(simulator* s) {
    // LW a5, a5
    write_word(s, 0, 0X0007A783);
    if (!execute_simulation_step(s))
        FAIL("Simulation stopped unexpectedly");
    uint32_t value = read_register(s, REG_A5);
    if(value != 0X0007A783)
        FAIL("Expected 0X0007A783, got 0x%08X", value);
    return 0;
}
