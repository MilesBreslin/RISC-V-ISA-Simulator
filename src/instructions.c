// This file has been generated using `tools/opcode_generator`
// DO NOT EDIT BY HAND

#include <stdbool.h>
#include <stdint.h>
#include "core.h"
#include "instructions.h"

R_INSTRUCTION as_r_instruction(uint32_t instruction) {
    return (R_INSTRUCTION) {
        .opcode = (
            // <TotalBits=6>
            // <Start=0> <End=6> <Length=6> <Offset=0> <Zero=false>
            ((instruction << 0) & (0xFFFFFFFF >> (32 + 0 - 6)) << 0)
            |
            // Unsigned
            0
        ),
        .rd = (
            // <TotalBits=4>
            // <Start=7> <End=11> <Length=4> <Offset=0> <Zero=false>
            ((instruction << 7) & (0xFFFFFFFF >> (32 + 7 - 11)) << 0)
            |
            // Unsigned
            0
        ),
        .func3 = (
            // <TotalBits=2>
            // <Start=12> <End=14> <Length=2> <Offset=0> <Zero=false>
            ((instruction << 12) & (0xFFFFFFFF >> (32 + 12 - 14)) << 0)
            |
            // Unsigned
            0
        ),
        .rs1 = (
            // <TotalBits=4>
            // <Start=15> <End=19> <Length=4> <Offset=0> <Zero=false>
            ((instruction << 15) & (0xFFFFFFFF >> (32 + 15 - 19)) << 0)
            |
            // Unsigned
            0
        ),
        .rs2 = (
            // <TotalBits=4>
            // <Start=20> <End=24> <Length=4> <Offset=0> <Zero=false>
            ((instruction << 20) & (0xFFFFFFFF >> (32 + 20 - 24)) << 0)
            |
            // Unsigned
            0
        ),
        .func7 = (
            // <TotalBits=6>
            // <Start=25> <End=31> <Length=6> <Offset=0> <Zero=false>
            ((instruction << 25) & (0xFFFFFFFF >> (32 + 25 - 31)) << 0)
            |
            // Unsigned
            0
        )
    };
}

I_INSTRUCTION as_i_instruction(uint32_t instruction) {
    return (I_INSTRUCTION) {
        .opcode = (
            // <TotalBits=6>
            // <Start=0> <End=6> <Length=6> <Offset=0> <Zero=false>
            ((instruction << 0) & (0xFFFFFFFF >> (32 + 0 - 6)) << 0)
            |
            // Unsigned
            0
        ),
        .rd = (
            // <TotalBits=4>
            // <Start=7> <End=11> <Length=4> <Offset=0> <Zero=false>
            ((instruction << 7) & (0xFFFFFFFF >> (32 + 7 - 11)) << 0)
            |
            // Unsigned
            0
        ),
        .func3 = (
            // <TotalBits=2>
            // <Start=12> <End=14> <Length=2> <Offset=0> <Zero=false>
            ((instruction << 12) & (0xFFFFFFFF >> (32 + 12 - 14)) << 0)
            |
            // Unsigned
            0
        ),
        .rs1 = (
            // <TotalBits=4>
            // <Start=15> <End=19> <Length=4> <Offset=0> <Zero=false>
            ((instruction << 15) & (0xFFFFFFFF >> (32 + 15 - 19)) << 0)
            |
            // Unsigned
            0
        ),
        .imm = (
            // <TotalBits=7>
            // <Start=null> <End=null> <Length=1> <Offset=0> <Zero=true>
            0
            |
            // <Start=25> <End=31> <Length=6> <Offset=1> <Zero=false>
            ((instruction << 25) & (0xFFFFFFFF >> (32 + 25 - 31)) << 1)
            |
            // Signed <Bits=7>
            ((instruction >> (7 - 1)) == 0 ? 0 : (0xFFFFFFFF << 7))
        )
    };
}

