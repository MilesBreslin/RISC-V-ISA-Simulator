#include "test_main.h"
int simulation_run(simulator* s) {
    // MULH S1, T0, T1 
    write_register(s, REG_T0, 65535);
    write_register(s, REG_T1, 65535);
    write_word(s, 0, 0x026294b3);
    if(!execute_simulation_step(s))
        FAIL("program ended prematurely");
    uint32_t value = read_register(s, REG_S1);
    if (value != 65534) 
        FAIL("Expected 18, got %d", value);
    return 0;
}
