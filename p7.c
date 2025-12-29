#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;   // self-referential pointer
};

int main()
{
    struct node n1, n2;

    n1.data = 10;
    n2.data = 20;

    n1.next = &n2;
    n2.next = NULL;

    printf("First node data: %d\n", n1.data);
    printf("Second node data: %d\n", n1.next->data);

    fflush(stdout);          // flush output buffer
    system("getmac");        // works only on Windows

    return 0;
}