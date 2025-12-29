#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, temp;
    printf("Enter size: ");
    scanf("%d", &n);
    printf("Enter Elements: ");
    int *a = (int*)malloc(n * sizeof(int));

    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);

    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("Sorted array:\n");
    for(int i=0; i<n; i++)
        printf("%d ", a[i]);

    free(a);

    fflush(stdout);
    system("getmac");
    return 0;
}