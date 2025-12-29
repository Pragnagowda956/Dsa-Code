#include <stdio.h>
int main()
{
    int a;
    printf("Enter element: ");
    scanf("%d",&a);
    printf("Initial Value (A): %d",a);
    printf("\nPre Increment: %d", ++a);
    printf("\nPost Increment: %d", a++);
    printf("\n");
    fflush(stdout);          // flush output buffer
    system("getmac");        // works only on Windows

    return 0;
}