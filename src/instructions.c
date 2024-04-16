// This file has been generated using `tools/opcode_generator`
// DO NOT EDIT BY HAND

#include <stdbool.h>
#include <stdint.h>
#include "core.h"
#include "instructions.h"

char format_memory[128];

#define get_word_bits(instruction, start, end) \
    ((instruction >> start) & (((uint32_t) ~0) >> (32 + start - end - 1)))

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
        .func7 = (
            // <TotalBits=7>
            // <Start=25> <End=31> <Length=7> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 25, 31) << 0)
            |
            // Unsigned
            0
        ),
        .imm_u = (
            // <TotalBits=12>
            // <Start=20> <End=31> <Length=12> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 20, 31) << 0)
            |
            // Unsigned
            0
        ),
        .imm_s = (
            // <TotalBits=12>
            // <Start=20> <End=31> <Length=12> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 20, 31) << 0)
            |
            // Signed <LastBit=31>
            (((1 << 31) & instruction) == 0 ? 0 : ((~0) << 11))
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
    if (d.func7 > (1 << 7))
        FAIL("I_INSTRUCTION.func7 decode error: size %d", d.func7);
    if (d.imm_u > (1 << 12))
        FAIL("I_INSTRUCTION.imm_u decode error: size %d", d.imm_u);
    if (d.imm_s > (1 << 11))
        FAIL("I_INSTRUCTION.imm_s decode error: size %d", d.imm_s);
    if (d.imm_s < -(1 << 11) - 1)
        FAIL("I_INSTRUCTION.imm_s decode error: size %d", d.imm_s);
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
        .imm_u = (
            // <TotalBits=12>
            // <Start=7> <End=11> <Length=5> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 7, 11) << 0)
            |
            // <Start=25> <End=31> <Length=7> <Offset=5> <Zero=false>
            (get_word_bits(instruction, 25, 31) << 5)
            |
            // Unsigned
            0
        ),
        .imm_s = (
            // <TotalBits=12>
            // <Start=7> <End=11> <Length=5> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 7, 11) << 0)
            |
            // <Start=25> <End=31> <Length=7> <Offset=5> <Zero=false>
            (get_word_bits(instruction, 25, 31) << 5)
            |
            // Signed <LastBit=31>
            (((1 << 31) & instruction) == 0 ? 0 : ((~0) << 11))
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
    if (d.imm_u > (1 << 12))
        FAIL("S_INSTRUCTION.imm_u decode error: size %d", d.imm_u);
    if (d.imm_s > (1 << 11))
        FAIL("S_INSTRUCTION.imm_s decode error: size %d", d.imm_s);
    if (d.imm_s < -(1 << 11) - 1)
        FAIL("S_INSTRUCTION.imm_s decode error: size %d", d.imm_s);
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
        .imm_u = (
            // <TotalBits=20>
            // <Start=12> <End=31> <Length=20> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 12, 31) << 0)
            |
            // Unsigned
            0
        ),
        .imm_s = (
            // <TotalBits=20>
            // <Start=12> <End=31> <Length=20> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 12, 31) << 0)
            |
            // Signed <LastBit=31>
            (((1 << 31) & instruction) == 0 ? 0 : ((~0) << 19))
        )
    };
    if (d.opcode > (1 << 7))
        FAIL("U_INSTRUCTION.opcode decode error: size %d", d.opcode);
    if (d.rd > (1 << 5))
        FAIL("U_INSTRUCTION.rd decode error: size %d", d.rd);
    if (d.imm_u > (1 << 20))
        FAIL("U_INSTRUCTION.imm_u decode error: size %d", d.imm_u);
    if (d.imm_s > (1 << 19))
        FAIL("U_INSTRUCTION.imm_s decode error: size %d", d.imm_s);
    if (d.imm_s < -(1 << 19) - 1)
        FAIL("U_INSTRUCTION.imm_s decode error: size %d", d.imm_s);
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
        .imm_u = (
            // <TotalBits=13>
            // <Start=null> <End=null> <Length=1> <Offset=0> <Zero=true>
            0
            |
            // <Start=8> <End=11> <Length=4> <Offset=1> <Zero=false>
            (get_word_bits(instruction, 8, 11) << 1)
            |
            // <Start=25> <End=30> <Length=6> <Offset=5> <Zero=false>
            (get_word_bits(instruction, 25, 30) << 5)
            |
            // <Start=7> <End=7> <Length=1> <Offset=11> <Zero=false>
            (get_word_bits(instruction, 7, 7) << 11)
            |
            // <Start=31> <End=31> <Length=1> <Offset=12> <Zero=false>
            (get_word_bits(instruction, 31, 31) << 12)
            |
            // Unsigned
            0
        ),
        .imm_s = (
            // <TotalBits=13>
            // <Start=null> <End=null> <Length=1> <Offset=0> <Zero=true>
            0
            |
            // <Start=8> <End=11> <Length=4> <Offset=1> <Zero=false>
            (get_word_bits(instruction, 8, 11) << 1)
            |
            // <Start=25> <End=30> <Length=6> <Offset=5> <Zero=false>
            (get_word_bits(instruction, 25, 30) << 5)
            |
            // <Start=7> <End=7> <Length=1> <Offset=11> <Zero=false>
            (get_word_bits(instruction, 7, 7) << 11)
            |
            // <Start=31> <End=31> <Length=1> <Offset=12> <Zero=false>
            (get_word_bits(instruction, 31, 31) << 12)
            |
            // Signed <LastBit=31>
            (((1 << 31) & instruction) == 0 ? 0 : ((~0) << 12))
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
    if (d.imm_u > (1 << 13))
        FAIL("B_INSTRUCTION.imm_u decode error: size %d", d.imm_u);
    if (d.imm_s > (1 << 12))
        FAIL("B_INSTRUCTION.imm_s decode error: size %d", d.imm_s);
    if (d.imm_s < -(1 << 12) - 1)
        FAIL("B_INSTRUCTION.imm_s decode error: size %d", d.imm_s);
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
        .imm_u = (
            // <TotalBits=21>
            // <Start=null> <End=null> <Length=1> <Offset=0> <Zero=true>
            0
            |
            // <Start=21> <End=24> <Length=4> <Offset=1> <Zero=false>
            (get_word_bits(instruction, 21, 24) << 1)
            |
            // <Start=25> <End=30> <Length=6> <Offset=5> <Zero=false>
            (get_word_bits(instruction, 25, 30) << 5)
            |
            // <Start=20> <End=20> <Length=1> <Offset=11> <Zero=false>
            (get_word_bits(instruction, 20, 20) << 11)
            |
            // <Start=12> <End=19> <Length=8> <Offset=12> <Zero=false>
            (get_word_bits(instruction, 12, 19) << 12)
            |
            // <Start=31> <End=31> <Length=1> <Offset=20> <Zero=false>
            (get_word_bits(instruction, 31, 31) << 20)
            |
            // Unsigned
            0
        ),
        .imm_s = (
            // <TotalBits=21>
            // <Start=null> <End=null> <Length=1> <Offset=0> <Zero=true>
            0
            |
            // <Start=21> <End=24> <Length=4> <Offset=1> <Zero=false>
            (get_word_bits(instruction, 21, 24) << 1)
            |
            // <Start=25> <End=30> <Length=6> <Offset=5> <Zero=false>
            (get_word_bits(instruction, 25, 30) << 5)
            |
            // <Start=20> <End=20> <Length=1> <Offset=11> <Zero=false>
            (get_word_bits(instruction, 20, 20) << 11)
            |
            // <Start=12> <End=19> <Length=8> <Offset=12> <Zero=false>
            (get_word_bits(instruction, 12, 19) << 12)
            |
            // <Start=31> <End=31> <Length=1> <Offset=20> <Zero=false>
            (get_word_bits(instruction, 31, 31) << 20)
            |
            // Signed <LastBit=31>
            (((1 << 31) & instruction) == 0 ? 0 : ((~0) << 20))
        )
    };
    if (d.opcode > (1 << 7))
        FAIL("J_INSTRUCTION.opcode decode error: size %d", d.opcode);
    if (d.rd > (1 << 5))
        FAIL("J_INSTRUCTION.rd decode error: size %d", d.rd);
    if (d.imm_u > (1 << 21))
        FAIL("J_INSTRUCTION.imm_u decode error: size %d", d.imm_u);
    if (d.imm_s > (1 << 20))
        FAIL("J_INSTRUCTION.imm_s decode error: size %d", d.imm_s);
    if (d.imm_s < -(1 << 20) - 1)
        FAIL("J_INSTRUCTION.imm_s decode error: size %d", d.imm_s);
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
    if (decoded_instruction->func7 != 0b0000000) return false;
    return true;
}

