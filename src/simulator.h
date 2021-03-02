#ifndef SIMULATOR_H
#define SIMULATOR_H
#include <stdint.h>

typedef struct {
    uint32_t reg[31];
    uint32_t pc;
    void* memory;
    uint32_t mem_bytes;
} simulator;

typedef enum {
    REG_ZERO = 0,
    REG_RA = 1,
    REG_SP = 2,
    REG_GP = 3,
    REG_TP = 4,
    REG_T0 = 5,
    REG_T1 = 6,
    REG_T2 = 7,
    REG_S0 = 8,
    REG_FP = 8,
    REG_S1 = 9,
    REG_A0 = 10,
    REG_A1 = 11,
    REG_A2 = 12,
    REG_A3 = 13,
    REG_A4 = 14,
    REG_A5 = 15,
    REG_A6 = 16,
    REG_A7 = 17,
    REG_S2 = 18,
    REG_S3 = 19,
    REG_S4 = 20,
    REG_S5 = 21,
    REG_S6 = 22,
    REG_S7 = 23,
    REG_S8 = 24,
    REG_S9 = 25,
    REG_S10 = 26,
    REG_S11 = 27,
    REG_T3 = 28,
    REG_T4 = 29,
    REG_T5 = 30,
    REG_T6 = 31,
} REGISTER;

void simulator_init(simulator *s, uint32_t mem_bytes);
void simulator_destroy(simulator *s);
void display_memory(simulator *s, uint32_t start_addr, uint32_t length, bool ignore_zeros);
void display_registers(simulator *s, bool ignore_zeros);
int read_file_to_memory(simulator *s, FILE *f);
int dump_memory_to_file(simulator *s, FILE *f, uint32_t start_addr, uint32_t length, bool ignore_zeros);
int dump_registers_to_file(simulator *s, FILE *f, bool ignore_zeros);
void write_word(simulator *s, uint32_t addr, uint32_t data);
void write_hword(simulator *s, uint32_t addr, uint16_t data);
void write_byte(simulator *s, uint32_t addr, uint8_t data);
uint32_t read_word(simulator *s, uint32_t addr);
uint16_t read_hword(simulator *s, uint32_t addr);
uint8_t read_byte(simulator *s, uint32_t addr);
int32_t read_sword(simulator *s, uint32_t addr);
int16_t read_shword(simulator *s, uint32_t addr);
int8_t read_sbyte(simulator *s, uint32_t addr);
uint32_t read_register(simulator *s, REGISTER reg);
int32_t read_register_signed(simulator *s, REGISTER reg);
void write_register(simulator *s, REGISTER reg, uint32_t data);
void write_register_signed(simulator *s, REGISTER reg, int32_t data);
const char *register_to_name(REGISTER reg);
REGISTER register_from_name(char *name);
bool execute_simulation_step(simulator *s);

#endif