#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Maximum vertices

int adj[MAX][MAX];
int visited[MAX];
int n; // Number of vertices

// Reset matrix to 0
void init() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
}

// Add an undirected edge
void addEdge(int u, int v) {
    if (u >= 0 && u < n && v >= 0 && v < n) {
        adj[u][v] = 1;
        adj[v][u] = 1; 
    } else {
        printf("Invalid vertex index!\n");
    }
}

void display() {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

// Simple DFS Traversal
void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    int choice, u, v, start;

    printf("Enter number of vertices (max %d): ", MAX);
    scanf("%d", &n);
    init();

    while (1) {
        printf("\n--- Adjacency Matrix Menu ---\n");
        printf("1. Add Edge\n2. Display Matrix\n3. DFS Traversal\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter edge (u v): ");
                scanf("%d %d", &u, &v);
                addEdge(u, v);
                break;
            case 2:
                display();
                break;
            case 3:
                for(int i = 0; i < n; i++) visited[i] = 0;
                printf("Enter starting vertex: ");
                scanf("%d", &start);
                printf("DFS traversal: ");
                DFS(start);
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}