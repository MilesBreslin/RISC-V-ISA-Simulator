#include "test_main.h"
int simulation_run(simulator* s) {
    // MUL S1, T0, T1 
    write_register(s, REG_T0, 9);
    write_register(s, REG_T1, 2);
    write_word(s, 0, 0x026284b3);
    if(!execute_simulation_step(s))
        FAIL("program ended prematurely");
    uint32_t value = read_register(s, REG_A5);
    if (value != 18) 
        FAIL("Expected 18, got %d", value);
    return 0;
}