bool is_srai_instruction(const I_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_srai_instruction");
    if (decoded_instruction->opcode != 0b0010011) return false;
    if (decoded_instruction->func3 != 0b101) return false;
    if (decoded_instruction->func7 != 0b0100000) return false;
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
    if (decoded_instruction->opcode != 0b0000011) return false;
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

bool is_ecall_instruction(const I_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_ecall_instruction");
    if (decoded_instruction->opcode != 0b1110011) return false;
    if (decoded_instruction->func3 != 0b000) return false;
    return true;
}

bool is_mul_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_mul_instruction");
    if (decoded_instruction->opcode != 0b0110011) return false;
    if (decoded_instruction->func3 != 0b000) return false;
    if (decoded_instruction->func7 != 0b0000001) return false;
    return true;
}

bool is_mulh_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_mulh_instruction");
    if (decoded_instruction->opcode != 0b0110011) return false;
    if (decoded_instruction->func3 != 0b001) return false;
    if (decoded_instruction->func7 != 0b0000001) return false;
    return true;
}

bool is_mulhsu_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_mulhsu_instruction");
    if (decoded_instruction->opcode != 0b0110011) return false;
    if (decoded_instruction->func3 != 0b010) return false;
    if (decoded_instruction->func7 != 0b0000001) return false;
    return true;
}

