#include <stdio.h>

int a[10][10], vis[10], V;

void bfs(int src) {
    int Q[100], front = 0, rear = 0;
    int u, v;

    for (int i = 0; i < V; i++)
        vis[i] = 0;

    Q[rear++] = src;
    vis[src] = 1;

    while (front < rear) {
        u = Q[front++];
        printf("%d ", u);

        for (v = 0; v < V; v++) {
            if (a[u][v] == 1 && vis[v] == 0) {
                vis[v] = 1;
                Q[rear++] = v;
            }
        }
    }
}
int main() {
    int i, j, src;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    printf("BFS Traversal: ");
    bfs(src);

    return 0;
}