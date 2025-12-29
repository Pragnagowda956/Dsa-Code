#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, cols;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    /* Dynamic memory allocation for 2D array */
    int **a = (int**)malloc(rows * sizeof(int*));

    for(int i = 0; i < rows; i++)
        a[i] = (int*)malloc(cols * sizeof(int));

    /* Reading elements */
    printf("Enter elements:\n");
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            scanf("%d", &a[i][j]);

    /* Printing elements */
    printf("2D Array:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    /* Freeing memory */
    for(int i = 0; i < rows; i++)
        free(a[i]);
    free(a);
    fflush(stdout);          // flush output buffer
    system("getmac");
    return 0;
}