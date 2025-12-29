#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r, c, i, j;
    int a[10][10];
    int triplet[20][3];
    int count = 0, k = 1;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter matrix elements:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    /* Count non-zero elements */
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            if (a[i][j] != 0)
                count++;

    /* First row of triplet */
    triplet[0][0] = r;
    triplet[0][1] = c;
    triplet[0][2] = count;

    /* Store non-zero elements */
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (a[i][j] != 0)
            {
                triplet[k][0] = i;
                triplet[k][1] = j;
                triplet[k][2] = a[i][j];
                k++;
            }
        }
    }

    printf("\nSparse Matrix in Triplet Form:\n");
    printf("Row  Col  Value\n");
    for (i = 0; i <= count; i++)
        printf("%d    %d    %d\n",
               triplet[i][0],
               triplet[i][1],
               triplet[i][2]);

    fflush(stdout);          // flush output buffer
    system("getmac");        // works only on Windows

    return 0;
}