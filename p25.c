#include <stdio.h>
#include <stdlib.h>

#define MAX 20

/* Stack for DFS */
int stack[MAX], top = -1;

void push(int x) {
    if(top < MAX-1) stack[++top] = x;
}

int pop() {
    if(top >= 0) return stack[top--];
    return -1;
}

int isStackEmpty() { return top == -1; }

/* Queue for BFS */
int queue[MAX], front=-1, rear=-1;

void enqueue(int x) {
    if(rear < MAX-1) {
        if(front == -1) front=0;
        queue[++rear] = x;
    }
}

int dequeue() {
    if(front != -1) {
        int x = queue[front];
        if(front==rear) front=rear=-1;
        else front++;
        return x;
    }
    return -1;
}

int isQueueEmpty() { return front==-1; }

/* Node for adjacency list */
struct adjNode {
    int vertex;
    struct adjNode *next;
};

/* Adjacency list array */
struct adjNode* adjList[MAX];

/* Add edge to adjacency list (undirected) */
void addEdge(int u, int v) {
    struct adjNode *newNode = (struct adjNode*)malloc(sizeof(struct adjNode));
    newNode->vertex = v;
    newNode->next = adjList[u];
    adjList[u] = newNode;

    // For undirected graph
    newNode = (struct adjNode*)malloc(sizeof(struct adjNode));
    newNode->vertex = u;
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

/* DFS using stack */
void DFS(int n, int start) {
    int visited[n];
    for(int i=0;i<n;i++) visited[i]=0;

    push(start);
    printf("DFS Traversal: ");

    while(!isStackEmpty()) {
        int v = pop();
        if(!visited[v]) {
            printf("%d ", v);
            visited[v] = 1;

            struct adjNode *temp = adjList[v];
            // push adjacent vertices in reverse order for correct sequence
            int tempStack[MAX], t=0;
            while(temp) {
                if(!visited[temp->vertex])
                    tempStack[t++] = temp->vertex;
                temp = temp->next;
            }
            for(int i=t-1;i>=0;i--) push(tempStack[i]);
        }
    }
    printf("\n");
}

/* BFS using queue */
void BFS(int n, int start) {
    int visited[n];
    for(int i=0;i<n;i++) visited[i]=0;

    enqueue(start);
    visited[start]=1;

    printf("BFS Traversal: ");

    while(!isQueueEmpty()) {
        int v = dequeue();
        printf("%d ", v);

        struct adjNode *temp = adjList[v];
        while(temp) {
            if(!visited[temp->vertex]) {
                enqueue(temp->vertex);
                visited[temp->vertex]=1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    int n, e, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter number of edges: ");
    scanf("%d",&e);

    for(int i=0;i<n;i++) adjList[i]=NULL;

    printf("Enter edges (u v):\n");
    for(int i=0;i<e;i++) {
        scanf("%d %d",&u,&v);
        addEdge(u,v);
    }

    printf("Enter starting vertex: ");
    scanf("%d",&start);

    DFS(n,start);
    BFS(n,start);

    fflush(stdout);          // flush output buffer
    system("getmac");        // works only on Windows

    return 0;
}