S_INSTRUCTION as_s_instruction(uint32_t instruction) {
    return (S_INSTRUCTION) {
        .opcode = (
            // <TotalBits=6>
            // <Start=0> <End=6> <Length=6> <Offset=0> <Zero=false>
            ((instruction << 0) & (0xFFFFFFFF >> (32 + 0 - 6)) << 0)
            |
            // Unsigned
            0
        ),
        .func3 = (
            // <TotalBits=2>
            // <Start=12> <End=14> <Length=2> <Offset=0> <Zero=false>
            ((instruction << 12) & (0xFFFFFFFF >> (32 + 12 - 14)) << 0)
            |
            // Unsigned
            0
        ),
        .rs1 = (
            // <TotalBits=4>
            // <Start=15> <End=19> <Length=4> <Offset=0> <Zero=false>
            ((instruction << 15) & (0xFFFFFFFF >> (32 + 15 - 19)) << 0)
            |
            // Unsigned
            0
        ),
        .rs2 = (
            // <TotalBits=4>
            // <Start=20> <End=24> <Length=4> <Offset=0> <Zero=false>
            ((instruction << 20) & (0xFFFFFFFF >> (32 + 20 - 24)) << 0)
            |
            // Unsigned
            0
        ),
        .imm = (
            // <TotalBits=10>
            // <Start=7> <End=11> <Length=4> <Offset=0> <Zero=false>
            ((instruction << 7) & (0xFFFFFFFF >> (32 + 7 - 11)) << 0)
            |
            // <Start=25> <End=31> <Length=6> <Offset=4> <Zero=false>
            ((instruction << 25) & (0xFFFFFFFF >> (32 + 25 - 31)) << 4)
            |
            // Unsigned
            0
        )
    };
}

U_INSTRUCTION as_u_instruction(uint32_t instruction) {
    return (U_INSTRUCTION) {
        .opcode = (
            // <TotalBits=6>
            // <Start=0> <End=6> <Length=6> <Offset=0> <Zero=false>
            ((instruction << 0) & (0xFFFFFFFF >> (32 + 0 - 6)) << 0)
            |
            // Unsigned
            0
        ),
        .rd = (
            // <TotalBits=4>
            // <Start=7> <End=11> <Length=4> <Offset=0> <Zero=false>
            ((instruction << 7) & (0xFFFFFFFF >> (32 + 7 - 11)) << 0)
            |
            // Unsigned
            0
        ),
        .imm = (
            // <TotalBits=19>
            // <Start=12> <End=31> <Length=19> <Offset=0> <Zero=false>
            ((instruction << 12) & (0xFFFFFFFF >> (32 + 12 - 31)) << 0)
            |
            // Signed <Bits=19>
            ((instruction >> (19 - 1)) == 0 ? 0 : (0xFFFFFFFF << 19))
        )
    };
}

B_INSTRUCTION as_b_instruction(uint32_t instruction) {
    return (B_INSTRUCTION) {
        .opcode = (
            // <TotalBits=6>
            // <Start=0> <End=6> <Length=6> <Offset=0> <Zero=false>
            ((instruction << 0) & (0xFFFFFFFF >> (32 + 0 - 6)) << 0)
            |
            // Unsigned
            0
        ),
        .func3 = (
            // <TotalBits=2>
            // <Start=12> <End=14> <Length=2> <Offset=0> <Zero=false>
            ((instruction << 12) & (0xFFFFFFFF >> (32 + 12 - 14)) << 0)
            |
            // Unsigned
            0
        ),
        .rs1 = (
            // <TotalBits=4>
            // <Start=15> <End=19> <Length=4> <Offset=0> <Zero=false>
            ((instruction << 15) & (0xFFFFFFFF >> (32 + 15 - 19)) << 0)
            |
            // Unsigned
            0
        ),
        .rs2 = (
            // <TotalBits=4>
            // <Start=20> <End=24> <Length=4> <Offset=0> <Zero=false>
            ((instruction << 20) & (0xFFFFFFFF >> (32 + 20 - 24)) << 0)
            |
            // Unsigned
            0
        ),
        .imm = (
            // <TotalBits=10>
            // <Start=7> <End=11> <Length=4> <Offset=0> <Zero=false>
            ((instruction << 7) & (0xFFFFFFFF >> (32 + 7 - 11)) << 0)
            |
            // <Start=25> <End=31> <Length=6> <Offset=4> <Zero=false>
            ((instruction << 25) & (0xFFFFFFFF >> (32 + 25 - 31)) << 4)
            |
            // Unsigned
            0
        )
    };
}

J_INSTRUCTION as_j_instruction(uint32_t instruction) {
    return (J_INSTRUCTION) {
        .opcode = (
            // <TotalBits=6>
            // <Start=0> <End=6> <Length=6> <Offset=0> <Zero=false>
            ((instruction << 0) & (0xFFFFFFFF >> (32 + 0 - 6)) << 0)
            |
            // Unsigned
            0
        ),
        .rd = (
            // <TotalBits=4>
            // <Start=7> <End=11> <Length=4> <Offset=0> <Zero=false>
            ((instruction << 7) & (0xFFFFFFFF >> (32 + 7 - 11)) << 0)
            |
            // Unsigned
            0
        ),
        .imm = (
            // <TotalBits=19>
            // <Start=12> <End=31> <Length=19> <Offset=0> <Zero=false>
            ((instruction << 12) & (0xFFFFFFFF >> (32 + 12 - 31)) << 0)
            |
            // Unsigned
            0
        )
    };
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
