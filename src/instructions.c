// This file has been generated using `tools/opcode_generator`
// DO NOT EDIT BY HAND

#include <stdbool.h>
#include <stdint.h>
#include "core.h"
#include "instructions.h"

#define get_word_bits(instruction, start, end) \
    ((instruction >> start) & (((uint32_t) ~0) >> (32 + start - end)))

R_INSTRUCTION as_r_instruction(uint32_t instruction) {
    R_INSTRUCTION d = {
        .opcode = (
            // <TotalBits=7>
            // <Start=0> <End=6> <Length=7> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 0, 6) << 0)
            |
            // Unsigned
            0
        ),
        .rd = (
            // <TotalBits=5>
            // <Start=7> <End=11> <Length=5> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 7, 11) << 0)
            |
            // Unsigned
            0
        ),
        .func3 = (
            // <TotalBits=3>
            // <Start=12> <End=14> <Length=3> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 12, 14) << 0)
            |
            // Unsigned
            0
        ),
        .rs1 = (
            // <TotalBits=5>
            // <Start=15> <End=19> <Length=5> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 15, 19) << 0)
            |
            // Unsigned
            0
        ),
        .rs2 = (
            // <TotalBits=5>
            // <Start=20> <End=24> <Length=5> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 20, 24) << 0)
            |
            // Unsigned
            0
        ),
        .func7 = (
            // <TotalBits=7>
            // <Start=25> <End=31> <Length=7> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 25, 31) << 0)
            |
            // Unsigned
            0
        )
    };
    if (d.opcode > (1 << 7))
        FAIL("R_INSTRUCTION.opcode decode error: size %d", d.opcode);
    if (d.rd > (1 << 5))
        FAIL("R_INSTRUCTION.rd decode error: size %d", d.rd);
    if (d.func3 > (1 << 3))
        FAIL("R_INSTRUCTION.func3 decode error: size %d", d.func3);
    if (d.rs1 > (1 << 5))
        FAIL("R_INSTRUCTION.rs1 decode error: size %d", d.rs1);
    if (d.rs2 > (1 << 5))
        FAIL("R_INSTRUCTION.rs2 decode error: size %d", d.rs2);
    if (d.func7 > (1 << 7))
        FAIL("R_INSTRUCTION.func7 decode error: size %d", d.func7);
    return d;
}

I_INSTRUCTION as_i_instruction(uint32_t instruction) {
    I_INSTRUCTION d = {
        .opcode = (
            // <TotalBits=7>
            // <Start=0> <End=6> <Length=7> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 0, 6) << 0)
            |
            // Unsigned
            0
        ),
        .rd = (
            // <TotalBits=5>
            // <Start=7> <End=11> <Length=5> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 7, 11) << 0)
            |
            // Unsigned
            0
        ),
        .func3 = (
            // <TotalBits=3>
            // <Start=12> <End=14> <Length=3> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 12, 14) << 0)
            |
            // Unsigned
            0
        ),
        .rs1 = (
            // <TotalBits=5>
            // <Start=15> <End=19> <Length=5> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 15, 19) << 0)
            |
            // Unsigned
            0
        ),
        .imm = (
            // <TotalBits=13>
            // <Start=null> <End=null> <Length=1> <Offset=0> <Zero=true>
            0
            |
            // <Start=20> <End=31> <Length=12> <Offset=1> <Zero=false>
            (get_word_bits(instruction, 20, 31) << 1)
            |
            // Signed <Bits=13>
            ((instruction >> (13 - 1)) == 0 ? 0 : (0xFFFFFFFF << 13))
        )
    };
    if (d.opcode > (1 << 7))
        FAIL("I_INSTRUCTION.opcode decode error: size %d", d.opcode);
    if (d.rd > (1 << 5))
        FAIL("I_INSTRUCTION.rd decode error: size %d", d.rd);
    if (d.func3 > (1 << 3))
        FAIL("I_INSTRUCTION.func3 decode error: size %d", d.func3);
    if (d.rs1 > (1 << 5))
        FAIL("I_INSTRUCTION.rs1 decode error: size %d", d.rs1);
    if (d.imm > (1 << 12))
        FAIL("I_INSTRUCTION.imm decode error: size %d", d.imm);
    if (d.imm < -(1 << 12) - 1)
        FAIL("I_INSTRUCTION.imm decode error: size %d", d.imm);
    return d;
}