bool is_mulhu_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_mulhu_instruction");
    if (decoded_instruction->opcode != 0b0110011) return false;
    if (decoded_instruction->func3 != 0b011) return false;
    if (decoded_instruction->func7 != 0b0000001) return false;
    return true;
}

bool is_div_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_div_instruction");
    if (decoded_instruction->opcode != 0b0110011) return false;
    if (decoded_instruction->func3 != 0b100) return false;
    if (decoded_instruction->func7 != 0b0000001) return false;
    return true;
}

bool is_divu_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_divu_instruction");
    if (decoded_instruction->opcode != 0b0110011) return false;
    if (decoded_instruction->func3 != 0b101) return false;
    if (decoded_instruction->func7 != 0b0000001) return false;
    return true;
}

bool is_rem_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_rem_instruction");
    if (decoded_instruction->opcode != 0b0110011) return false;
    if (decoded_instruction->func3 != 0b110) return false;
    if (decoded_instruction->func7 != 0b0000001) return false;
    return true;
}

bool is_remu_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_remu_instruction");
    if (decoded_instruction->opcode != 0b0110011) return false;
    if (decoded_instruction->func3 != 0b111) return false;
    if (decoded_instruction->func7 != 0b0000001) return false;
    return true;
}

int count_all_instruction_matches(uint32_t encoded_instruction) {
    int count = 0;
    R_INSTRUCTION r_instruction = as_r_instruction(encoded_instruction);
    I_INSTRUCTION i_instruction = as_i_instruction(encoded_instruction);
    S_INSTRUCTION s_instruction = as_s_instruction(encoded_instruction);
    U_INSTRUCTION u_instruction = as_u_instruction(encoded_instruction);
    B_INSTRUCTION b_instruction = as_b_instruction(encoded_instruction);
    J_INSTRUCTION j_instruction = as_j_instruction(encoded_instruction);
    count += is_add_instruction(&r_instruction);
    count += is_sub_instruction(&r_instruction);
    count += is_sll_instruction(&r_instruction);
    count += is_slt_instruction(&r_instruction);
    count += is_sltu_instruction(&r_instruction);
    count += is_xor_instruction(&r_instruction);
    count += is_srl_instruction(&r_instruction);
    count += is_sra_instruction(&r_instruction);
    count += is_or_instruction(&r_instruction);
    count += is_and_instruction(&r_instruction);
    count += is_addi_instruction(&i_instruction);
    count += is_slti_instruction(&i_instruction);
    count += is_sltiu_instruction(&i_instruction);
    count += is_xori_instruction(&i_instruction);
    count += is_ori_instruction(&i_instruction);
    count += is_andi_instruction(&i_instruction);
    count += is_slli_instruction(&i_instruction);
    count += is_srli_instruction(&i_instruction);
    count += is_srai_instruction(&i_instruction);
    count += is_beq_instruction(&b_instruction);
    count += is_bne_instruction(&b_instruction);
    count += is_blt_instruction(&b_instruction);
    count += is_bge_instruction(&b_instruction);
    count += is_bltu_instruction(&b_instruction);
    count += is_bgeu_instruction(&b_instruction);
    count += is_lui_instruction(&u_instruction);
    count += is_auipc_instruction(&u_instruction);
    count += is_jal_instruction(&j_instruction);
    count += is_jalr_instruction(&i_instruction);
    count += is_lb_instruction(&i_instruction);
    count += is_lh_instruction(&i_instruction);
    count += is_lw_instruction(&i_instruction);
    count += is_lbu_instruction(&i_instruction);
    count += is_lhu_instruction(&i_instruction);
    count += is_sb_instruction(&s_instruction);
    count += is_sh_instruction(&s_instruction);
    count += is_sw_instruction(&s_instruction);
    count += is_ecall_instruction(&i_instruction);
    count += is_mul_instruction(&r_instruction);
    count += is_mulh_instruction(&r_instruction);
    count += is_mulhsu_instruction(&r_instruction);
    count += is_mulhu_instruction(&r_instruction);
    count += is_div_instruction(&r_instruction);
    count += is_divu_instruction(&r_instruction);
    count += is_rem_instruction(&r_instruction);
    count += is_remu_instruction(&r_instruction);
    return count;
}

