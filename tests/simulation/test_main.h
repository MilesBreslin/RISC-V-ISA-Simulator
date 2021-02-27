#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAIN
#include "../../src/core.h"
#include "../../src/simulator.h"
#include "../../src/instructions.h"
bool verbose = 1;

#ifndef SIMULATION_SIZE
#define SIMULATION_SIZE (1 << 20)
#endif
#ifndef PC_INIT
#define PC_INIT 0
#endif
#ifndef SP_INIT
#define SP_INIT 0xFFFF
#endif

int simulation_run(simulator* s);

int main() {
    // Initialize a simulator
    simulator s;
    simulator_init(&s, SIMULATION_SIZE);
    s.pc = 0;
    write_register(&s, REG_SP, SP_INIT);

#ifdef LOAD_FILE
    // Open file
    FILE *f;
    if ((f = fopen(LOAD_FILE, "r+")) == NULL)
        FAIL_SYS("Unable to open input file:" LOAD_FILE);

    // Read file and write its values to memory
    int lines = read_file_to_memory(&s, f);
    if (lines == 0)
        FAIL("File is empty");
#endif

    int ret = simulation_run(&s);
    simulator_destroy(&s);
    return ret;
}