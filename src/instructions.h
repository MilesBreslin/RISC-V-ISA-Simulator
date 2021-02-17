// This file has been generated using `tools/opcode_generator`
// DO NOT EDIT BY HAND

#ifndef INSTRUCTIONS_H

#define INSTRUCTIONS_H

#include <stdbool.h>

#include <stdint.h>

typedef struct {
    // <TotalBits=6>
    uint8_t opcode;
    // <TotalBits=4>
    uint8_t rd;
    // <TotalBits=2>
    uint8_t func3;
    // <TotalBits=4>
    uint8_t rs1;
    // <TotalBits=4>
    uint8_t rs2;
    // <TotalBits=6>
    uint8_t func7;
} R_INSTRUCTION;
R_INSTRUCTION as_r_instruction(uint32_t instruction);

typedef struct {
    // <TotalBits=7>
    uint8_t opcode;
    // <TotalBits=5>
    uint8_t rd;
    // <TotalBits=2>
    uint8_t func3;
    // <TotalBits=4>
    uint8_t rs1;
    // <TotalBits=7>
    int8_t imm;
} I_INSTRUCTION;
I_INSTRUCTION as_i_instruction(uint32_t instruction);

typedef struct {
    // <TotalBits=6>
    uint8_t opcode;
    // <TotalBits=2>
    uint8_t func3;
    // <TotalBits=4>
    uint8_t rs1;
    // <TotalBits=4>
    uint8_t rs2;
    // <TotalBits=10>
    uint16_t imm;
} S_INSTRUCTION;
S_INSTRUCTION as_s_instruction(uint32_t instruction);

const uint8_t OPCODE_ADD = 0b0110011;
const uint8_t FUNC3_ADD = 0b000;
const uint8_t FUNC7_ADD = 0b0000000;
bool is_add_instruction(uint32_t instruction, R_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_SUB = 0b0110011;
const uint8_t FUNC3_SUB = 0b000;
const uint8_t FUNC7_SUB = 0b0100000;
bool is_sub_instruction(uint32_t instruction, R_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_LW = 0b0000011;
const uint8_t FUNC3_LW = 0b010;
bool is_lw_instruction(uint32_t instruction, I_INSTRUCTION* decoded_instruction);

#endif
