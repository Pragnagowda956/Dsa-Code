#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

/* Enqueue operation */
void enqueue(int x)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

/* Dequeue operation */
void dequeue()
{
    struct node *temp;

    if (front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }

    temp = front;
    front = front->next;

    printf("Deleted element: %d\n", temp->data);
    free(temp);

    if (front == NULL)
        rear = NULL;
}

/* Display queue */
void display()
{
    struct node *temp;

    if (front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements: ");
    temp = front;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int n, value;

    printf("Enter number of elements: ");
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