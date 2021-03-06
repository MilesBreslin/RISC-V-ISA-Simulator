#include "test_main.h"
int simulation_run(simulator* s) {
    // XORI  S0, T0, 2
    write_register(s, REG_T0, 0x3);
    write_word(s, 0, 0x0022c413);
    write_word(s, 4, 0xffe2c413);

    execute_simulation_step(s);

    uint32_t value = read_register(s, REG_S0);
    if (value != 1) 
        FAIL("Expected 1, got %d", value);


    execute_simulation_step(s);

    value = read_register(s, REG_S0);
    if (value != -3) 
        FAIL("Expected -3, got %d", value);
    return 0;
}
