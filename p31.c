#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int cq[MAX];
int front = -1, rear = -1;

/* Check if queue is full */
int isFull() {
    return (rear + 1) % MAX == front;
}

/* Check if queue is empty */
int isEmpty() {
    return front == -1;
}

/* Enqueue */
void enqueue(int val) {
    if(isFull()) {
        printf("Queue is full! Cannot insert %d\n", val);
        return;
    }
    if(front == -1) front = 0;
    rear = (rear + 1) % MAX;
    cq[rear] = val;
    printf("%d inserted\n", val);
}

/* Dequeue */
int dequeue() {
    if(isEmpty()) {
        printf("Queue is empty! Cannot delete\n");
        return -1;
    }
    int val = cq[front];
    if(front == rear) {
        front = rear = -1;  // only one element was present
    } else {
        front = (front + 1) % MAX;
    }
    return val;
}

/* Display queue */
void display() {
    if(isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while(1) {
        printf("%d ", cq[i]);
        if(i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, val;

    do {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d",&val);
                enqueue(val);
                break;
            case 2:
                val = dequeue();
                if(val != -1) printf("Deleted: %d\n", val);
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 4);

    fflush(stdout);          // flush output buffer
    system("getmac");        // works only on Windows

    return 0;
}