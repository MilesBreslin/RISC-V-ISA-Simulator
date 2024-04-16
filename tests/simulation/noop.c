#define PC_INIT 0
#define SIMULATION_SIZE 1 << 20
#define LOAD_FILE "noop.mem"
#include "test_main.h"
int simulation_run(simulator* s) {
    if (execute_simulation_step(s))
        FAIL("Simulation was supposed to stop immedietely");
    return 0;
}