char* format_instruction(uint32_t encoded_instruction) {
    R_INSTRUCTION r_instruction = as_r_instruction(encoded_instruction);
    I_INSTRUCTION i_instruction = as_i_instruction(encoded_instruction);
    S_INSTRUCTION s_instruction = as_s_instruction(encoded_instruction);
    U_INSTRUCTION u_instruction = as_u_instruction(encoded_instruction);
    B_INSTRUCTION b_instruction = as_b_instruction(encoded_instruction);
    J_INSTRUCTION j_instruction = as_j_instruction(encoded_instruction);
    if (is_add_instruction(&r_instruction)) return format_add_operation(&r_instruction);
    if (is_sub_instruction(&r_instruction)) return format_sub_operation(&r_instruction);
    if (is_sll_instruction(&r_instruction)) return format_sll_operation(&r_instruction);
    if (is_slt_instruction(&r_instruction)) return format_slt_operation(&r_instruction);
    if (is_sltu_instruction(&r_instruction)) return format_sltu_operation(&r_instruction);
    if (is_xor_instruction(&r_instruction)) return format_xor_operation(&r_instruction);
    if (is_srl_instruction(&r_instruction)) return format_srl_operation(&r_instruction);
    if (is_sra_instruction(&r_instruction)) return format_sra_operation(&r_instruction);
    if (is_or_instruction(&r_instruction)) return format_or_operation(&r_instruction);
    if (is_and_instruction(&r_instruction)) return format_and_operation(&r_instruction);
    if (is_addi_instruction(&i_instruction)) return format_addi_operation(&i_instruction);
    if (is_slti_instruction(&i_instruction)) return format_slti_operation(&i_instruction);
    if (is_sltiu_instruction(&i_instruction)) return format_sltiu_operation(&i_instruction);
    if (is_xori_instruction(&i_instruction)) return format_xori_operation(&i_instruction);
    if (is_ori_instruction(&i_instruction)) return format_ori_operation(&i_instruction);
    if (is_andi_instruction(&i_instruction)) return format_andi_operation(&i_instruction);
    if (is_slli_instruction(&i_instruction)) return format_slli_operation(&i_instruction);
    if (is_srli_instruction(&i_instruction)) return format_srli_operation(&i_instruction);
    if (is_srai_instruction(&i_instruction)) return format_srai_operation(&i_instruction);
    if (is_beq_instruction(&b_instruction)) return format_beq_operation(&b_instruction);
    if (is_bne_instruction(&b_instruction)) return format_bne_operation(&b_instruction);
    if (is_blt_instruction(&b_instruction)) return format_blt_operation(&b_instruction);
    if (is_bge_instruction(&b_instruction)) return format_bge_operation(&b_instruction);
    if (is_bltu_instruction(&b_instruction)) return format_bltu_operation(&b_instruction);
    if (is_bgeu_instruction(&b_instruction)) return format_bgeu_operation(&b_instruction);
    if (is_lui_instruction(&u_instruction)) return format_lui_operation(&u_instruction);
    if (is_auipc_instruction(&u_instruction)) return format_auipc_operation(&u_instruction);
    if (is_jal_instruction(&j_instruction)) return format_jal_operation(&j_instruction);
    if (is_jalr_instruction(&i_instruction)) return format_jalr_operation(&i_instruction);
    if (is_lb_instruction(&i_instruction)) return format_lb_operation(&i_instruction);
    if (is_lh_instruction(&i_instruction)) return format_lh_operation(&i_instruction);
    if (is_lw_instruction(&i_instruction)) return format_lw_operation(&i_instruction);
    if (is_lbu_instruction(&i_instruction)) return format_lbu_operation(&i_instruction);
    if (is_lhu_instruction(&i_instruction)) return format_lhu_operation(&i_instruction);
    if (is_sb_instruction(&s_instruction)) return format_sb_operation(&s_instruction);
    if (is_sh_instruction(&s_instruction)) return format_sh_operation(&s_instruction);
    if (is_sw_instruction(&s_instruction)) return format_sw_operation(&s_instruction);
    if (is_ecall_instruction(&i_instruction)) return format_ecall_operation(&i_instruction);
    if (is_mul_instruction(&r_instruction)) return format_mul_operation(&r_instruction);
    if (is_mulh_instruction(&r_instruction)) return format_mulh_operation(&r_instruction);
    if (is_mulhsu_instruction(&r_instruction)) return format_mulhsu_operation(&r_instruction);
    if (is_mulhu_instruction(&r_instruction)) return format_mulhu_operation(&r_instruction);
    if (is_div_instruction(&r_instruction)) return format_div_operation(&r_instruction);
    if (is_divu_instruction(&r_instruction)) return format_divu_operation(&r_instruction);
    if (is_rem_instruction(&r_instruction)) return format_rem_operation(&r_instruction);
    if (is_remu_instruction(&r_instruction)) return format_remu_operation(&r_instruction);
    return NULL;
}

