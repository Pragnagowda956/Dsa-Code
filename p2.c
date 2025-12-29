#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 10;
    int *ptr = &x;

    printf("Address of x: %p\n", (void*)&x);
    printf("Address of ptr: %p\n", (void*)&ptr);

    fflush(stdout);
    system("getmac");
    return 0;
}