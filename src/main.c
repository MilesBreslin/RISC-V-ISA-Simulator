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
uint32_t pc_init = 0x00000000;
uint32_t sp_init = 0x0000FFFF;
uint32_t simulation_size = 1 << 28;

void usage(char* message, int err) {
    FILE* fd = err == 0 ? stdout : stderr;
    fprintf(fd, "%s\n", message);

    fprintf(fd, "--load-file <config_file>          Decoded runtime code (default: \"%s\")\n", target_file);
    fprintf(fd, "--pc-init <addr>                   Hexadecimal value to start the program counter (default: 0x00000000)\n");
    fprintf(fd, "--sp_init <addr>                   Decimal value to specify the stack address (default: 65535)\n");
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
        } else if (strcmp("--verbose", argv[i]) == 0) {
            verbose = true;
        } else if (strcmp("--help", argv[i]) == 0) {
            usage("", 0);
        } else {
            const char* fmt = "Unknown flag `%s`";
            char* buf = malloc(strlen(fmt) + strlen(argv[i]));
            sprintf(buf, fmt, argv[1]);
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

        simulator s;
        simulator_init(&s, simulation_size);

        // Parse the file
        int line_no = 0;
        char line[255];
        while (fgets(line, sizeof(line), f) != NULL) {

            // Split the string into 
            char* addr_ptr = line;
            char* value_ptr;
            if ((value_ptr = strchr(addr_ptr, ':')) != NULL) {
                value_ptr[0] = 0;
                value_ptr++;
            } else
                FAIL("Invalid line: %s", line);

            // Parse address
            uint32_t addr;
            if (sscanf(addr_ptr, "%X", &addr) != 1)
                FAIL("Invalid line: %s", line);

            // Parse value
            uint32_t value;
            if (sscanf(value_ptr, "%X", &value) != 1)
                FAIL("Invalid line: %s", line);

            write_word(&s, addr, value);

            // Log to verbose information the parsed line
            INFO("%04X (L%02d): %08X", addr, line_no, value);
            line_no++;
        }

        if (line_no == 0)
            FAIL("File is empty");
        
        if (verbose)
            display_memory(&s, 0, line_no);

        /*Execution loop*/
        while (1) {
            bool ret = (execute_simulation_step(&s, pc_init));

            if (!ret) {
                simulator_destroy(&s);
                exit(EXIT_SUCCESS);
                printf("Shouldn't see this if execution halted\n"); //There to prove that the sim actually halts
            }

            pc_init += 4;
        }

    } else {
        usage("Target file not specified", 1);
    }

}