char* format_add_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_add_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "ADD <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
}

char* format_sub_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_sub_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "SUB <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
}

char* format_sll_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_sll_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "SLL <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
}

char* format_slt_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_slt_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "SLT <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
}

char* format_sltu_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_sltu_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "SLTU <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
}

char* format_xor_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_xor_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "XOR <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
}

char* format_srl_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_srl_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "SRL <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
}

char* format_sra_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_sra_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "SRA <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
}

char* format_or_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_or_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "OR <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
}

char* format_and_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_and_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "AND <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
}

char* format_addi_operation(I_INSTRUCTION* decoded_instruction) {
    if (!is_addi_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "ADDI <rd=%s> <rs1=%s> <imm_u=%u> <imm_s=%d>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        decoded_instruction->imm_u,
        decoded_instruction->imm_s
    );
    return format_memory;
}

char* format_slti_operation(I_INSTRUCTION* decoded_instruction) {
    if (!is_slti_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "SLTI <rd=%s> <rs1=%s> <imm_u=%u> <imm_s=%d>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        decoded_instruction->imm_u,
        decoded_instruction->imm_s
    );
    return format_memory;
}

char* format_sltiu_operation(I_INSTRUCTION* decoded_instruction) {
    if (!is_sltiu_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "SLTIU <rd=%s> <rs1=%s> <imm_u=%u> <imm_s=%d>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        decoded_instruction->imm_u,
        decoded_instruction->imm_s
    );
    return format_memory;
}

