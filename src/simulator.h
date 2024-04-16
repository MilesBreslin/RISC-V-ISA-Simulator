#ifndef SIMULATOR_H
#define SIMULATOR_H
#include <stdint.h>

typedef struct {
    uint32_t reg[31];
    uint32_t pc;
    void* memory;
    uint32_t mem_bytes;
    int return_code;
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

// Initialize a simulator object
void simulator_init(simulator *s, uint32_t mem_bytes);

// Destroy a simulator object
void simulator_destroy(simulator *s);

// Write the specified memory contents to stdout
// This appears in the format of a memory image file
// A 0 length is infinite
// 0 values may be ignored by setting the ignore_zeros flag to true
void display_memory(simulator *s, uint32_t start_addr, uint32_t length, bool ignore_zeros);

// Write all registers to stdout
// This appears in the format of a memory image file
// 0 values may be ignored by setting the ignore_zeros flag to true
void display_registers(simulator *s, bool ignore_zeros);

// Read a memory image file
// This can be used to load the simulator state from a file into memory
// This allows for memory addresses, registers, and pc
// The length of the value may determine whether the write is a word, hword, or byte
// returns the number of lines read if no errors, otherwise a negative number
int read_file_to_memory(simulator *s, FILE *f);

// Write to a memory address from a string
// This allows for memory addresses, registers, and pc
// The length of the value may determine whether the write is a word, hword, or byte
// returns 0 if no errors, otherwise a negative number
int write_mem_str(simulator* s, char* addr_ptr, char* value_ptr);

// Read a memory address from a string
// The value is always a full word
// returns 0 if no errors, otherwise a negative number
int read_mem_str(simulator* s, char* addr_ptr, uint32_t* value);

// Write the specified memory contents to a file pointer
// This appears in the format of a memory image file
// A 0 length is infinite
// 0 values may be ignored by setting the ignore_zeros flag to true
int dump_memory_to_file(simulator *s, FILE *f, uint32_t start_addr, uint32_t length, bool ignore_zeros);

// Write all registers to a file pointer
// This appears in the format of a memory image file
// 0 values may be ignored by setting the ignore_zeros flag to true
int dump_registers_to_file(simulator *s, FILE *f, bool ignore_zeros);

// Write a word to a memory address
// Warns if out-of-bounds or misaligned
void write_word(simulator *s, uint32_t addr, uint32_t data);

// Write a hword to a memory address
// Warns if out-of-bounds or misaligned
void write_hword(simulator *s, uint32_t addr, uint16_t data);

// Write a byte to a memory address
// Warns if out-of-bounds
void write_byte(simulator *s, uint32_t addr, uint8_t data);

// Read an unsigned word from memory
// Warns if out-of-bounds or misaligned and returns 0
uint32_t read_word(simulator *s, uint32_t addr);

// Read an unsigned hword from memory
// Warns if out-of-bounds or misaligned and returns 0
uint16_t read_hword(simulator *s, uint32_t addr);

// Read an unsigned byte from memory
// Warns if out-of-bounds or misaligned and returns 0
uint8_t read_byte(simulator *s, uint32_t addr);

// Read a signed word from memory
// Warns if out-of-bounds or misaligned and returns 0
int32_t read_sword(simulator *s, uint32_t addr);

// Read a signed hword from memory
// Warns if out-of-bounds or misaligned and returns 0
int16_t read_shword(simulator *s, uint32_t addr);

// Read a signed byte from memory
// Warns if out-of-bounds or misaligned and returns 0
int8_t read_sbyte(simulator *s, uint32_t addr);

// Read a register to an unsigned value
// Fails if invalid register
uint32_t read_register(simulator *s, REGISTER reg);

// Read a register to a signed value
// Fails if invalid register
int32_t read_register_signed(simulator *s, REGISTER reg);

// Writes to a register a unsigned value
// Fails if invalid register
void write_register(simulator *s, REGISTER reg, uint32_t data);

// Writes to a register a signed value
// Fails if invalid register
void write_register_signed(simulator *s, REGISTER reg, int32_t data);

// Returns a static string reference to a given register
// Returns "REG_INVALID" for an invalid register
// Uses names found in the REGISTER enum
const char *register_to_name(REGISTER reg);

// Get a register value from a string
// Is case-insensitive
// Uses names found in the REGISTER enum
// Returns -1 if invalid register name
REGISTER register_from_name(char *name);

// Execute a simulation step
// This function is the main execution for the simulator
// It includes the fetch, decode, execute, memory, and write-back phases
// Returns true if the simulator should continue
// Warns for invalid instructions
// Verbose will show decoded instructions at run-time
// Will exit on ECALL exit or a 0 instruction is encountered
bool execute_simulation_step(simulator *s);

#endif