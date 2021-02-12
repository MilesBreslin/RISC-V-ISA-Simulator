#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


bool debug = 0;
char* target_file = NULL;

void usage(char* message, int err) {
    FILE* fd = err == 0 ? stdout : stderr;
    fprintf(fd, "%s\n", message);
    fprintf(fd, "--load-file <config_file>          Decoded runtime code\n");
    fprintf(fd, "--debug                            Show extra debug information\n");
    fprintf(fd, "--help                             Show this help dialog\n");
    exit(err);
}

int main(int argc, char* argv[]) {
    // Parse Input Arguments
    for (int i = 1 ; i < argc ; i++) {
        if (strcmp("--load-file", argv[i]) == 0) {
            i++;
            target_file = argv[i];
        } else if (strcmp("--debug", argv[i]) == 0) {
            debug = true;
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
        printf("Load file not implemented: %s\n", target_file);
    } else {
        printf("Target file not specified\n");
        return 1;
    }
}