#include "test_main.h"
int simulation_run(simulator* s) {
    // Data payload
    uint32_t data1 = 0x00000005;
    uint32_t data2 = 0x00000006;
    write_word(s, 18, data1);
    write_word(s,1C, data2);
    write_register(s, REG_A6, 0x00000005);
    write_register(s, REG_A7, 0x00000009);

    // ADD a5, a6, a7
    write_word(s, 0, 0x011807b3);
    // SUB a4, a6, a7
    write_word(s, 4, 0x41180733);

    // Simulate 2 instructions
    execute_simulation_step(s);
    execute_simulation_step(s);

    //ADD result
    uint32_t value_add = read_register(s, REG_A5);
    INFO("Expected 0xFFFFFFFF, got %08X", value_add);

    //SUB result
    uint32_t value_sub = read_register(s, REG_A4);
    INFO("Expected 0xFF, got %08X", value_sub);

    return 0;
}
