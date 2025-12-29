#include <stdio.h>
#include <stdlib.h>

int queue[100];
int front = -1, rear = -1, size;

void enqueue(int x)
{
    if (rear == size - 1)
    {
        printf("Queue is Full\n");
        return;
    }

    if (front == -1)
        front = 0;

    queue[++rear] = x;
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front++]);
}

void display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main()
{
    int n, value;

    printf("Enter queue size: ");
    scanf("%d", &size);

    printf("Enter number of elements to insert: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        enqueue(value);
    }

    display();

    dequeue();
    display();

    fflush(stdout);          // flush output buffer
    system("getmac");        // works only on Windows

    return 0;
}