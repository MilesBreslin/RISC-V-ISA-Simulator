#include "test_main.h"
int simulation_run(simulator* s) {
    // ANDI  S0, T0, 5 
    write_register(s, REG_T0, 0xFFFFFFFF);
    write_word(s, 0, 0x0052f413);
    write_word(s, 4, 0xffb2f413);

    execute_simulation_step(s);

    uint32_t value = read_register(s, REG_S0);
    if (value != 5) 
        FAIL("Expected 5, got %d", value);


    execute_simulation_step(s);

    value = read_register(s, REG_S0);
    if (value != (0xFFFFFFFF & -5)) 
        FAIL("Expected 5, got %d", value);
    return 0;
}
