#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "core.h"
#include "simulator.h"
#include "instructions.h"

void simulator_init(simulator* s, uint32_t mem_bytes) {
    memset(s, 0, sizeof(*s));
    s->memory = calloc(mem_bytes, sizeof(uint8_t));
    s->mem_bytes = mem_bytes;
}

void simulator_destroy(simulator* s) {
    free(s->memory);
}

#define out_of_bounds_check(s, addr, data_type) (addr > (((int64_t) s->mem_bytes) - sizeof(data_type)))

void display_memory(simulator* s, uint32_t start_addr, uint32_t length, bool ignore_zeros) {
    dump_memory_to_file(s, stdout, start_addr, length, ignore_zeros);
}

void display_registers(simulator* s, bool ignore_zeros) {
    dump_registers_to_file(s, stdout, ignore_zeros);
}

int read_file_to_memory(simulator* s, FILE *f) {
    // Parse the file
    int line_no = 0;
    char line[255];
    while (fgets(line, sizeof(line), f) != NULL) {
        // Skip commented lines
        if (line[0] == '#')
            continue;

        // Split the string into 
        char* addr_ptr = line;
        char* value_ptr;
        if ((value_ptr = strchr(addr_ptr, ':')) != NULL) {
            value_ptr[0] = 0;
            value_ptr++;
        } else
            FAIL("Invalid line: %s", line);

        // Parse value
        uint32_t value;
        if (sscanf(value_ptr, "%X", &value) != 1)
            FAIL("Invalid line: %s", line);

        // If is a valid register, write to the register; else parse as an address
        REGISTER reg;
        if ((reg = register_from_name(addr_ptr)) < 32 && reg >= 0) {
            write_register(s, reg, value);
        } else if (strcmp("PC", addr_ptr) == 0) {
            s->pc = value;
        } else {
            // Parse address
            uint32_t addr;
            if (sscanf(addr_ptr, "%X", &addr) != 1)
                FAIL("Invalid line: %s", line);

            // Get the length of only the value string's valid characters
            int value_length = 0;
            for (int i = 0; i < strlen(value_ptr) ; i++)
                if ((value_ptr[i] >= '0' && value_ptr[i] <= '9')
                    || (value_ptr[i] >= 'a' && value_ptr[i] <= 'f')
                    || (value_ptr[i] >= 'A' && value_ptr[i] <= 'F'))
                    value_length++;

            // Write the word into memory
            if (value_length <= 2)
                write_byte(s, addr, value);
            else if (value_length <= 4)
                write_hword(s, addr, value);
            else
                write_word(s, addr, value);
        }

        line_no++;
    }
    return line_no;
}

int dump_memory_to_file(simulator* s, FILE* f, uint32_t start_addr, uint32_t length, bool ignore_zeros) {
    uint32_t count = 0;
    uint32_t addr = start_addr;
    uint32_t end_addr = start_addr + (length * 4);
    while ((addr < end_addr || length == 0) && !out_of_bounds_check(s, addr, uint32_t)) {
        uint32_t value = read_word(s, addr);
        if ((value != 0 || !ignore_zeros) && fprintf(f, "%08X: %08X\n", addr, value) <= 0) {
            WARN_SYS("Memory dump error");
            return count;
        }
        addr += 4;
        count++;
    }
    return count;
}

