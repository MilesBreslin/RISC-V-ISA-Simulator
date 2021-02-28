#include "test_main.h"
int simulation_run(simulator* s) {
    // Data payload
    uint8_t data = 0xFF;
    write_byte(s, 8, data);

    // LB a5, 8(zero)
    write_word(s, 0, 0x00800783);
    // LBU a6, 8(zero)
    write_word(s, 4, 0x00804803);

    // Simulate 2 instructions
    execute_simulation_step(s);
    execute_simulation_step(s);

    // LB is sign extended
    uint32_t value_s = read_register(s, REG_A5);
    if (value_s != 0xFFFFFFFF)
        FAIL("Expected 0xFFFFFFFF, got %08X", value_s);

    // LBU is not sign extended
    uint32_t value_u = read_register(s, REG_A6);
    if (value_u != data)
        FAIL("Expected 0xFF, got %08X", value_u);

    return 0;
}
