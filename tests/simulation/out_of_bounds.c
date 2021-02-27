#include "test_main.h"
int simulation_run(simulator* s) {
    uint32_t data = 1;
    write_word(s, SIMULATION_SIZE - 4, data);
    if (read_word(s, SIMULATION_SIZE - 4) != data)
        FAIL("Data incorrect");
    write_hword(s, SIMULATION_SIZE - 2, data);
    if (read_hword(s, SIMULATION_SIZE - 2) != data)
        FAIL("Data incorrect");
    write_byte(s, SIMULATION_SIZE - 2, data);
    if (read_byte(s, SIMULATION_SIZE - 2) != data)
        FAIL("Data incorrect");
    return 0;
}
