#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tree[100];
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter tree elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &tree[i]);

    printf("\nBinary Tree (Array Representation):\n");
    for (i = 0; i < n; i++)
    {
        printf("Node %d : %d", i, tree[i]);

        if (2*i + 1 < n)
            printf("  Left Child: %d", tree[2*i + 1]);

        if (2*i + 2 < n)
            printf("  Right Child: %d", tree[2*i + 2]);

        printf("\n");
    }

    fflush(stdout);          // flush output buffer
    system("getmac");        // works only on Windows

    return 0;
}