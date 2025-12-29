#include <stdio.h>
#include <stdlib.h>

void selectionSort(int a[], int n)
{
    int min, temp;

    for(int i = 0; i < n - 1; i++)
    {
        min = i;
        for(int j = i + 1; j < n; j++)
        {
            if(a[j] < a[min])
                min = j;
        }

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}
int main()
{
    int a[20];
    int n;

    printf("Enter size: ");
    scanf("%d", &n);
    printf("Enter elements: ",&a);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    selectionSort(a, n);

    printf("Sorted array:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nProgram Output: Success\n");
    fflush(stdout);          // flush output buffer
    system("getmac");        // works only on Windows

    return 0;
}