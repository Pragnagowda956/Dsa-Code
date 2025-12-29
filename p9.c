#include <stdio.h>
int main()
{
    int a;
    printf("Enter element: ");
    scanf("%d",&a);
    printf("Initial Value (A): %d",a);
    printf("\nPre Decrement: %d", --a);
    printf("\nPost Decrement: %d", a--);
    printf("\n");
    fflush(stdout);          // flush output buffer
    system("getmac");        // works only on Windows

    return 0;
}