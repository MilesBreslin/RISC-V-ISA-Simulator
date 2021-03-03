#define PC_INIT 0
#define SIMULATION_SIZE 1 << 20
#define LOAD_FILE "srli_test.mem"
#include "test_main.h"
int simulation_run(simulator* s) {
    while (execute_simulation_step(s)){}
        //FAIL("Simulation was supposed to stop immedietely");
    return 0;
}
