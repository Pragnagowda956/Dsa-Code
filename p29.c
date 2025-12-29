#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct Node {
    int data;
    struct Node *next;
};

/* Insert at position (1-based) */
struct Node* insertMiddle(struct Node *head, int pos, int val) {
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = NULL;

    if(pos == 1) {
        newnode->next = head;
        return newnode;
    }

    struct Node *temp = head;
    for(int i=1;i<pos-1 && temp != NULL;i++)
        temp = temp->next;

    if(temp == NULL) {
        printf("Position out of range\n");
        free(newnode);
        return head;
    }

    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}

/* Delete at position (1-based) */
struct Node* deleteMiddle(struct Node *head, int pos) {
    if(head == NULL) return NULL;

    struct Node *temp = head, *prev = NULL;

    if(pos == 1) {
        head = head->next;
        free(temp);
        return head;
    }

    for(int i=1;i<pos && temp!=NULL;i++) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Position out of range\n");
        return head;
    }

    prev->next = temp->next;
    free(temp);
    return head;
}

/* Traverse */
void traverse(struct Node *head) {
    struct Node *temp = head;
    printf("Linked List: ");
    while(temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* MAIN */
int main() {
    struct Node *head = NULL;
    int n, val, pos;

    printf("Enter number of initial elements: ");
    scanf("%d",&n);

    printf("Enter elements:\n");
    for(int i=0;i<n;i++) {
        scanf("%d",&val);
        head = insertMiddle(head, i+1, val); // insert at end initially
    }

    traverse(head);

    // Insert in middle
    printf("Enter position to insert: ");
    scanf("%d",&pos);
    printf("Enter value to insert: ");
    scanf("%d",&val);
    head = insertMiddle(head,pos,val);
    traverse(head);

    // Delete in middle
    printf("Enter position to delete: ");
    scanf("%d",&pos);
    head = deleteMiddle(head,pos);
    traverse(head);

    fflush(stdout);          // flush output buffer
    system("getmac");        // works only on Windows

    return 0;
}