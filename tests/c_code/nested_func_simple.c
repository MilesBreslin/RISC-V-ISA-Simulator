int callee(int a, int b);
void caller(){
    int a = 36;
    int b = 63;
    int result = callee(a,b);
}
int callee(int a, int b) {
    int c = a + b;
    return c;
}