S_INSTRUCTION as_s_instruction(uint32_t instruction) {
    S_INSTRUCTION d = {
        .opcode = (
            // <TotalBits=7>
            // <Start=0> <End=6> <Length=7> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 0, 6) << 0)
            |
            // Unsigned
            0
        ),
        .func3 = (
            // <TotalBits=3>
            // <Start=12> <End=14> <Length=3> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 12, 14) << 0)
            |
            // Unsigned
            0
        ),
        .rs1 = (
            // <TotalBits=5>
            // <Start=15> <End=19> <Length=5> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 15, 19) << 0)
            |
            // Unsigned
            0
        ),
        .rs2 = (
            // <TotalBits=5>
            // <Start=20> <End=24> <Length=5> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 20, 24) << 0)
            |
            // Unsigned
            0
        ),
        .imm = (
            // <TotalBits=12>
            // <Start=7> <End=11> <Length=5> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 7, 11) << 0)
            |
            // <Start=25> <End=31> <Length=7> <Offset=5> <Zero=false>
            (get_word_bits(instruction, 25, 31) << 5)
            |
            // Unsigned
            0
        )
    };
    if (d.opcode > (1 << 7))
        FAIL("S_INSTRUCTION.opcode decode error: size %d", d.opcode);
    if (d.func3 > (1 << 3))
        FAIL("S_INSTRUCTION.func3 decode error: size %d", d.func3);
    if (d.rs1 > (1 << 5))
        FAIL("S_INSTRUCTION.rs1 decode error: size %d", d.rs1);
    if (d.rs2 > (1 << 5))
        FAIL("S_INSTRUCTION.rs2 decode error: size %d", d.rs2);
    if (d.imm > (1 << 12))
        FAIL("S_INSTRUCTION.imm decode error: size %d", d.imm);
    return d;
}

U_INSTRUCTION as_u_instruction(uint32_t instruction) {
    U_INSTRUCTION d = {
        .opcode = (
            // <TotalBits=7>
            // <Start=0> <End=6> <Length=7> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 0, 6) << 0)
            |
            // Unsigned
            0
        ),
        .rd = (
            // <TotalBits=5>
            // <Start=7> <End=11> <Length=5> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 7, 11) << 0)
            |
            // Unsigned
            0
        ),
        .imm = (
            // <TotalBits=20>
            // <Start=12> <End=31> <Length=20> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 12, 31) << 0)
            |
            // Signed <Bits=20>
            ((instruction >> (20 - 1)) == 0 ? 0 : (0xFFFFFFFF << 20))
        )
    };
    if (d.opcode > (1 << 7))
        FAIL("U_INSTRUCTION.opcode decode error: size %d", d.opcode);
    if (d.rd > (1 << 5))
        FAIL("U_INSTRUCTION.rd decode error: size %d", d.rd);
    if (d.imm > (1 << 19))
        FAIL("U_INSTRUCTION.imm decode error: size %d", d.imm);
    if (d.imm < -(1 << 19) - 1)
        FAIL("U_INSTRUCTION.imm decode error: size %d", d.imm);
    return d;
}

B_INSTRUCTION as_b_instruction(uint32_t instruction) {
    B_INSTRUCTION d = {
        .opcode = (
            // <TotalBits=7>
            // <Start=0> <End=6> <Length=7> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 0, 6) << 0)
            |
            // Unsigned
            0
        ),
        .func3 = (
            // <TotalBits=3>
            // <Start=12> <End=14> <Length=3> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 12, 14) << 0)
            |
            // Unsigned
            0
        ),
        .rs1 = (
            // <TotalBits=5>
            // <Start=15> <End=19> <Length=5> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 15, 19) << 0)
            |
            // Unsigned
            0
        ),
        .rs2 = (
            // <TotalBits=5>
            // <Start=20> <End=24> <Length=5> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 20, 24) << 0)
            |
            // Unsigned
            0
        ),
        .imm = (
            // <TotalBits=12>
            // <Start=7> <End=11> <Length=5> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 7, 11) << 0)
            |
            // <Start=25> <End=31> <Length=7> <Offset=5> <Zero=false>
            (get_word_bits(instruction, 25, 31) << 5)
            |
            // Unsigned
            0
        )
    };
    if (d.opcode > (1 << 7))
        FAIL("B_INSTRUCTION.opcode decode error: size %d", d.opcode);
    if (d.func3 > (1 << 3))
        FAIL("B_INSTRUCTION.func3 decode error: size %d", d.func3);
    if (d.rs1 > (1 << 5))
        FAIL("B_INSTRUCTION.rs1 decode error: size %d", d.rs1);
    if (d.rs2 > (1 << 5))
        FAIL("B_INSTRUCTION.rs2 decode error: size %d", d.rs2);
    if (d.imm > (1 << 12))
        FAIL("B_INSTRUCTION.imm decode error: size %d", d.imm);
    return d;
}

