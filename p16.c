#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int power;
    struct node *next;
};

struct node *head = NULL;

/* Insert term at end */
void insert(int c, int p)
{
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->coeff = c;
    newnode->power = p;
    newnode->next = NULL;

    if (head == NULL)
        head = newnode;
    else
    {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}

/* Display polynomial */
void display()
{
    struct node *temp = head;

    printf("Polynomial: ");
    while (temp != NULL)
    {
        printf("%dx^%d", temp->coeff, temp->power);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int n, c, p;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Enter coefficient and power:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &c, &p);
        insert(c, p);
    }

    display();

    fflush(stdout);          // flush output buffer
    system("getmac");        // works only on Windows

    return 0;
}