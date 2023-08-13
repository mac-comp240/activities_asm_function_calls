
#include <stdio.h>

int func1(int a, int b);

int main(void) {
    int res1 = func1(5, 15);
    printf("%hi\n", res1);
    return 0;
}

int func1(int a, int b) {
    int c = a + b;
    return c;
}