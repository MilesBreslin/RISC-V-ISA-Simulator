#include "test_main.h"
int simulation_run(simulator* s) {
    // DIV S1, T0, T1 
    write_register(s, REG_T0, 9);
    write_register(s, REG_T1, 0);
    write_word(s, 0, 0x0262c4b3);
    if(!execute_simulation_step(s))
        FAIL("program ended prematurely");
    uint32_t value = read_register(s, REG_S1);
    if (value != 4294967295) 
        FAIL("Expected 4294967295, got %d", value);
    return 0;
}
