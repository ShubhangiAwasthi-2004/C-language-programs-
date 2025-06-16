#include <stdio.h>
#include <stdbool.h>

bool isPowerOf2(int n) {
    // A number is a power of 2 if it is > 0 and n & (n - 1) == 0
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main() {
    int x = 16;

    if (isPowerOf2(x))
        printf("%d is a power of 2\n", x);
    else
        printf("%d is NOT a power of 2\n", x);

    return 0;
}
