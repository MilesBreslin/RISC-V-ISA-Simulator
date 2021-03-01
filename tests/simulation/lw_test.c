#define PC_INIT 0
#define SIMULATION_SIZE 1 << 20
#define LOAD_FILE "lw_test.mem"
#include "test_main.h"
int simulation_run(simulator* s) {
    // LW a5, a5
    write_word(s, 0, 0x00052503);
    if (!execute_simulation_step(s))
        FAIL("Simulation stopped unexpectedly");
    //unit32_t value = read_register(s, REG_A5);
    display_memory(s, 0, 16);
    display_registers(s);
    //if(value != 5)
    //    FAIL("Expected 5, got %d", value);
    return 0;
}
