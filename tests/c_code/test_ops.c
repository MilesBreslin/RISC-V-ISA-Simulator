void _start() {
    int x = 0;
    for (int i = 0; i < 32 ; i+=2)
        x |= 1 << i;
    int y = x == 0x55555555;
}