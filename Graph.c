
#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int V;

void addEdge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void printAdjMatrix() {
    int i, j;

    printf("Adjacency Matrix:\n");

    // Print column headings
    printf("   ");
    for (i = 0; i < V; i++) {
        printf("%d ", i);
    }
    printf("\n");

    // Print matrix with row headings
    for (i = 0; i < V; i++) {
        printf("%d  ", i);

        for (j = 0; j < V; j++) {
            printf("%d ", graph[i][j]);
        }

        printf("\n");
}
}

int main() {
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    // Initialize adjacency matrix
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }

    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(2, 3);
    addEdge(2, 4);

    printAdjMatrix();

    return 0;
}
