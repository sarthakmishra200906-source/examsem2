#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Node structure for the linked list
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[MAX]; // Array of pointers to keep track of lists
int n; // Number of vertices

// Function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge
void addEdge(int u, int v) {
    // Add v to u's list
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    // Add u to v's list (for undirected graph)
    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// Function to display the graph
void printGraph() {
    printf("\nAdjacency List:\n");
    for (int i = 0; i < n; i++) {
        struct Node* temp = adj[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("-> NULL\n");
    }
}

int main() {
    int choice, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize pointers to NULL
    for (int i = 0; i < n; i++) adj[i] = NULL;

    while (1) {
        printf("\n--- Graph Menu (List) ---\n");
        printf("1. Add Edge\n2. Display Graph\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter edge (u v): ");
                scanf("%d %d", &u, &v);
                if (u < n && v < n) addEdge(u, v);
                else printf("Invalid vertices!\n");
                break;
            case 2:
                printGraph();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}