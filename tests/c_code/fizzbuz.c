#include "lib.h"

void _start() {
    for (int i = 1; i < 100 ; i++) {
        print_str("FB");
        print_int(i);
        print_str(": ");
        if (mod(i,3) == 0 && mod(i, 5) == 0)
            print_str("fizz buzz");
        else if (mod(i,3) == 0)
            print_str("fizz");
        else if (mod(i, 5) == 0)
            print_str("buzz");
        else
            print_int(i);
        print_str("\n");
    }
    ecall_exit();
}