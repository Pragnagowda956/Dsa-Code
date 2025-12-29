#include <stdio.h>
#include <stdlib.h>

/* Node Structure */
struct Node {
    int data;
    struct Node *next;
};

/* Create Node */
struct Node* createNode(int val) {
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

/* Insert at end */
struct Node* insertEnd(struct Node *head, int val) {
    struct Node *newnode = createNode(val);
    if(head == NULL) {
        newnode->next = newnode;
        return newnode;
    }

    struct Node *temp = head;
    while(temp->next != head) temp = temp->next;
    temp->next = newnode;
    newnode->next = head;
    return head;
}

/* Delete a node with value key */
struct Node* deleteNode(struct Node *head, int key) {
    if(head == NULL) return NULL;

    struct Node *curr = head, *prev = NULL;

    // Single node case
    if(head->data == key && head->next == head) {
        free(head);
        return NULL;
    }

    // Find the node to delete
    do {
        if(curr->data == key) break;
        prev = curr;
        curr = curr->next;
    } while(curr != head);

    if(curr->data != key) {
        printf("Node not found\n");
        return head;
    }

    // Deleting head node
    if(curr == head) {
        struct Node *last = head;
        while(last->next != head) last = last->next;
        last->next = head->next;
        head = head->next;
        free(curr);
    } else {
        prev->next = curr->next;
        free(curr);
    }

    return head;
}

/* Traverse */
void traverse(struct Node *head) {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);
    printf("\n");
}

/* MAIN */
int main() {
    struct Node *head = NULL;
    int n, val, key;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements:\n");
    for(int i=0;i<n;i++) {
        scanf("%d",&val);
        head = insertEnd(head,val);
    }

    traverse(head);

    printf("Enter value to delete: ");
    scanf("%d",&key);
    head = deleteNode(head,key);

    traverse(head);

    fflush(stdout);          // flush output buffer
    system("getmac");        // works only on Windows

    return 0;
}
