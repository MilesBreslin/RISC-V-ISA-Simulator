#ifndef CORE_H
#define CORE_H

// DEBUG
#ifndef MAIN
extern _Bool verbose;
#endif

#include <stdio.h>
#include <stdlib.h>
#include "errno.h"
extern int errno;

#define CASSERT(condition, msg) char assert_#msg[!!(condition)-1];
#define FAIL(fmt, ...) do { fprintf(stderr, "FAIL: " fmt "\n", ##__VA_ARGS__); exit(1); } while (0)
#define FAIL_SYS(fmt, ...) do { fprintf(stderr, "FAIL: " fmt ": %s\n", ##__VA_ARGS__, strerror(errno)); exit(1); } while (0)
#define WARN(fmt, ...) do { fprintf(stderr, "WARN: " fmt "\n", ##__VA_ARGS__); } while (0)
#define WARN_SYS(fmt, ...) do { fprintf(stderr, "WARN: " fmt ": %s\n", ##__VA_ARGS__, strerror(errno)); } while (0)
#define INFO(fmt, ...) do { if (verbose) fprintf(stderr, "INFO: " fmt "\n", ##__VA_ARGS__); } while (0)
#define length(array) (sizeof(array)/sizeof(array[0]))

#endif