char* format_xori_operation(I_INSTRUCTION* decoded_instruction) {
    if (!is_xori_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "XORI <rd=%s> <rs1=%s> <imm_u=%u> <imm_s=%d>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        decoded_instruction->imm_u,
        decoded_instruction->imm_s
    );
    return format_memory;
}

char* format_ori_operation(I_INSTRUCTION* decoded_instruction) {
    if (!is_ori_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "ORI <rd=%s> <rs1=%s> <imm_u=%u> <imm_s=%d>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        decoded_instruction->imm_u,
        decoded_instruction->imm_s
    );
    return format_memory;
}

char* format_andi_operation(I_INSTRUCTION* decoded_instruction) {
    if (!is_andi_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "ANDI <rd=%s> <rs1=%s> <imm_u=%u> <imm_s=%d>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        decoded_instruction->imm_u,
        decoded_instruction->imm_s
    );
    return format_memory;
}

char* format_slli_operation(I_INSTRUCTION* decoded_instruction) {
    if (!is_slli_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "SLLI <rd=%s> <rs1=%s> <imm_u=%u> <imm_s=%d>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        decoded_instruction->imm_u,
        decoded_instruction->imm_s
    );
    return format_memory;
}

char* format_srli_operation(I_INSTRUCTION* decoded_instruction) {
    if (!is_srli_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "SRLI <rd=%s> <rs1=%s> <imm_u=%u> <imm_s=%d>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        decoded_instruction->imm_u,
        decoded_instruction->imm_s
    );
    return format_memory;
}

char* format_srai_operation(I_INSTRUCTION* decoded_instruction) {
    if (!is_srai_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "SRAI <rd=%s> <rs1=%s> <imm_u=%u> <imm_s=%d>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        decoded_instruction->imm_u,
        decoded_instruction->imm_s
    );
    return format_memory;
}

char* format_beq_operation(B_INSTRUCTION* decoded_instruction) {
    if (!is_beq_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "BEQ <rs1=%s> <rs2=%s> <imm_u=%u> <imm_s=%d>",
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2),
        decoded_instruction->imm_u,
        decoded_instruction->imm_s
    );
    return format_memory;
}

char* format_bne_operation(B_INSTRUCTION* decoded_instruction) {
    if (!is_bne_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "BNE <rs1=%s> <rs2=%s> <imm_u=%u> <imm_s=%d>",
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2),
        decoded_instruction->imm_u,
        decoded_instruction->imm_s
    );
    return format_memory;
}

char* format_blt_operation(B_INSTRUCTION* decoded_instruction) {
    if (!is_blt_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "BLT <rs1=%s> <rs2=%s> <imm_u=%u> <imm_s=%d>",
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2),
        decoded_instruction->imm_u,
        decoded_instruction->imm_s
    );
    return format_memory;
}

char* format_bge_operation(B_INSTRUCTION* decoded_instruction) {
    if (!is_bge_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "BGE <rs1=%s> <rs2=%s> <imm_u=%u> <imm_s=%d>",
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2),
        decoded_instruction->imm_u,
        decoded_instruction->imm_s
    );
    return format_memory;
}

char* format_bltu_operation(B_INSTRUCTION* decoded_instruction) {
    if (!is_bltu_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "BLTU <rs1=%s> <rs2=%s> <imm_u=%u> <imm_s=%d>",
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2),
        decoded_instruction->imm_u,
        decoded_instruction->imm_s
    );
    return format_memory;
}

char* format_bgeu_operation(B_INSTRUCTION* decoded_instruction) {
    if (!is_bgeu_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "BGEU <rs1=%s> <rs2=%s> <imm_u=%u> <imm_s=%d>",
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2),
        decoded_instruction->imm_u,
        decoded_instruction->imm_s
    );
    return format_memory;
}

char* format_lui_operation(U_INSTRUCTION* decoded_instruction) {
    if (!is_lui_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "LUI <rd=%s> <imm_u=%u> <imm_s=%d>",
        register_to_name(decoded_instruction->rd),
        decoded_instruction->imm_u,
        decoded_instruction->imm_s
    );
    return format_memory;
}

