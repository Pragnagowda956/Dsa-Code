#include <stdio.h>
#include <stdlib.h>

/* Node for non-zero element */
struct Node {
    int row;
    int col;
    int value;
    struct Node *next;
};

/* Create new node */
struct Node* createNode(int r, int c, int val) {
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->row = r;
    newnode->col = c;
    newnode->value = val;
    newnode->next = NULL;
    return newnode;
}

/* Insert node at end */
struct Node* insertNode(struct Node *head, int r, int c, int val) {
    struct Node *newnode = createNode(r,c,val);
    if(head == NULL) return newnode;

    struct Node *temp = head;
    while(temp->next != NULL) temp = temp->next;
    temp->next = newnode;
    return head;
}

/* Display sparse matrix */
void displaySparse(struct Node *head, int rows, int cols) {
    struct Node *temp = head;
    printf("\nSparse Matrix:\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(temp != NULL && temp->row==i && temp->col==j){
                printf("%d ", temp->value);
                temp = temp->next;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    int rows, cols, n, r, c, val;
    struct Node *head = NULL;

    printf("Enter number of rows: ");
    scanf("%d",&rows);
    printf("Enter number of columns: ");
    scanf("%d",&cols);

    printf("Enter number of non-zero elements: ");
    scanf("%d",&n);

    printf("Enter row, column and value of each non-zero element:\n");
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&r,&c,&val);
        head = insertNode(head,r,c,val);
    }

    displaySparse(head, rows, cols);

    fflush(stdout);          // flush output buffer
    system("getmac");        // works only on Windows

    return 0;
}