#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* insert(struct node* root, int val) {
    if (!root) {
        struct node* n = malloc(sizeof(struct node));
        n->data = val; n->left = n->right = NULL;
        return n;
    }
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

void inorder(struct node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct node* root = NULL;
    int n, v;

    printf("Enter the no. of ele: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &v);
        root = insert(root, v);
    }

    printf("Inorder Traversal: ");
    inorder(root);

    printf("\n");
    system("getmac");
    return 0;
}