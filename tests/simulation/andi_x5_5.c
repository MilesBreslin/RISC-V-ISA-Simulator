#include "test_main.h"
int simulation_run(simulator* s) {
    // ANDI  S1, T0, 5 
    write_register(s, REG_T0, 24);
    write_word(s, 0, 0x0052f493);

    if(!execute_simulation_step(s))
        FAIL("program ended prematurely");
    uint32_t value = read_register(s, REG_S1);
    if (value != 29) 
        FAIL("Expected 29, got %d", value);
    return 0;
}
