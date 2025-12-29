#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int stack[MAX], top = -1;

void push(int x) {
    if(top < MAX-1)
        stack[++top] = x;
}

int pop() {
    if(top >= 0)
        return stack[top--];
    return -1;
}

int isEmpty() {
    return top == -1;
}

void DFS(int n, int adj[n][n], int start) {
    int visited[n];
    for(int i=0; i<n; i++) visited[i] = 0;

    push(start);

    printf("DFS Traversal: ");

    while(!isEmpty()) {
        int v = pop();
        if(!visited[v]) {
            printf("%d ", v);
            visited[v] = 1;
        }

        // Push adjacent nodes
        for(int i = n-1; i >=0; i--) {
            if(adj[v][i] && !visited[i])
                push(i);
        }
    }
    printf("\n");
}

int main() {
    int n, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[n][n];
    printf("Enter adjacency matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&adj[i][j]);

    printf("Enter starting vertex (0 to %d): ", n-1);
    scanf("%d",&start);

    DFS(n, adj, start);

    fflush(stdout);          // flush output buffer
    system("getmac");        // works only on Windows

    return 0;
}