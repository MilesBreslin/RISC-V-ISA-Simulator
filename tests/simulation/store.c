#include "test_main.h"
int simulation_run(simulator* s) {
    uint32_t addr = -4;
    // SB a6, -2(a5)
    write_word(s, addr+=4, 0xff078f23);
    // SH a6, 0(a5)
    write_word(s, addr+=4, 0x01079023);
    // SW a6, -2(a5)
    write_word(s, addr+=4, 0xff07af23);

    write_register(s, REG_A5, (addr+=4) + 2);
    write_register(s, REG_A6, 0xFFFFFFFF);
    write_word(s, addr, 0);

    execute_simulation_step(s);
    uint32_t value = read_word(s, addr);
    if (value != 0x000000FF)
        FAIL("Failed to write a byte: %08X", value);
    execute_simulation_step(s);
    value = read_word(s, addr);
    if (value != 0xFFFF00FF)
        FAIL("Failed to write a half-word: %08X", value);
    execute_simulation_step(s);
    value = read_word(s, addr);
    if (value != 0xFFFFFFFF)
        FAIL("Failed to write a word: %08X", value);

    return 0;
}
