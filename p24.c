#include <stdio.h>
#include <stdlib.h>

/* ---------- Tree Node ---------- */
struct node {
    int data;
    struct node *left;
    struct node *right;
};

/* ---------- Queue for Tree Nodes ---------- */
struct queue {
    struct node *data;
    struct queue *next;
};

struct queue *front = NULL, *rear = NULL;

/* Queue Operations */
void enqueue(struct node *x) {
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->data = x;
    q->next = NULL;

    if(rear == NULL)
        front = rear = q;
    else {
        rear->next = q;
        rear = q;
    }
}

struct node* dequeue() {
    if(front == NULL) return NULL;
    struct queue *temp = front;
    struct node *x = temp->data;
    front = front->next;
    if(front == NULL) rear = NULL;
    free(temp);
    return x;
}

int isEmpty() {
    return front == NULL;
}

/* Create Tree Node */
struct node* createNode(int val) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}

/* Level Order Traversal */
void levelOrder(struct node *root) {
    if(root == NULL) return;
    enqueue(root);

    printf("Level Order Traversal: ");
    while(!isEmpty()) {
        struct node *temp = dequeue();
        printf("%d ", temp->data);
        if(temp->left) enqueue(temp->left);
        if(temp->right) enqueue(temp->right);
    }
    printf("\n");
}

/* Build Tree from User Input (Level Order) */
struct node* buildTree(int n) {
    if(n <= 0) return NULL;

    int value;
    printf("Enter value of root: ");
    scanf("%d", &value);
    struct node *root = createNode(value);
    enqueue(root);

    int count = 1;
    while(count < n) {
        struct node *temp = dequeue();

        // Left child
        if(count < n) {
            printf("Enter left child of %d: ", temp->data);
            scanf("%d", &value);
            temp->left = createNode(value);
            enqueue(temp->left);
            count++;
        }

        // Right child
        if(count < n) {
            printf("Enter right child of %d: ", temp->data);
            scanf("%d", &value);
            temp->right = createNode(value);
            enqueue(temp->right);
            count++;
        }
    }

    return root;
}

/* MAIN */
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct node *root = buildTree(n);

    levelOrder(root);

    fflush(stdout);          // flush output buffer
    system("getmac");        // works only on Windows

    return 0;
}