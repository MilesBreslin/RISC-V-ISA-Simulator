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
    // <TotalBits=6>
    uint8_t opcode;
    // <TotalBits=4>
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

typedef struct {
    // <TotalBits=6>
    uint8_t opcode;
    // <TotalBits=4>
    uint8_t rd;
    // <TotalBits=19>
    int32_t imm;
} U_INSTRUCTION;
U_INSTRUCTION as_u_instruction(uint32_t instruction);

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
} B_INSTRUCTION;
B_INSTRUCTION as_b_instruction(uint32_t instruction);

typedef struct {
    // <TotalBits=6>
    uint8_t opcode;
    // <TotalBits=4>
    uint8_t rd;
    // <TotalBits=19>
    uint32_t imm;
} J_INSTRUCTION;
J_INSTRUCTION as_j_instruction(uint32_t instruction);

const uint8_t OPCODE_ADD = 0b0110011;
const uint8_t FUNC3_ADD = 0b000;
const uint8_t FUNC7_ADD = 0b0000000;
bool is_add_instruction(uint32_t instruction, const R_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_SUB = 0b0110011;
const uint8_t FUNC3_SUB = 0b000;
const uint8_t FUNC7_SUB = 0b0100000;
bool is_sub_instruction(uint32_t instruction, const R_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_SLL = 0b0110011;
const uint8_t FUNC3_SLL = 0b001;
const uint8_t FUNC7_SLL = 0b0000000;
bool is_sll_instruction(uint32_t instruction, const R_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_SLT = 0b0110011;
const uint8_t FUNC3_SLT = 0b010;
const uint8_t FUNC7_SLT = 0b0000000;
bool is_slt_instruction(uint32_t instruction, const R_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_SLTU = 0b0110011;
const uint8_t FUNC3_SLTU = 0b011;
const uint8_t FUNC7_SLTU = 0b0000000;
bool is_sltu_instruction(uint32_t instruction, const R_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_XOR = 0b0110011;
const uint8_t FUNC3_XOR = 0b100;
const uint8_t FUNC7_XOR = 0b0000000;
bool is_xor_instruction(uint32_t instruction, const R_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_SRL = 0b0110011;
const uint8_t FUNC3_SRL = 0b101;
const uint8_t FUNC7_SRL = 0b0000000;
bool is_srl_instruction(uint32_t instruction, const R_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_SRA = 0b0110011;
const uint8_t FUNC3_SRA = 0b101;
const uint8_t FUNC7_SRA = 0b0100000;
bool is_sra_instruction(uint32_t instruction, const R_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_OR = 0b0110011;
const uint8_t FUNC3_OR = 0b110;
const uint8_t FUNC7_OR = 0b0000000;
bool is_or_instruction(uint32_t instruction, const R_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_AND = 0b0110011;
const uint8_t FUNC3_AND = 0b111;
const uint8_t FUNC7_AND = 0b0000000;
bool is_and_instruction(uint32_t instruction, const R_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_ADDI = 0b0010011;
const uint8_t FUNC3_ADDI = 0b000;
bool is_addi_instruction(uint32_t instruction, const I_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_SLTI = 0b0010011;
const uint8_t FUNC3_SLTI = 0b010;
bool is_slti_instruction(uint32_t instruction, const I_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_SLTIU = 0b0010011;
const uint8_t FUNC3_SLTIU = 0b011;
bool is_sltiu_instruction(uint32_t instruction, const I_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_XORI = 0b0010011;
const uint8_t FUNC3_XORI = 0b100;
bool is_xori_instruction(uint32_t instruction, const I_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_ORI = 0b0010011;
const uint8_t FUNC3_ORI = 0b110;
bool is_ori_instruction(uint32_t instruction, const I_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_ANDI = 0b0010011;
const uint8_t FUNC3_ANDI = 0b111;
bool is_andi_instruction(uint32_t instruction, const I_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_SLLI = 0b0010011;
const uint8_t FUNC3_SLLI = 0b001;
const uint8_t FUNC7_SLLI = 0b0000000;
bool is_slli_instruction(uint32_t instruction, const I_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_SRLI = 0b0010011;
const uint8_t FUNC3_SRLI = 0b101;
const uint8_t FUNC7_SRLI = 0b0000000;
bool is_srli_instruction(uint32_t instruction, const I_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_SRAI = 0b0010011;
const uint8_t FUNC3_SRAI = 0b101;
const uint8_t FUNC7_SRAI = 0b0100000;
bool is_srai_instruction(uint32_t instruction, const I_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_BEQ = 0b1100011;
const uint8_t FUNC3_BEQ = 0b000;
bool is_beq_instruction(uint32_t instruction, const B_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_BNE = 0b1100011;
const uint8_t FUNC3_BNE = 0b001;
bool is_bne_instruction(uint32_t instruction, const B_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_BLT = 0b1100011;
const uint8_t FUNC3_BLT = 0b100;
bool is_blt_instruction(uint32_t instruction, const B_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_BGE = 0b1100011;
const uint8_t FUNC3_BGE = 0b101;
bool is_bge_instruction(uint32_t instruction, const B_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_BLTU = 0b1100011;
const uint8_t FUNC3_BLTU = 0b110;
bool is_bltu_instruction(uint32_t instruction, const B_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_BGEU = 0b1100011;
const uint8_t FUNC3_BGEU = 0b111;
bool is_bgeu_instruction(uint32_t instruction, const B_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_LUI = 0b0110111;
bool is_lui_instruction(uint32_t instruction, const U_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_AUIPC = 0b0010111;
bool is_auipc_instruction(uint32_t instruction, const U_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_JAL = 0b1101111;
bool is_jal_instruction(uint32_t instruction, const U_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_JALR = 0b1100111;
const uint8_t FUNC3_JALR = 0b0;
bool is_jalr_instruction(uint32_t instruction, const U_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_LB = 0b0000011;
const uint8_t FUNC3_LB = 0b000;
bool is_lb_instruction(uint32_t instruction, const U_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_LH = 0b0000111;
const uint8_t FUNC3_LH = 0b001;
bool is_lh_instruction(uint32_t instruction, const U_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_LW = 0b0000011;
const uint8_t FUNC3_LW = 0b010;
bool is_lw_instruction(uint32_t instruction, const U_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_LBU = 0b0000011;
const uint8_t FUNC3_LBU = 0b100;
bool is_lbu_instruction(uint32_t instruction, const U_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_LHU = 0b0000011;
const uint8_t FUNC3_LHU = 0b101;
bool is_lhu_instruction(uint32_t instruction, const U_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_SB = 0b0100011;
const uint8_t FUNC3_SB = 0b000;
bool is_sb_instruction(uint32_t instruction, const U_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_SH = 0b0100011;
const uint8_t FUNC3_SH = 0b001;
bool is_sh_instruction(uint32_t instruction, const U_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_SW = 0b0100011;
const uint8_t FUNC3_SW = 0b010;
bool is_sw_instruction(uint32_t instruction, const U_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_SBU = 0b0100011;
const uint8_t FUNC3_SBU = 0b100;
bool is_sbu_instruction(uint32_t instruction, const U_INSTRUCTION* decoded_instruction);

const uint8_t OPCODE_SHU = 0b0100011;
const uint8_t FUNC3_SHU = 0b101;
bool is_shu_instruction(uint32_t instruction, const U_INSTRUCTION* decoded_instruction);

#endif
