#include <stdio.h>
#include <stdlib.h>

/* Tree Node */
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

/* Queue for tree nodes */
struct queue
{
    struct node *data;
    struct queue *next;
};

struct queue *front = NULL, *rear = NULL;

/* Queue functions */
void enqueue(struct node *x)
{
    struct queue *newq = (struct queue*)malloc(sizeof(struct queue));
    newq->data = x;
    newq->next = NULL;

    if (rear == NULL)
        front = rear = newq;
    else
    {
        rear->next = newq;
        rear = newq;
    }
}

struct node* dequeue()
{
    struct queue *temp;
    struct node *x;

    if (front == NULL)
        return NULL;

    temp = front;
    x = temp->data;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
    return x;
}

/* Create Node */
struct node* createNode(int value)
{
    struct node *newnode =
        (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}

/* Insert Node */
void insertNode(struct node **root, int value)
{
    struct node *temp, *newnode;
    newnode = createNode(value);

    if (*root == NULL)
    {
        *root = newnode;
        return;
    }

    enqueue(*root);

    while (front != NULL)
    {
        temp = dequeue();

        if (temp->left == NULL)
        {
            temp->left = newnode;
            return;
        }
        else
            enqueue(temp->left);

        if (temp->right == NULL)
        {
            temp->right = newnode;
            return;
        }
        else
            enqueue(temp->right);
    }
}

/* Inorder Traversal */
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/* MAIN */
int main()
{
    struct node *root = NULL;
    int n, value;

    printf("Enter number of nodes to insert: ");
    scanf("%d", &n);

    printf("Enter values:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        insertNode(&root, value);
    }

    printf("Inorder Traversal after insertion:\n");
    inorder(root);
    printf("\n");

    fflush(stdout);          // flush output buffer
    system("getmac");        // works only on Windows

    return 0;
}