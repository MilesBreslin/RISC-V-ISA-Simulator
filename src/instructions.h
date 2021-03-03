// This file has been generated using `tools/opcode_generator`
// DO NOT EDIT BY HAND

#ifndef INSTRUCTIONS_H

#define INSTRUCTIONS_H

#include <stdbool.h>

#include <stdint.h>

#include "simulator.h"

typedef struct {
    // <TotalBits=7>
    uint8_t opcode;
    // <TotalBits=5>
    REGISTER rd;
    // <TotalBits=3>
    uint8_t func3;
    // <TotalBits=5>
    REGISTER rs1;
    // <TotalBits=5>
    REGISTER rs2;
    // <TotalBits=7>
    uint8_t func7;
} R_INSTRUCTION;
R_INSTRUCTION as_r_instruction(uint32_t instruction);

typedef struct {
    // <TotalBits=7>
    uint8_t opcode;
    // <TotalBits=5>
    REGISTER rd;
    // <TotalBits=3>
    uint8_t func3;
    // <TotalBits=5>
    REGISTER rs1;
    // <TotalBits=7>
    uint8_t func7;
    // <TotalBits=12>
    uint16_t imm_u;
    // <TotalBits=12>
    int16_t imm_s;
} I_INSTRUCTION;
I_INSTRUCTION as_i_instruction(uint32_t instruction);

typedef struct {
    // <TotalBits=7>
    uint8_t opcode;
    // <TotalBits=3>
    uint8_t func3;
    // <TotalBits=5>
    REGISTER rs1;
    // <TotalBits=5>
    REGISTER rs2;
    // <TotalBits=12>
    uint16_t imm_u;
    // <TotalBits=12>
    int16_t imm_s;
} S_INSTRUCTION;
S_INSTRUCTION as_s_instruction(uint32_t instruction);

typedef struct {
    // <TotalBits=7>
    uint8_t opcode;
    // <TotalBits=5>
    REGISTER rd;
    // <TotalBits=20>
    uint32_t imm_u;
    // <TotalBits=20>
    int32_t imm_s;
} U_INSTRUCTION;
U_INSTRUCTION as_u_instruction(uint32_t instruction);

typedef struct {
    // <TotalBits=7>
    uint8_t opcode;
    // <TotalBits=3>
    uint8_t func3;
    // <TotalBits=5>
    REGISTER rs1;
    // <TotalBits=5>
    REGISTER rs2;
    // <TotalBits=13>
    uint16_t imm_u;
    // <TotalBits=13>
    int16_t imm_s;
} B_INSTRUCTION;
B_INSTRUCTION as_b_instruction(uint32_t instruction);

typedef struct {
    // <TotalBits=7>
    uint8_t opcode;
    // <TotalBits=5>
    REGISTER rd;
    // <TotalBits=20>
    uint32_t imm_u;
    // <TotalBits=20>
    int32_t imm_s;
} J_INSTRUCTION;
J_INSTRUCTION as_j_instruction(uint32_t instruction);

#define OPCODE_ADD 0b0110011;
#define FUNC3_ADD 0b000;
#define FUNC7_ADD 0b0000000;
bool is_add_instruction(const R_INSTRUCTION* decoded_instruction);

#define OPCODE_SUB 0b0110011;
#define FUNC3_SUB 0b000;
#define FUNC7_SUB 0b0100000;
bool is_sub_instruction(const R_INSTRUCTION* decoded_instruction);

#define OPCODE_SLL 0b0110011;
#define FUNC3_SLL 0b001;
#define FUNC7_SLL 0b0000000;
bool is_sll_instruction(const R_INSTRUCTION* decoded_instruction);

#define OPCODE_SLT 0b0110011;
#define FUNC3_SLT 0b010;
#define FUNC7_SLT 0b0000000;
bool is_slt_instruction(const R_INSTRUCTION* decoded_instruction);

#define OPCODE_SLTU 0b0110011;
#define FUNC3_SLTU 0b011;
#define FUNC7_SLTU 0b0000000;
bool is_sltu_instruction(const R_INSTRUCTION* decoded_instruction);

#define OPCODE_XOR 0b0110011;
#define FUNC3_XOR 0b100;
#define FUNC7_XOR 0b0000000;
bool is_xor_instruction(const R_INSTRUCTION* decoded_instruction);

