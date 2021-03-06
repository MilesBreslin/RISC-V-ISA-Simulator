#include "test_main.h"
int simulation_run(simulator* s) {
    // ANDI  S1, T0, 5 
    write_register(s, REG_T0, 0x18);
    write_word(s, 0, 0x0052f493);

    if(!execute_simulation_step(s))
        FAIL("program ended prematurely");
    uint32_t value = read_register(s, REG_S1);
    uint32_t imm_val = read_register_signed(s, i_instruction.imm_s);
        INFO("Immediate value is: %d");
    if (value != 29) 
        FAIL("Expected 29, got %d", value);
    return 0;
}
