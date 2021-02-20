#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "core.h"
#include "simulator.h"

void simulator_init(simulator* s, uint32_t mem_bytes) {
    memset(s, 0, sizeof(*s));
    s->memory = malloc(mem_bytes);
    s->mem_bytes = mem_bytes;
}

void simulator_destroy(simulator* s) {
    free(&s->memory);
}

#define out_of_bounds_check(s, addr, data_type) (addr >= (((int64_t) s->mem_bytes) - sizeof(data_type)))

void display_memory(simulator* s, uint32_t start_addr, uint32_t length) {
    // Check if address is out of bounds
    if (out_of_bounds_check(s, start_addr, uint32_t)) {
        WARN("Out of bounds memory display: %08X", start_addr);
        return;
    }

    // Ensure the length is in bounds
    uint32_t actual_len = length;
    if (start_addr + length > s->mem_bytes)
        actual_len = start_addr - s->mem_bytes;

    // Pretty table formatting
    const char* line = "|---------------------|";
    printf("%s\n", line);
    printf("| %-8s | %-8s |\n", "Address", "Length");
    printf("%s\n", line);

    // Print all values
    uint32_t addr = start_addr;
    while (actual_len-- > 0) {
        printf("| %08X | %08X | \n", addr, *(uint32_t*) (s->memory + addr));
        addr += 4;
    }

    printf("%s\n", line);
}

void write_word(simulator* s, uint32_t addr, uint32_t word) {
    // Check if address is out of bounds
    if (out_of_bounds_check(s, addr, uint32_t)) {
        WARN("Out of bounds memory write access: %08X", addr);
        return;
    }

    *((uint32_t*) (s->memory + addr)) = word;
    s->pc = addr;
}

void write_byte(simulator* s, uint32_t addr, uint8_t byte) {
    // Check if address is out of bounds
    if (out_of_bounds_check(s, addr, uint8_t)) {
        WARN("Out of bounds memory write access: %08X", addr);
        return;
    }

    *((uint8_t*) (s->memory + addr)) = byte;
}

bool execute_simulation_step(simulator* s, uint32_t PC) {
    // Check if address is out of bounds
    if (PC > s->pc) {
        WARN("Execution reached the end without a halt: %08X", PC);
        exit(EXIT_FAILURE);
    }

    bool ret = true;
    
    if ((*(uint32_t*)(s->memory + PC)) == 0) {
        INFO("Execution halted at PC: %08X", PC);
        ret = false;
    }
    else {
        /*else if instruction != zeros, then execute*/
    }
    return ret;
}
