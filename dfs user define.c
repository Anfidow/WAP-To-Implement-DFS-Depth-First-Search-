#include <stdio.h>
#define MAX_VERTICES 10
int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int numVertices;
void DFS(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (int i = 0; i < numVertices; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}
int main() {
    int edges, src, dest;
    printf("Enter the number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &numVertices);
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
        for (int j = 0; j < numVertices; j++) {
            graph[i][j] = 0;
        }
    }
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < edges; i++) {
        printf("Enter edge (src dest): ");
        scanf("%d %d", &src, &dest);
        graph[src][dest] = 1;
        graph[dest][src] = 1;
    }
    printf("Depth First Search starting from vertex 0:\n");
    DFS(0);
    return 0;
}