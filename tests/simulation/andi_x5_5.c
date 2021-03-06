#include "test_main.h"
int simulation_run(simulator* s) {
    // ANDI  S0, T0, 5 
    write_register(s, REG_T0, 5);
    write_word(s, 0, 0x0052f413);

    if(!execute_simulation_step(s))
        FAIL("program ended prematurely");
    uint32_t value = read_register(s, REG_S0);
    if (value != 5) 
        FAIL("Expected 5, got %d", value);
    return 0;
}
