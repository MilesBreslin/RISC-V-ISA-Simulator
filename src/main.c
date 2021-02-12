#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


bool verbose = 0;
char* target_file = NULL;
uint32_t pc_init = 0x00000000;

void usage(char* message, int err) {
    FILE* fd = err == 0 ? stdout : stderr;
    fprintf(fd, "%s\n", message);

    fprintf(fd, "--load-file <config_file>          Decoded runtime code\n");
    fprintf(fd, "--pc-init <addr>                   Hexadecimal value to start the program counter (default: %08X)\n", pc_init);
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
    if (target_file) {
        printf("pc-init at: %08X\n", pc_init);
        printf("Load file not implemented: %s\n", target_file);
    } else {
        usage("Target file not specified", 1);
    }
}