#include <stdio.h>

int graph[10][10], visited[10];
int n;

// DFS function
void DFS(int node) {
    int i;

    printf("%d ", node);   // print node
    visited[node] = 1;     // mark visited

    for (i = 1; i <= n; i++) {
        if (graph[node][i] == 1 && visited[i] == 0) {
            DFS(i);   // recursive call
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting node: ");
    scanf("%d", &start);

    DFS(start);

    return 0;
}