int dump_registers_to_file(simulator* s, FILE* f, bool ignore_zeros) {
    for (int i = 0; i < 32; i++) {
        uint32_t value = read_register(s, i);
        if (value == 0 && ignore_zeros)
            continue;
        if (fprintf(f, "%s: %08X\n", register_to_name(i), value) <= 0) {
            WARN_SYS("Register dump write error");
            return i;
        }
    }
    return 32;
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
    INFO("Write %s: [%08X] %08X", #data_type, addr, data);\
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
    if (reg == REG_ZERO)
        return 0;
    int reg_reduced = reg - 1;      // REG_ZERO is not real
    if (reg_reduced > length(s->reg))
        FAIL("Invalid register read: %d", reg);
    return s->reg[reg_reduced];
}
int32_t read_register_signed(simulator* s, REGISTER reg) {
    uint32_t value = read_register(s, reg);
    return *(int32_t*) (&value);
}
void write_register(simulator* s, REGISTER reg, uint32_t data) {
    INFO("Write: [%s] %08X", register_to_name(reg), data);
    if (reg == REG_ZERO)
        return;
    int reg_reduced = reg - 1;      // REG_ZERO is not real
    if (reg_reduced > length(s->reg))
        FAIL("Invalid register write: %d", reg);
    s->reg[reg_reduced] = data;
}
void write_register_signed(simulator* s, REGISTER reg, int32_t data) {
    write_register(s, reg, *(uint32_t*) (&data));
}

const char* register_to_name(REGISTER reg) {
    #define GEN_REG_TO_NAME(value) if (reg == value) return #value
    GEN_REG_TO_NAME(REG_ZERO);
    GEN_REG_TO_NAME(REG_RA);
    GEN_REG_TO_NAME(REG_SP);
    GEN_REG_TO_NAME(REG_GP);
    GEN_REG_TO_NAME(REG_TP);
    GEN_REG_TO_NAME(REG_T0);
    GEN_REG_TO_NAME(REG_T1);
    GEN_REG_TO_NAME(REG_T2);
    GEN_REG_TO_NAME(REG_FP);
    GEN_REG_TO_NAME(REG_S1);
    GEN_REG_TO_NAME(REG_A0);
    GEN_REG_TO_NAME(REG_A1);
    GEN_REG_TO_NAME(REG_A2);
    GEN_REG_TO_NAME(REG_A3);
    GEN_REG_TO_NAME(REG_A4);
    GEN_REG_TO_NAME(REG_A5);
    GEN_REG_TO_NAME(REG_A6);
    GEN_REG_TO_NAME(REG_A7);
    GEN_REG_TO_NAME(REG_S2);
    GEN_REG_TO_NAME(REG_S3);
    GEN_REG_TO_NAME(REG_S4);
    GEN_REG_TO_NAME(REG_S5);
    GEN_REG_TO_NAME(REG_S6);
    GEN_REG_TO_NAME(REG_S7);
    GEN_REG_TO_NAME(REG_S8);
    GEN_REG_TO_NAME(REG_S9);
    GEN_REG_TO_NAME(REG_S10);
    GEN_REG_TO_NAME(REG_S11);
    GEN_REG_TO_NAME(REG_T3);
    GEN_REG_TO_NAME(REG_T4);
    GEN_REG_TO_NAME(REG_T5);
    GEN_REG_TO_NAME(REG_T6);
    return "REG_INVALID";
}
REGISTER register_from_name(char* name) {
    #define GEN_REG_FROM_NAME(value) if (strcmp(name, #value) == 0) return value;
    GEN_REG_FROM_NAME(REG_ZERO);
    GEN_REG_FROM_NAME(REG_RA);
    GEN_REG_FROM_NAME(REG_SP);
    GEN_REG_FROM_NAME(REG_GP);
    GEN_REG_FROM_NAME(REG_TP);
    GEN_REG_FROM_NAME(REG_T0);
    GEN_REG_FROM_NAME(REG_T1);
    GEN_REG_FROM_NAME(REG_T2);
    GEN_REG_FROM_NAME(REG_S0);
    GEN_REG_FROM_NAME(REG_FP);
    GEN_REG_FROM_NAME(REG_S1);
    GEN_REG_FROM_NAME(REG_A0);
    GEN_REG_FROM_NAME(REG_A1);
    GEN_REG_FROM_NAME(REG_A2);
    GEN_REG_FROM_NAME(REG_A3);
    GEN_REG_FROM_NAME(REG_A4);
    GEN_REG_FROM_NAME(REG_A5);
    GEN_REG_FROM_NAME(REG_A6);
    GEN_REG_FROM_NAME(REG_A7);
    GEN_REG_FROM_NAME(REG_S2);
    GEN_REG_FROM_NAME(REG_S3);
    GEN_REG_FROM_NAME(REG_S4);
    GEN_REG_FROM_NAME(REG_S5);
    GEN_REG_FROM_NAME(REG_S6);
    GEN_REG_FROM_NAME(REG_S7);
    GEN_REG_FROM_NAME(REG_S8);
    GEN_REG_FROM_NAME(REG_S9);
    GEN_REG_FROM_NAME(REG_S10);
    GEN_REG_FROM_NAME(REG_S11);
    GEN_REG_FROM_NAME(REG_T3);
    GEN_REG_FROM_NAME(REG_T4);
    GEN_REG_FROM_NAME(REG_T5);
    GEN_REG_FROM_NAME(REG_T6);
    return -1;
}

// Make GCC refuse to compile if we use the wrong instruction type
#pragma GCC diagnostic error "-Wincompatible-pointer-types"
bool execute_simulation_step(simulator* s) {
    uint32_t pc = s->pc;
    s->pc += 4;

    if (pc % 4 != 0)
        WARN("PC is not aligned");
    
    // No need to check OOB, read_word returns 0 on invalid memory
    uint32_t encoded_instruction = read_word(s, pc);
    if (encoded_instruction == 0) {
        INFO("Instruction [%08X] %08X", pc, encoded_instruction);
        return false;
    }

    int instruction_matches = count_all_instruction_matches(encoded_instruction);
    if (instruction_matches > 1) {
        WARN("Instruction [%08X] %08X: Matches more than 1 instruction", pc, encoded_instruction);
        return true;
    } else if (instruction_matches == 0) {
        WARN("Instruction [%08X] %08X: No known instruction", pc, encoded_instruction);
        return true;
    }

    INFO("Instruction [%08X] %08X: %s", pc, encoded_instruction, format_instruction(encoded_instruction));

    R_INSTRUCTION r_instruction = as_r_instruction(encoded_instruction);
    I_INSTRUCTION i_instruction = as_i_instruction(encoded_instruction);
    S_INSTRUCTION s_instruction = as_s_instruction(encoded_instruction);
    U_INSTRUCTION u_instruction = as_u_instruction(encoded_instruction);
    B_INSTRUCTION b_instruction = as_b_instruction(encoded_instruction);
    J_INSTRUCTION j_instruction = as_j_instruction(encoded_instruction);
    if (is_add_instruction(&r_instruction)) {
        write_register(s, r_instruction.rd, 
            read_register(s, r_instruction.rs1) + read_register(s, r_instruction.rs2)
        );  
        return true;
    }
    if (is_sub_instruction(&r_instruction)) {
        write_register(s, r_instruction.rd, 
            read_register(s, r_instruction.rs1)^ read_register(s, r_instruction.rs2)
        );  
        return true;
    }
    if (is_sll_instruction(&r_instruction)) {
       write_register(s, r_instruction.rd, 
           read_register(s, r_instruction.rs1) << (read_register(s, r_instruction.rs2) %32)
       );
        return true;
    }
    if (is_slt_instruction(&r_instruction)) {
        if(read_register_signed(s, r_instruction.rs1) < read_register_signed(s, r_instruction.rs2)){
           write_register(s, r_instruction.rd, 1);
        }
        else {
            write_register(s, r_instruction.rd, 0);
        }
        return true;
    }
    if (is_sltu_instruction(&r_instruction)) {
        if(read_register(s, r_instruction.rs1) < read_register(s, r_instruction.rs2)){
           write_register(s, r_instruction.rd, 1);
        }
        else {
            write_register(s, r_instruction.rd, 0);
        }
        return true;
    }
    if (is_xor_instruction(&r_instruction)) {
        write_register(s, r_instruction.rd, 
            read_register(s, r_instruction.rs1)^ read_register(s, r_instruction.rs2)
        );
        return true;
    }
    if (is_srl_instruction(&r_instruction)) {
        write_register(s, r_instruction.rd, 
            read_register(s, r_instruction.rs1) >> (read_register(s, r_instruction.rs2) %32)
       );
        return true;

    }
    if (is_sra_instruction(&r_instruction)) {
        write_register_signed(s, r_instruction.rd, 
            read_register_signed(s, r_instruction.rs1) >> (read_register(s, r_instruction.rs2) %32)
       );
        return true;
    }
    if (is_or_instruction(&r_instruction)) {
        write_register(s, r_instruction.rd, 
            read_register(s, r_instruction.rs1) | read_register(s, r_instruction.rs2)
        );
        return true;
    }
    if (is_and_instruction(&r_instruction)) {
        write_register(s, r_instruction.rd, 
            read_register(s, r_instruction.rs1) & read_register(s, r_instruction.rs2)
        );
        return true;
    }
    if (is_addi_instruction(&i_instruction)) {
        write_register(s, i_instruction.rd,
            (read_register(s, i_instruction.rs1) + i_instruction.imm_s)
        );
        return true;
    }
    if (is_slti_instruction(&i_instruction)) {
        if(read_register_signed(s, i_instruction.rs1) < read_register_signed(s, i_instruction.imm_s)) {
            write_register(s, i_instruction.rd, 1);
        }        
        else {
            write_register(s, i_instruction.rd, 0);
        }
        return true;
    }
    if (is_sltiu_instruction(&i_instruction)) {
        if(read_register(s, i_instruction.rs1) < i_instruction.imm_u) { 
            write_register(s, i_instruction.rd, 1);                                            
        }        
        else {
            write_register(s, i_instruction.rd, 0);
        }
        return true;
    }
    if (is_xori_instruction(&i_instruction)) {
        write_register(s, i_instruction.rd, 
            read_register(s, i_instruction.rs1)^ ((int32_t)i_instruction.imm_s)
        );
        return true;
    }
    if (is_ori_instruction(&i_instruction)) {
        write_register(s, i_instruction.rd, 
            read_register(s, i_instruction.rs1)|((int32_t)i_instruction.imm_s)
        );
        return true;
    }
    if (is_andi_instruction(&i_instruction)) {
        write_register(s, i_instruction.rd, 
            read_register(s, i_instruction.rs1)&((int32_t)i_instruction.imm_s)
        );
        return true;
    }
    if (is_slli_instruction(&i_instruction)) {
        write_register(s, i_instruction.rd, (read_register(s,i_instruction.rs1)) << (0x01f & i_instruction.imm_u));
        return true;
    }
    if (is_srli_instruction(&i_instruction)) {
        if(!(i_instruction.imm_u>>10)){
            write_register(s, i_instruction.rd, (read_register(s,i_instruction.rs1)) >> (0x01f & i_instruction.imm_u));
        }
        return true;
    }
    if (is_srai_instruction(&i_instruction)) {
        if((i_instruction.imm_u>>10)){
            write_register(s, i_instruction.rd, (read_register_signed(s,i_instruction.rs1)) >> (0x01f & i_instruction.imm_u));
        }        return true;
    }
    if (is_beq_instruction(&b_instruction)) {
        if(read_register(s, b_instruction.rs1) == read_register(s, b_instruction.rs2)){
            s->pc = pc + (b_instruction.imm_s);
        }
        return true;
    }
    if (is_bne_instruction(&b_instruction)) {
        if(read_register(s, b_instruction.rs1) != read_register(s, b_instruction.rs2)){
            s->pc = pc + (b_instruction.imm_s);
        }
        return true;
    }
    if (is_blt_instruction(&b_instruction)) {
        if(read_register_signed(s, b_instruction.rs1) < read_register_signed(s, b_instruction.rs2)){
            s->pc = pc + (b_instruction.imm_s);
        }
        return true;
    }
    if (is_bge_instruction(&b_instruction)) {
        if(read_register_signed(s, b_instruction.rs1) >= read_register_signed(s, b_instruction.rs2)){
            s->pc = pc + (b_instruction.imm_s);
        }
        return true;
    }
    if (is_bltu_instruction(&b_instruction)) {
        if(read_register(s, b_instruction.rs1) < read_register(s, b_instruction.rs2)){
            s->pc = pc + (b_instruction.imm_s);
        }
        return true;
    }
    if (is_bgeu_instruction(&b_instruction)) {
        if(read_register(s, b_instruction.rs1) >= read_register(s, b_instruction.rs2)){
            s->pc = pc + (b_instruction.imm_s);
        }
        return true;
    }
    if (is_lui_instruction(&u_instruction)) {
        write_register(s, u_instruction.rd, (read_register(s,u_instruction.rd)) + (u_instruction.imm_u<<12));
        return true;
    }
    if (is_auipc_instruction(&u_instruction)) {
        write_register(s, u_instruction.rd, pc + (u_instruction.imm_u<<12));
        return true;
    }
    if (is_jal_instruction(&j_instruction)) {
        write_register(s, j_instruction.rd, pc + j_instruction.imm_s);
            s->pc = pc + (j_instruction.imm_s);
        return true;
    }
    if (is_jalr_instruction(&i_instruction)) {
        write_register(s, i_instruction.rd, pc + 4);
        s->pc = (read_register_signed(s,i_instruction.rs1) + i_instruction.imm_s) & ~1;
        return true;
    }
    if (is_lb_instruction(&i_instruction)) {
        write_register(s, i_instruction.rd,
            read_sbyte(s, read_register(s, i_instruction.rs1) + i_instruction.imm_s)
        );
        return true;
    }
    if (is_lh_instruction(&i_instruction)) {
        write_register(s, i_instruction.rd,
            read_shword(s, read_register(s, i_instruction.rs1) + i_instruction.imm_s)
        );
        return true;
    }
    if (is_lw_instruction(&i_instruction)) {
        write_register(s, i_instruction.rd,
            read_sword(s,(read_register(s, i_instruction.rs1) + i_instruction.imm_s))
        );
        return true;
    }
    if (is_lbu_instruction(&i_instruction)) {
        write_register(s, i_instruction.rd,
            read_byte(s, read_register(s, i_instruction.rs1) + i_instruction.imm_u)
        );
        return true;
    }
    if (is_lhu_instruction(&i_instruction)) {
        write_register(s, i_instruction.rd,
            read_hword(s, read_register(s, i_instruction.rs1) + i_instruction.imm_u)
        );
        return true;
    }
    if (is_sb_instruction(&s_instruction)) {
        write_byte(s,
            read_register(s, s_instruction.rs1) + s_instruction.imm_s,
            read_register(s, s_instruction.rs2)
        );
        return true;
    }
    if (is_sh_instruction(&s_instruction)) {
        write_hword(s,
            read_register(s, s_instruction.rs1) + s_instruction.imm_s,
            read_register(s, s_instruction.rs2)
        );
        return true;
    }
    if (is_sw_instruction(&s_instruction)) {
        write_word(s,
            read_register(s, s_instruction.rs1) + s_instruction.imm_s,
            read_register(s, s_instruction.rs2)
        );
        return true;
    }
    if (is_mul_instruction(&r_instruction)) {
        write_register_signed(s, r_instruction.rd,
            ((int64_t)read_register(s, r_instruction.rs1) * (int64_t)read_register(s, r_instruction.rs2))
        ); 
        return true;
    }
    if (is_mulh_instruction(&r_instruction)) {
        int64_t value = ((int64_t)read_register_signed(s, r_instruction.rs1) * (int64_t)read_register_signed(s, r_instruction.rs2));
        write_register_signed(s, r_instruction.rd, value);
        return true;
    }
    if (is_mulhsu_instruction(&r_instruction)) {
        write_register_signed(s, r_instruction.rd,
            (((int64_t)read_register_signed(s, r_instruction.rs1) * (uint64_t)read_register(s, r_instruction.rs2))>> 16)
        ); 
        return true;
    }
    if (is_mulhu_instruction(&r_instruction)) {
        write_register(s, r_instruction.rd,
            (((uint64_t)read_register(s, r_instruction.rs1) * (uint64_t)read_register(s, r_instruction.rs2)) >> 32)
        ); 
        return true;
    }
    if (is_div_instruction(&r_instruction)) {
        if(read_register_signed(s, r_instruction.rs2) == 0){
            write_register_signed(s, r_instruction.rd, 0xffffffff);
        return true;
        }
        if(read_register_signed(s, r_instruction.rs2) == -1) {
            write_register_signed(s, r_instruction.rd, read_register_signed(s, r_instruction.rs1));
        return true;
        }
        else {
        write_register_signed(s, r_instruction.rd, 
            (read_register_signed(s, r_instruction.rs1) / read_register_signed(s, r_instruction.rs2))
        );
        return true;
        }
    }
    if (is_divu_instruction(&r_instruction)) {
        write_register(s, r_instruction.rd,
            (read_register(s, r_instruction.rs1) / read_register(s, r_instruction.rs2)) 
        );
        return true;
    }
    if (is_rem_instruction(&r_instruction)) {
        write_register(s, r_instruction.rd,
            (read_register_signed(s, r_instruction.rs1) % read_register_signed(s, r_instruction.rs2))
        );
        return true;
    }
    if (is_remu_instruction(&r_instruction)) {
        write_register(s, r_instruction.rd,
            (read_register(s, r_instruction.rs1) % read_register(s, r_instruction.rs2))
        );
        return true;
    }
    if (is_ecall_instruction(&i_instruction)) {
        if (i_instruction.imm_u == 1)
            WARN("Unimplemented operation: EBREAK");
        else if (i_instruction.imm_u != 0)
            WARN("Unexpected imm value for ECALL");
        else {
            uint32_t syscall = read_register(s, REG_A7);
            FILE* fds[] = {
                stdin,
                stdout,
                stderr,
            };
            switch (syscall) {
            case 63:
                WARN("Unimplemented syscall: READ");
                break;
            case 64:
                INFO("ECALL: write");
                uint32_t fd = read_register(s, REG_A0);
                uint32_t addr = read_register(s, REG_A1);
                uint32_t length = read_register(s, REG_A2);
                if (addr > s->mem_bytes)
                    return true;
                if (addr + length > s->mem_bytes)
                    length = s->mem_bytes - addr;
                if (fd <= length(fds))
                    fprintf(fds[fd], "%-*s", length, &((uint8_t*) s->memory)[addr]);
                return true;
            case 94:
                INFO("ECALL: exit");
                return false;
            default:
                WARN("Unknown syscall: %d", syscall);
                break;
            }
        }
        return true;
    }

    WARN("Unhandled operation: %08X", encoded_instruction);
    return true;
}