J_INSTRUCTION as_j_instruction(uint32_t instruction) {
    J_INSTRUCTION d = {
        .opcode = (
            // <TotalBits=7>
            // <Start=0> <End=6> <Length=7> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 0, 6) << 0)
            |
            // Unsigned
            0
        ),
        .rd = (
            // <TotalBits=5>
            // <Start=7> <End=11> <Length=5> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 7, 11) << 0)
            |
            // Unsigned
            0
        ),
        .imm = (
            // <TotalBits=20>
            // <Start=12> <End=31> <Length=20> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 12, 31) << 0)
            |
            // Unsigned
            0
        )
    };
    if (d.opcode > (1 << 7))
        FAIL("J_INSTRUCTION.opcode decode error: size %d", d.opcode);
    if (d.rd > (1 << 5))
        FAIL("J_INSTRUCTION.rd decode error: size %d", d.rd);
    if (d.imm > (1 << 20))
        FAIL("J_INSTRUCTION.imm decode error: size %d", d.imm);
    return d;
}

bool is_add_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_add_instruction");
    if (decoded_instruction->opcode != 0b0110011) return false;
    if (decoded_instruction->func3 != 0b000) return false;
    if (decoded_instruction->func7 != 0b0000000) return false;
    return true;
}

bool is_sub_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_sub_instruction");
    if (decoded_instruction->opcode != 0b0110011) return false;
    if (decoded_instruction->func3 != 0b000) return false;
    if (decoded_instruction->func7 != 0b0100000) return false;
    return true;
}

bool is_sll_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_sll_instruction");
    if (decoded_instruction->opcode != 0b0110011) return false;
    if (decoded_instruction->func3 != 0b001) return false;
    if (decoded_instruction->func7 != 0b0000000) return false;
    return true;
}

bool is_slt_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_slt_instruction");
    if (decoded_instruction->opcode != 0b0110011) return false;
    if (decoded_instruction->func3 != 0b010) return false;
    if (decoded_instruction->func7 != 0b0000000) return false;
    return true;
}

bool is_sltu_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_sltu_instruction");
    if (decoded_instruction->opcode != 0b0110011) return false;
    if (decoded_instruction->func3 != 0b011) return false;
    if (decoded_instruction->func7 != 0b0000000) return false;
    return true;
}

bool is_xor_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_xor_instruction");
    if (decoded_instruction->opcode != 0b0110011) return false;
    if (decoded_instruction->func3 != 0b100) return false;
    if (decoded_instruction->func7 != 0b0000000) return false;
    return true;
}

bool is_srl_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_srl_instruction");
    if (decoded_instruction->opcode != 0b0110011) return false;
    if (decoded_instruction->func3 != 0b101) return false;
    if (decoded_instruction->func7 != 0b0000000) return false;
    return true;
}

bool is_sra_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_sra_instruction");
    if (decoded_instruction->opcode != 0b0110011) return false;
    if (decoded_instruction->func3 != 0b101) return false;
    if (decoded_instruction->func7 != 0b0100000) return false;
    return true;
}

bool is_or_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_or_instruction");
    if (decoded_instruction->opcode != 0b0110011) return false;
    if (decoded_instruction->func3 != 0b110) return false;
    if (decoded_instruction->func7 != 0b0000000) return false;
    return true;
}

bool is_and_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_and_instruction");
    if (decoded_instruction->opcode != 0b0110011) return false;
    if (decoded_instruction->func3 != 0b111) return false;
    if (decoded_instruction->func7 != 0b0000000) return false;
    return true;
}

bool is_addi_instruction(const I_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_addi_instruction");
    if (decoded_instruction->opcode != 0b0010011) return false;
    if (decoded_instruction->func3 != 0b000) return false;
    return true;
}

bool is_slti_instruction(const I_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_slti_instruction");
    if (decoded_instruction->opcode != 0b0010011) return false;
    if (decoded_instruction->func3 != 0b010) return false;
    return true;
}

bool is_sltiu_instruction(const I_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_sltiu_instruction");
    if (decoded_instruction->opcode != 0b0010011) return false;
    if (decoded_instruction->func3 != 0b011) return false;
    return true;
}

bool is_xori_instruction(const I_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_xori_instruction");
    if (decoded_instruction->opcode != 0b0010011) return false;
    if (decoded_instruction->func3 != 0b100) return false;
    return true;
}

bool is_ori_instruction(const I_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_ori_instruction");
    if (decoded_instruction->opcode != 0b0010011) return false;
    if (decoded_instruction->func3 != 0b110) return false;
    return true;
}

bool is_andi_instruction(const I_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_andi_instruction");
    if (decoded_instruction->opcode != 0b0010011) return false;
    if (decoded_instruction->func3 != 0b111) return false;
    return true;
}

