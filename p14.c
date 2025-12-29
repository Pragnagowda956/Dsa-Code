#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ---------- ARRAY OPERATIONS ---------- */
void arrayOperations(int n)
{
    int arr[10000];
    clock_t start, end;

    /* Insertion */
    start = clock();
    for (int i = 0; i < n; i++)
        arr[i] = i;
    end = clock();

    printf("Array Insertion Time: %f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    /* Deletion */
    start = clock();
    for (int i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];
    end = clock();

    printf("Array Deletion Time: %f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);
}

/* ---------- LINKED LIST ---------- */
struct node
{
    int data;
    struct node *next;
};

void linkedListOperations(int n)
{
    struct node *head = NULL, *temp;
    clock_t start, end;

    /* Insertion */
    start = clock();
    for (int i = 0; i < n; i++)
    {
        struct node *newnode =
            (struct node*)malloc(sizeof(struct node));
        newnode->data = i;
        newnode->next = head;
        head = newnode;
    }
    end = clock();

    printf("Linked List Insertion Time: %f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    /* Deletion */
    start = clock();
    temp = head;
    if (temp != NULL)
    {
        head = head->next;
        free(temp);
    }
    end = clock();

    printf("Linked List Deletion Time: %f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);
}

/* ---------- MAIN ---------- */
int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    arrayOperations(n);
    linkedListOperations(n);

    fflush(stdout);          // flush output buffer
    system("getmac");        // works only on Windows

    return 0;
}