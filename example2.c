
#include <stdio.h>

int func2(int x1, int x2, int x3, int x4, int x5, int x6, int x7, int x8, int x9);

int main(void) {
    // First test call
    int res = func2(25, 30, 35, 40, 45, 50, 55, 60, 65);
    printf("%d\n", res);

    // Second test call
    res = func2(1, 2, 3, 4, 5, 6, 7, 8, 9);
    printf("%d\n", res);

    return 0;
}

// Takes in 9 inputs and adds them up in a complicated way
int func2(int x1, int x2, int x3, int x4, int x5, int x6, int x7, int x8, int x9) {
    int r1 = x1 + x4 + x7;
    int r2 = x2 + x5 + x8;
    int r3 = x3 + x6 + x9;
    return r3 - r2 + r1;
}
