#ifndef SIMULATOR_H
#include <stdint.h>


typedef struct {
    uint32_t reg[32];
    uint32_t pc;
    void* memory;
    uint32_t mem_bytes;
} simulator;

void simulator_init(simulator *s, uint32_t mem_bytes);
void simulator_destroy(simulator *s);
void display_memory(simulator *s, uint32_t start_addr, uint32_t length);
void write_word(simulator *s, uint32_t addr, uint32_t word);
void write_byte(simulator *s, uint32_t addr, uint8_t byte);
bool execute_simulation_step(simulator* s, uint32_t PC);

#endif