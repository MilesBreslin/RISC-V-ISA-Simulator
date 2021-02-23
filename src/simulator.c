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
    free(s->memory);
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
        printf("| %08X | %08X | \n", addr, read_word(s, addr));
        addr += 4;
    }

    printf("%s\n", line);
}

int read_file_to_memory(simulator* s, FILE *f) {
    // Parse the file
    int line_no = 0;
    char line[255];
    while (fgets(line, sizeof(line), f) != NULL) {

        // Split the string into 
        char* addr_ptr = line;
        char* value_ptr;
        if ((value_ptr = strchr(addr_ptr, ':')) != NULL) {
            value_ptr[0] = 0;
            value_ptr++;
        } else
            FAIL("Invalid line: %s", line);

        // Parse address
        uint32_t addr;
        if (sscanf(addr_ptr, "%X", &addr) != 1)
            FAIL("Invalid line: %s", line);

        // Parse value
        uint32_t value;
        if (sscanf(value_ptr, "%X", &value) != 1)
            FAIL("Invalid line: %s", line);

        // Write the word into memory
        write_word(s, addr, value);

        line_no++;
    }
    return line_no;
}

// Disable pointer math warnings only for mem access functions
#pragma GCC diagnostic ignored "-Wpointer-arith"

// Generic write memory function
// Use write_word, write_hword, write_byte instead
#define write_memory(s, addr, data, data_type) {\
    if (out_of_bounds_check(s, addr, data_type)) {\
        WARN("Out of bounds memory write access: %08X", addr);\
        return;\
    }\
    if (addr % sizeof(data_type) != 0) {\
        WARN("Unaligned memory write access: %08X", addr);\
    }\
    *((data_type*) (s->memory + addr)) = data;\
}

void write_word(simulator* s, uint32_t addr, uint32_t data) write_memory(s, addr, data, uint32_t)
void write_hword(simulator* s, uint32_t addr, uint16_t data) write_memory(s, addr, data, uint16_t)
void write_byte(simulator* s, uint32_t addr, uint8_t data) write_memory(s, addr, data, uint8_t)

// Generic read memory function
// Use read_word, read_hword, read_byte instead
#define read_memory(s, addr, data_type) {\
    if (out_of_bounds_check(s, addr, data_type)) {\
        WARN("Out of bounds memory read access: %08X", addr);\
        return (data_type) 0;\
    }\
    if (addr % sizeof(data_type) != 0)\
        WARN("Unaligned memory read access: %08X", addr);\
    return *((data_type*) (s->memory + addr));\
}
uint32_t read_word(simulator* s, uint32_t addr) read_memory(s, addr, uint32_t)
uint16_t read_hword(simulator* s, uint32_t addr) read_memory(s, addr, uint16_t)
uint8_t read_byte(simulator* s, uint32_t addr) read_memory(s, addr, uint8_t)
int32_t read_sword(simulator* s, uint32_t addr) read_memory(s, addr, int32_t)
int16_t read_shword(simulator* s, uint32_t addr) read_memory(s, addr, int16_t)
int8_t read_sbyte(simulator* s, uint32_t addr) read_memory(s, addr, int8_t)

// Enable warnings for any other pointer math
#pragma GCC diagnostic warning "-Wpointer-arith"

uint32_t read_register(simulator* s, REGISTER reg) {
    if (reg > 32)
        FAIL("Invalid register read: %d", reg);
    if (reg == REG_ZERO)
        return 0;
    return s->reg[reg];
}
void write_register(simulator* s, REGISTER reg, uint32_t data) {
    if (reg > 32)
        FAIL("Invalid register write: %d", reg);
    if (reg == REG_ZERO)
        return;
    s->reg[reg] = data;
}

bool execute_simulation_step(simulator* s) {
    uint32_t pc = s->pc;
    s->pc += 4;
    
    // No need to check OOB, read_word returns 0 on invalid memory
    uint32_t encoded_instruction = read_word(s, pc);
    if (encoded_instruction == 0) {
        INFO("Execution halted at PC: %08X", pc);
        return false;
    }
    return true;
}