bool is_slli_instruction(const I_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_slli_instruction");
    if (decoded_instruction->opcode != 0b0010011) return false;
    if (decoded_instruction->func3 != 0b001) return false;
    return true;
}

bool is_srli_instruction(const I_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_srli_instruction");
    if (decoded_instruction->opcode != 0b0010011) return false;
    if (decoded_instruction->func3 != 0b101) return false;
    return true;
}

bool is_srai_instruction(const I_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_srai_instruction");
    if (decoded_instruction->opcode != 0b0010011) return false;
    if (decoded_instruction->func3 != 0b101) return false;
    return true;
}

bool is_beq_instruction(const B_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_beq_instruction");
    if (decoded_instruction->opcode != 0b1100011) return false;
    if (decoded_instruction->func3 != 0b000) return false;
    return true;
}

bool is_bne_instruction(const B_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_bne_instruction");
    if (decoded_instruction->opcode != 0b1100011) return false;
    if (decoded_instruction->func3 != 0b001) return false;
    return true;
}

bool is_blt_instruction(const B_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_blt_instruction");
    if (decoded_instruction->opcode != 0b1100011) return false;
    if (decoded_instruction->func3 != 0b100) return false;
    return true;
}

bool is_bge_instruction(const B_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_bge_instruction");
    if (decoded_instruction->opcode != 0b1100011) return false;
    if (decoded_instruction->func3 != 0b101) return false;
    return true;
}

bool is_bltu_instruction(const B_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_bltu_instruction");
    if (decoded_instruction->opcode != 0b1100011) return false;
    if (decoded_instruction->func3 != 0b110) return false;
    return true;
}

bool is_bgeu_instruction(const B_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_bgeu_instruction");
    if (decoded_instruction->opcode != 0b1100011) return false;
    if (decoded_instruction->func3 != 0b111) return false;
    return true;
}

bool is_lui_instruction(const U_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_lui_instruction");
    if (decoded_instruction->opcode != 0b0110111) return false;
    return true;
}

bool is_auipc_instruction(const U_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_auipc_instruction");
    if (decoded_instruction->opcode != 0b0010111) return false;
    return true;
}

bool is_jal_instruction(const J_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_jal_instruction");
    if (decoded_instruction->opcode != 0b1101111) return false;
    return true;
}

bool is_jalr_instruction(const I_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_jalr_instruction");
    if (decoded_instruction->opcode != 0b1100111) return false;
    if (decoded_instruction->func3 != 0b0) return false;
    return true;
}

bool is_lb_instruction(const I_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_lb_instruction");
    if (decoded_instruction->opcode != 0b0000011) return false;
    if (decoded_instruction->func3 != 0b000) return false;
    return true;
}

bool is_lh_instruction(const I_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_lh_instruction");
    if (decoded_instruction->opcode != 0b0000111) return false;
    if (decoded_instruction->func3 != 0b001) return false;
    return true;
}

bool is_lw_instruction(const I_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_lw_instruction");
    if (decoded_instruction->opcode != 0b0000011) return false;
    if (decoded_instruction->func3 != 0b010) return false;
    return true;
}

bool is_lbu_instruction(const I_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_lbu_instruction");
    if (decoded_instruction->opcode != 0b0000011) return false;
    if (decoded_instruction->func3 != 0b100) return false;
    return true;
}

bool is_lhu_instruction(const I_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_lhu_instruction");
    if (decoded_instruction->opcode != 0b0000011) return false;
    if (decoded_instruction->func3 != 0b101) return false;
    return true;
}

bool is_sb_instruction(const S_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_sb_instruction");
    if (decoded_instruction->opcode != 0b0100011) return false;
    if (decoded_instruction->func3 != 0b000) return false;
    return true;
}

bool is_sh_instruction(const S_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_sh_instruction");
    if (decoded_instruction->opcode != 0b0100011) return false;
    if (decoded_instruction->func3 != 0b001) return false;
    return true;
}

bool is_sw_instruction(const S_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_sw_instruction");
    if (decoded_instruction->opcode != 0b0100011) return false;
    if (decoded_instruction->func3 != 0b010) return false;
    return true;
}

bool is_sbu_instruction(const S_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_sbu_instruction");
    if (decoded_instruction->opcode != 0b0100011) return false;
    if (decoded_instruction->func3 != 0b100) return false;
    return true;
}

bool is_shu_instruction(const S_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_shu_instruction");
    if (decoded_instruction->opcode != 0b0100011) return false;
    if (decoded_instruction->func3 != 0b101) return false;
    return true;
}
