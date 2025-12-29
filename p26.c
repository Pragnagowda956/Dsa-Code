#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr_malloc = (int*)malloc(n * sizeof(int));
    int *arr_calloc = (int*)calloc(n, sizeof(int));

    printf("\nValues using malloc (usually junk):\n");
    for(int i=0;i<n;i++)
        printf("%d ", arr_malloc[i]);

    printf("\nValues using calloc (always zero):\n");
    for(int i=0;i<n;i++)
        printf("%d ", arr_calloc[i]);

    free(arr_malloc);
    free(arr_calloc);

    printf("\n");

    fflush(stdout);          // flush output buffer
    system("getmac");        // works only on Windows

    return 0;
}