char* format_auipc_operation(U_INSTRUCTION* decoded_instruction) {
    if (!is_auipc_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "AUIPC <rd=%s> <imm_u=%u> <imm_s=%d>",
        register_to_name(decoded_instruction->rd),
        decoded_instruction->imm_u,
        decoded_instruction->imm_s
    );
    return format_memory;
}

char* format_jal_operation(J_INSTRUCTION* decoded_instruction) {
    if (!is_jal_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "JAL <rd=%s> <imm_u=%u> <imm_s=%d>",
        register_to_name(decoded_instruction->rd),
        decoded_instruction->imm_u,
        decoded_instruction->imm_s
    );
    return format_memory;
}

char* format_jalr_operation(I_INSTRUCTION* decoded_instruction) {
    if (!is_jalr_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "JALR <rd=%s> <rs1=%s> <imm_u=%u> <imm_s=%d>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        decoded_instruction->imm_u,
        decoded_instruction->imm_s
    );
    return format_memory;
}

char* format_lb_operation(I_INSTRUCTION* decoded_instruction) {
    if (!is_lb_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "LB <rd=%s> <rs1=%s> <imm_u=%u> <imm_s=%d>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        decoded_instruction->imm_u,
        decoded_instruction->imm_s
    );
    return format_memory;
}

char* format_lh_operation(I_INSTRUCTION* decoded_instruction) {
    if (!is_lh_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "LH <rd=%s> <rs1=%s> <imm_u=%u> <imm_s=%d>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        decoded_instruction->imm_u,
        decoded_instruction->imm_s
    );
    return format_memory;
}

char* format_lw_operation(I_INSTRUCTION* decoded_instruction) {
    if (!is_lw_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "LW <rd=%s> <rs1=%s> <imm_u=%u> <imm_s=%d>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        decoded_instruction->imm_u,
        decoded_instruction->imm_s
    );
    return format_memory;
}

char* format_lbu_operation(I_INSTRUCTION* decoded_instruction) {
    if (!is_lbu_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "LBU <rd=%s> <rs1=%s> <imm_u=%u> <imm_s=%d>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        decoded_instruction->imm_u,
        decoded_instruction->imm_s
    );
    return format_memory;
}

char* format_lhu_operation(I_INSTRUCTION* decoded_instruction) {
    if (!is_lhu_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "LHU <rd=%s> <rs1=%s> <imm_u=%u> <imm_s=%d>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        decoded_instruction->imm_u,
        decoded_instruction->imm_s
    );
    return format_memory;
}

char* format_sb_operation(S_INSTRUCTION* decoded_instruction) {
    if (!is_sb_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "SB <rs1=%s> <rs2=%s> <imm_u=%u> <imm_s=%d>",
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2),
        decoded_instruction->imm_u,
        decoded_instruction->imm_s
    );
    return format_memory;
}

char* format_sh_operation(S_INSTRUCTION* decoded_instruction) {
    if (!is_sh_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "SH <rs1=%s> <rs2=%s> <imm_u=%u> <imm_s=%d>",
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2),
        decoded_instruction->imm_u,
        decoded_instruction->imm_s
    );
    return format_memory;
}

char* format_sw_operation(S_INSTRUCTION* decoded_instruction) {
    if (!is_sw_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "SW <rs1=%s> <rs2=%s> <imm_u=%u> <imm_s=%d>",
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2),
        decoded_instruction->imm_u,
        decoded_instruction->imm_s
    );
    return format_memory;
}

char* format_ecall_operation(I_INSTRUCTION* decoded_instruction) {
    if (!is_ecall_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "ECALL <rd=%s> <rs1=%s> <imm_u=%u> <imm_s=%d>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        decoded_instruction->imm_u,
        decoded_instruction->imm_s
    );
    return format_memory;
}

char* format_mul_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_mul_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "MUL <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
}

char* format_mulh_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_mulh_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "MULH <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
}

char* format_mulhsu_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_mulhsu_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "MULHSU <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
}

char* format_mulhu_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_mulhu_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "MULHU <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
}

char* format_div_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_div_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "DIV <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
}

char* format_divu_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_divu_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "DIVU <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
}

char* format_rem_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_rem_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "REM <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
}

char* format_remu_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_remu_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "REMU <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
}
