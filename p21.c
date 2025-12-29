#include <stdio.h>
#include <stdlib.h>

/* ---------- Tree Node ---------- */
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

/* ---------- Queue ---------- */
struct queue
{
    struct node *data;
    struct queue *next;
};

struct queue *front = NULL, *rear = NULL;

/* Queue operations */
void enqueue(struct node *x)
{
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->data = x;
    q->next = NULL;

    if (rear == NULL)
        front = rear = q;
    else
    {
        rear->next = q;
        rear = q;
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
struct node* createNode(int x)
{
    struct node *newnode =
        (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->left = newnode->right = NULL;
    return newnode;
}

/* Insert node (level order) */
void insert(struct node **root, int x)
{
    struct node *temp, *newnode = createNode(x);

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

/* Delete deepest node */
void deleteDeepest(struct node *root, struct node *dnode)
{
    struct node *temp;
    enqueue(root);

    while (front != NULL)
    {
        temp = dequeue();

        if (temp->left)
        {
            if (temp->left == dnode)
            {
                free(temp->left);
                temp->left = NULL;
                return;
            }
            else
                enqueue(temp->left);
        }

        if (temp->right)
        {
            if (temp->right == dnode)
            {
                free(temp->right);
                temp->right = NULL;
                return;
            }
            else
                enqueue(temp->right);
        }
    }
}

/* Delete given key */
void deleteNode(struct node *root, int key)
{
    struct node *temp, *keyNode = NULL;

    enqueue(root);

    while (front != NULL)
    {
        temp = dequeue();
        if (temp->data == key)
            keyNode = temp;

        if (temp->left) enqueue(temp->left);
        if (temp->right) enqueue(temp->right);
    }

    if (keyNode != NULL)
    {
        int x = temp->data;
        deleteDeepest(root, temp);
        keyNode->data = x;
        printf("Node deleted successfully\n");
    }
    else
        printf("Node not found\n");
}

/* Inorder Traversal */
void inorder(struct node *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct node *root = NULL;
    int n, value, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        insert(&root, value);
    }

    printf("Enter element to delete: ");
    scanf("%d", &key);

    deleteNode(root, key);

    printf("Inorder traversal after deletion:\n");
    inorder(root);
    printf("\n");

    fflush(stdout);          // flush output buffer
    system("getmac");

    return 0;
}