#define OPCODE_SRL 0b0110011;
#define FUNC3_SRL 0b101;
#define FUNC7_SRL 0b0000000;
bool is_srl_instruction(const R_INSTRUCTION* decoded_instruction);

#define OPCODE_SRA 0b0110011;
#define FUNC3_SRA 0b101;
#define FUNC7_SRA 0b0100000;
bool is_sra_instruction(const R_INSTRUCTION* decoded_instruction);

#define OPCODE_OR 0b0110011;
#define FUNC3_OR 0b110;
#define FUNC7_OR 0b0000000;
bool is_or_instruction(const R_INSTRUCTION* decoded_instruction);

#define OPCODE_AND 0b0110011;
#define FUNC3_AND 0b111;
#define FUNC7_AND 0b0000000;
bool is_and_instruction(const R_INSTRUCTION* decoded_instruction);

#define OPCODE_ADDI 0b0010011;
#define FUNC3_ADDI 0b000;
bool is_addi_instruction(const I_INSTRUCTION* decoded_instruction);

#define OPCODE_SLTI 0b0010011;
#define FUNC3_SLTI 0b010;
bool is_slti_instruction(const I_INSTRUCTION* decoded_instruction);

#define OPCODE_SLTIU 0b0010011;
#define FUNC3_SLTIU 0b011;
bool is_sltiu_instruction(const I_INSTRUCTION* decoded_instruction);

#define OPCODE_XORI 0b0010011;
#define FUNC3_XORI 0b100;
bool is_xori_instruction(const I_INSTRUCTION* decoded_instruction);

#define OPCODE_ORI 0b0010011;
#define FUNC3_ORI 0b110;
bool is_ori_instruction(const I_INSTRUCTION* decoded_instruction);

#define OPCODE_ANDI 0b0010011;
#define FUNC3_ANDI 0b111;
bool is_andi_instruction(const I_INSTRUCTION* decoded_instruction);

#define OPCODE_SLLI 0b0010011;
#define FUNC3_SLLI 0b001;
bool is_slli_instruction(const I_INSTRUCTION* decoded_instruction);

#define OPCODE_SRLI 0b0010011;
#define FUNC3_SRLI 0b101;
#define FUNC7_SRLI 0b0100000;
bool is_srli_instruction(const I_INSTRUCTION* decoded_instruction);

#define OPCODE_SRAI 0b0010011;
#define FUNC3_SRAI 0b101;
#define FUNC7_SRAI 0b0000000;
bool is_srai_instruction(const I_INSTRUCTION* decoded_instruction);

#define OPCODE_BEQ 0b1100011;
#define FUNC3_BEQ 0b000;
bool is_beq_instruction(const B_INSTRUCTION* decoded_instruction);

#define OPCODE_BNE 0b1100011;
#define FUNC3_BNE 0b001;
bool is_bne_instruction(const B_INSTRUCTION* decoded_instruction);

#define OPCODE_BLT 0b1100011;
#define FUNC3_BLT 0b100;
bool is_blt_instruction(const B_INSTRUCTION* decoded_instruction);

#define OPCODE_BGE 0b1100011;
#define FUNC3_BGE 0b101;
bool is_bge_instruction(const B_INSTRUCTION* decoded_instruction);

#define OPCODE_BLTU 0b1100011;
#define FUNC3_BLTU 0b110;
bool is_bltu_instruction(const B_INSTRUCTION* decoded_instruction);

#define OPCODE_BGEU 0b1100011;
#define FUNC3_BGEU 0b111;
bool is_bgeu_instruction(const B_INSTRUCTION* decoded_instruction);

#define OPCODE_LUI 0b0110111;
bool is_lui_instruction(const U_INSTRUCTION* decoded_instruction);

#define OPCODE_AUIPC 0b0010111;
bool is_auipc_instruction(const U_INSTRUCTION* decoded_instruction);

#define OPCODE_JAL 0b1101111;
bool is_jal_instruction(const J_INSTRUCTION* decoded_instruction);

#define OPCODE_JALR 0b1100111;
#define FUNC3_JALR 0b0;
bool is_jalr_instruction(const I_INSTRUCTION* decoded_instruction);

#define OPCODE_LB 0b0000011;
#define FUNC3_LB 0b000;
bool is_lb_instruction(const I_INSTRUCTION* decoded_instruction);

