#include <stdio.h>
int parent[10];

int find(int i) {
    while(parent[i])
        i = parent[i];
    return i;
}

void unionSet(int i, int j) {
    parent[j] = i;
}

int main() {
    int n, i, j, a, b;
    int min, mincost = 0;
    int cost[10][10];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    printf("Edges in MST:\n");

    int edges = 0;
    while(edges < n - 1) {
        min = 999;

        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                if(cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        int u = find(a);
        int v = find(b);

        if(u != v) {
            printf("%d -> %d = %d\n", a, b, min);
            mincost += min;
            unionSet(u, v);
            edges++;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("Total cost = %d", mincost);

    return 0;
}
