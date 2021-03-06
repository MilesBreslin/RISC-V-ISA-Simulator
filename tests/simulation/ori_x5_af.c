#include "test_main.h"
int simulation_run(simulator* s) {
    // ORI  S0, T0, 15
    write_register(s, REG_T0, 0x0);
    write_word(s, 0, 0x00a2e413);
    write_word(s, 4, 0xff62e413);

    execute_simulation_step(s);

    uint32_t value = read_register(s, REG_S0);
    if (value != -10) 
        FAIL("Expected -10, got %d", value);


    execute_simulation_step(s);

    value = read_register(s, REG_S0);
    if (value != 10) 
        FAIL("Expected 10, got %d", value);
    return 0;
}
