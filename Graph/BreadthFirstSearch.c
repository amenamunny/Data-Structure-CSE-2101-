#include <stdio.h>

int graph[10][10], visited[10];
int queue[10], front = -1, rear = -1;
int n;

// enqueue function
void enqueue(int value)
 {
    if (rear == 9)
        return;
    else {
        if (front == -1)
            front = 0;
        queue[++rear] = value;
    }
}

// dequeue function
int dequeue() {
    if (front == -1)
        return -1;
    else {
        int value = queue[front];
        front++;
        return value;
    }
}

// BFS function
void BFS(int start) {
    int i;

    enqueue(start);
    visited[start] = 1;

    while (front <= rear) {
        int node = dequeue();
        printf("%d ", node);

        for (i = 1; i <= n; i++) {
            if (graph[node][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
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

    BFS(start);

    return 0;
}
