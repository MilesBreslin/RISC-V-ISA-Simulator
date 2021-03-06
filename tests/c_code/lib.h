void print_str(char* str) {
    int length = -1;
    while (str[++length] != 0)
        if (length > 100)
            return;
    register int syscall_reg asm ("a7") = 64;
    register int fd_reg asm ("a0") = 1;
    register char* addr_reg asm ("a1") = str;
    register int len_reg asm ("a2") = length;
    __asm__(
        "ecall"
    );
}

unsigned int div(unsigned int dividend, unsigned int divisor) {
    int quotient = 0;
    while (dividend >= divisor) {
        dividend-=divisor;
        quotient+=1;
    }
    return quotient;
}

unsigned int mod(unsigned int dividend, unsigned int divisor) {
    int quotient = 0;
    while (dividend >= divisor) {
        dividend-=divisor;
        quotient+=1;
    }
    return dividend;
}

void print_int(int x) {
    char buff[5];
    for (int i = 0; i < sizeof(buff) - 1 ; i++)
        buff[i] = '0';
    int i = 0;
    while (x != 0) {
        buff[sizeof(buff) - 2 - i] = mod(x, 10) + '0';
        x = div(x, 10);
        i++;
    }
    buff[sizeof(buff)-1] = 0; 
    print_str(buff);
}

void ecall_exit() {
    __asm__ (
        "addi a7, zero, 94;"
        "ecall;"
    );
}