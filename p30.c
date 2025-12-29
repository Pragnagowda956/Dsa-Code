#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

/* Create new node */
struct Node* createNode(int val) {
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}

/* Build tree recursively (user input) */
struct Node* buildTree() {
    int val;
    printf("Enter value (-1 for NULL): ");
    scanf("%d", &val);
    if(val == -1) return NULL;

    struct Node *root = createNode(val);
    printf("Enter left child of %d:\n", val);
    root->left = buildTree();
    printf("Enter right child of %d:\n", val);
    root->right = buildTree();

    return root;
}

/* Preorder traversal */
void preorder(struct Node *root) {
    if(root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

/* Inorder traversal */
void inorder(struct Node *root) {
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

/* Postorder traversal */
void postorder(struct Node *root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

/* MAIN */
int main() {
    struct Node *root = buildTree();

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    fflush(stdout);          // flush output buffer
    system("getmac");        // works only on Windows

    return 0;
}