#include <stdio.h>
#include <stdlib.h>

/* -------- Tree Node -------- */
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

/* -------- Queue -------- */
struct queue
{
    struct node *data;
    struct queue *next;
};

struct queue *front = NULL, *rear = NULL;

/* Enqueue */
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

/* Dequeue */
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

/* Create Tree Node */
struct node* createNode(int x)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->left = newnode->right = NULL;
    return newnode;
}

/* Build Tree */
struct node* buildTree(int n)
{
    struct node *root, *temp;
    int value;

    printf("Enter root value: ");
    scanf("%d", &value);

    root = createNode(value);
    enqueue(root);

    for (int i = 1; i < n; i += 2)
    {
        temp = dequeue();

        printf("Enter left child of %d: ", temp->data);
        scanf("%d", &value);
        temp->left = createNode(value);
        enqueue(temp->left);

        if (i + 1 < n)
        {
            printf("Enter right child of %d: ", temp->data);
            scanf("%d", &value);
            temp->right = createNode(value);
            enqueue(temp->right);
        }
    }

    return root;
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

/* -------- MAIN -------- */
int main()
{
    int n;
    struct node *root;

    printf("Enter total number of nodes: ");
    scanf("%d", &n);

    root = buildTree(n);

    printf("\nInorder Traversal:\n");
    inorder(root);
    printf("\n");

    fflush(stdout);          // flush output buffer
    system("getmac");

    return 0;
}