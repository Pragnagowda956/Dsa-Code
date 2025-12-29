#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

/* Push operation */
void push(int x)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

/* Pop operation */
void pop()
{
    struct node *temp;

    if (top == NULL)
    {
        printf("Stack is Empty\n");
        return;
    }

    temp = top;
    top = top->next;
    printf("Popped element: %d\n", temp->data);
    free(temp);
}

/* Display stack */
void display()
{
    struct node *temp;

    if (top == NULL)
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack elements: ");
    temp = top;
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
        push(value);
    }

    display();
    pop();
    display();

    fflush(stdout);          // flush output buffer
    system("getmac");        // works only on Windows

    return 0;
}