#define OPCODE_LH 0b0000011;
#define FUNC3_LH 0b001;
bool is_lh_instruction(const I_INSTRUCTION* decoded_instruction);

#define OPCODE_LW 0b0000011;
#define FUNC3_LW 0b010;
bool is_lw_instruction(const I_INSTRUCTION* decoded_instruction);

#define OPCODE_LBU 0b0000011;
#define FUNC3_LBU 0b100;
bool is_lbu_instruction(const I_INSTRUCTION* decoded_instruction);

#define OPCODE_LHU 0b0000011;
#define FUNC3_LHU 0b101;
bool is_lhu_instruction(const I_INSTRUCTION* decoded_instruction);

#define OPCODE_SB 0b0100011;
#define FUNC3_SB 0b000;
bool is_sb_instruction(const S_INSTRUCTION* decoded_instruction);

#define OPCODE_SH 0b0100011;
#define FUNC3_SH 0b001;
bool is_sh_instruction(const S_INSTRUCTION* decoded_instruction);

#define OPCODE_SW 0b0100011;
#define FUNC3_SW 0b010;
bool is_sw_instruction(const S_INSTRUCTION* decoded_instruction);

#define OPCODE_ECALL 0b1110011;
#define FUNC3_ECALL 0b000;
bool is_ecall_instruction(const I_INSTRUCTION* decoded_instruction);

int count_all_instruction_matches(uint32_t encoded_instruction);

char* format_instruction(uint32_t encoded_instruction);

char* format_add_operation(R_INSTRUCTION* decoded_instruction);

char* format_sub_operation(R_INSTRUCTION* decoded_instruction);

char* format_sll_operation(R_INSTRUCTION* decoded_instruction);

char* format_slt_operation(R_INSTRUCTION* decoded_instruction);

char* format_sltu_operation(R_INSTRUCTION* decoded_instruction);

char* format_xor_operation(R_INSTRUCTION* decoded_instruction);

char* format_srl_operation(R_INSTRUCTION* decoded_instruction);

char* format_sra_operation(R_INSTRUCTION* decoded_instruction);

char* format_or_operation(R_INSTRUCTION* decoded_instruction);

char* format_and_operation(R_INSTRUCTION* decoded_instruction);

char* format_addi_operation(I_INSTRUCTION* decoded_instruction);

char* format_slti_operation(I_INSTRUCTION* decoded_instruction);

char* format_sltiu_operation(I_INSTRUCTION* decoded_instruction);

char* format_xori_operation(I_INSTRUCTION* decoded_instruction);

char* format_ori_operation(I_INSTRUCTION* decoded_instruction);

char* format_andi_operation(I_INSTRUCTION* decoded_instruction);

char* format_slli_operation(I_INSTRUCTION* decoded_instruction);

char* format_srli_operation(I_INSTRUCTION* decoded_instruction);

char* format_srai_operation(I_INSTRUCTION* decoded_instruction);

char* format_beq_operation(B_INSTRUCTION* decoded_instruction);

char* format_bne_operation(B_INSTRUCTION* decoded_instruction);

char* format_blt_operation(B_INSTRUCTION* decoded_instruction);

char* format_bge_operation(B_INSTRUCTION* decoded_instruction);

char* format_bltu_operation(B_INSTRUCTION* decoded_instruction);

char* format_bgeu_operation(B_INSTRUCTION* decoded_instruction);

char* format_lui_operation(U_INSTRUCTION* decoded_instruction);

char* format_auipc_operation(U_INSTRUCTION* decoded_instruction);

char* format_jal_operation(J_INSTRUCTION* decoded_instruction);

char* format_jalr_operation(I_INSTRUCTION* decoded_instruction);

char* format_lb_operation(I_INSTRUCTION* decoded_instruction);

char* format_lh_operation(I_INSTRUCTION* decoded_instruction);

char* format_lw_operation(I_INSTRUCTION* decoded_instruction);

char* format_lbu_operation(I_INSTRUCTION* decoded_instruction);

char* format_lhu_operation(I_INSTRUCTION* decoded_instruction);

char* format_sb_operation(S_INSTRUCTION* decoded_instruction);

char* format_sh_operation(S_INSTRUCTION* decoded_instruction);

char* format_sw_operation(S_INSTRUCTION* decoded_instruction);

char* format_ecall_operation(I_INSTRUCTION* decoded_instruction);

#endif
