#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAIN
#include "core.h"
#include "simulator.h"


bool verbose = 0;
char* target_file = "prog.mem";
char* dump_mem_file = NULL;
char* dump_reg_file = NULL;
uint32_t pc_init = 0x00000000;
uint32_t sp_init = 0x0000FFF0;
uint32_t simulation_size = 1 << 16;
unsigned int instruction_limit = 0;

void usage(char* message, int err) {
    FILE* fd = err == 0 ? stdout : stderr;
    fprintf(fd, "%s\n", message);

    fprintf(fd, "--dump-memory <memory_file>        Dump memory to a file (default: \"%s\")\n", dump_mem_file);
    fprintf(fd, "--dump-registers <register_file>   Dump registers to a file (default: \"%s\")\n", dump_reg_file);
    fprintf(fd, "--instruction-limit <count>        Limit the number of instructions executed (default: %u)\n", instruction_limit);
    fprintf(fd, "--load-file <config_file>          Decoded runtime code (default: \"%s\")\n", target_file);
    fprintf(fd, "--pc-init <addr>                   Hexadecimal value to start the program counter (default: %08X)\n", pc_init);
    fprintf(fd, "--simulation-size <bytes>          Decimal value to specify the stack address (default: %08X)\n", simulation_size);
    fprintf(fd, "--sp-init <addr>                   Decimal value to specify the stack address (default: %08X)\n", sp_init);
    fprintf(fd, "--verbose                          Show extra verbose information\n");

    fprintf(fd, "--help                             Show this help dialog\n");
    exit(err);
}

int main(int argc, char* argv[]) {
    int err;

    // Parse Input Arguments
    for (int i = 1 ; i < argc ; i++) {
        if (strcmp("--load-file", argv[i]) == 0) {
            i++;
            target_file = argv[i];
        } else if (strcmp("--dump-memory", argv[i]) == 0) {
            i++;
            dump_mem_file = argv[i];
        } else if (strcmp("--dump-registers", argv[i]) == 0) {
            i++;
            dump_reg_file = argv[i];
        } else if (strcmp("--pc-init", argv[i]) == 0) {
            i++;
            if ((err = sscanf(argv[i], "%X", &pc_init)) != 1) {
                fprintf(stderr, "Invalid format for --pc-init\n");
            }
        } else if (strcmp("--sp-init", argv[i]) == 0) {
            i++;
            if ((err = sscanf(argv[i], "%X", &sp_init)) != 1) {
                fprintf(stderr, "Invalid format for --sp-init\n");
            }
        } else if (strcmp("--instruction-limit", argv[i]) == 0) {
            i++;
            if ((err = sscanf(argv[i], "%d", &instruction_limit)) != 1) {
                fprintf(stderr, "Invalid format for --instruction-limit\n");
            }
        } else if (strcmp("--simulation-size", argv[i]) == 0) {
            i++;
            if ((err = sscanf(argv[i], "%X", &simulation_size)) != 1) {
                fprintf(stderr, "Invalid format for --simulation-size\n");
            }
        } else if (strcmp("--verbose", argv[i]) == 0) {
            verbose = true;
        } else if (strcmp("--help", argv[i]) == 0) {
            usage("", 0);
        } else {
            const char* fmt = "Unknown flag `%s`";
            char buf[255];
            sprintf(buf, fmt, argv[i]);
            usage(buf, 1);
        }
    }

    // Load the Input file
    if (target_file && strlen(target_file) > 0) {
        INFO("pc-init at: 0x%08X", pc_init);
        INFO("Stack Address: %d", sp_init);

        // Open file
        FILE *f;
        if ((f = fopen(target_file, "r+")) == NULL)
            FAIL_SYS("Unable to open input file: %s", target_file);

        // Initialize a simulator
        simulator s;
        simulator_init(&s, simulation_size);
        s.pc = pc_init;
        write_register(&s, REG_SP, sp_init);

        // Read file and write its values to memory
        int lines = read_file_to_memory(&s, f);
        if (lines == 0)
            FAIL("File is empty");

        fclose(f);

        unsigned int exec_count = 0;
        while (execute_simulation_step(&s)) {
            if (instruction_limit > 0 && ++exec_count > instruction_limit)
                FAIL("Instruction limit reached: %d", instruction_limit);
        }

        if (dump_mem_file) {
            FILE* mem_f;
            if (strcmp("-", dump_mem_file) == 0)
                mem_f = stdout;
            else if ((mem_f = fopen(dump_mem_file, "w+")) == NULL)
                WARN_SYS("Unable to open dump mem file: %s", dump_mem_file);

            if (mem_f != NULL)
                dump_memory_to_file(&s, mem_f, 0, 0);

            if (mem_f != stdout)
                fclose(mem_f);
        }
        if (dump_reg_file) {
            FILE* reg_f;
            if (strcmp("-", dump_reg_file) == 0)
                reg_f = stdout;
            else if ((reg_f = fopen(dump_reg_file, "w+")) == NULL)
                WARN_SYS("Unable to open dump mem file: %s", dump_reg_file);

            if (reg_f != NULL)
                dump_registers_to_file(&s, reg_f);

            if (reg_f != stdout)
                fclose(reg_f);
        }
        printf("PC: %08X\n", s.pc);

        simulator_destroy(&s);
        exit(EXIT_SUCCESS);
        printf("Shouldn't see this if execution halted\n"); //There to prove that the sim actually halts
    } else {
        usage("Target file not specified", 1);
    }

}
