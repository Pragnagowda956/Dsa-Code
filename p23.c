#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int queue[MAX], front=-1, rear=-1;

void enqueue(int x) {
    if(rear < MAX-1) {
        if(front==-1) front=0;
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

int isEmpty() {
    return front==-1;
}

void BFS(int n, int adj[n][n], int start) {
    int visited[n];
    for(int i=0;i<n;i++) visited[i]=0;

    enqueue(start);
    visited[start]=1;

    printf("BFS Traversal: ");

    while(!isEmpty()) {
        int v = dequeue();
        printf("%d ", v);

        for(int i=0;i<n;i++) {
            if(adj[v][i] && !visited[i]) {
                enqueue(i);
                visited[i]=1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, start;
    printf("Enter number of vertices: ");
    scanf("%d",&n);

    int adj[n][n];
    printf("Enter adjacency matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&adj[i][j]);

    printf("Enter starting vertex (0 to %d): ", n-1);
    scanf("%d",&start);

    BFS(n, adj, start);

    fflush(stdout);          // flush output buffer
    system("getmac");        // works only on Windows

    return 0;
}