#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int num_vertices;
    int num_edges;
    int **adj_matrix;
} GraphStruct;

typedef GraphStruct *Graph;
typedef unsigned int Vertex;

typedef struct {
    Vertex v;
    Vertex w;
    int weight;
} Edge;

Graph createGraph(int num_vertices, int num_edges) {
    Graph graph = (Graph)malloc(sizeof(GraphStruct));
    if (!graph) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    graph->num_vertices = num_vertices;
    graph->num_edges = num_edges;
    graph->adj_matrix = (int **)malloc(num_vertices * sizeof(int *));
    if (!graph->adj_matrix) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < num_vertices; ++i) {
        graph->adj_matrix[i] = (int *)calloc(num_vertices, sizeof(int));
        if (!graph->adj_matrix[i]) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
    }

    return graph;
}

void addEdge(Graph graph, Edge edge) {
    graph->adj_matrix[edge.v][edge.w] = edge.weight;
}

void freeGraph(Graph graph) {
    for (int i = 0; i < graph->num_vertices; ++i) {
        free(graph->adj_matrix[i]);
    }
    free(graph->adj_matrix);
    free(graph);
}

void DFS(Graph graph, Vertex v, bool *visited, bool *dominance, int *dominators) {
    visited[v] = true;
    for (Vertex w = 0; w < graph->num_vertices; ++w) {
        if (graph->adj_matrix[v][w] && !visited[w]) {
            dominators[w]++;
            if (dominators[w] == graph->num_vertices - 1) {
                dominance[w] = true;
            }
            DFS(graph, w, visited, dominance, dominators);
        }
    }
}

void findDominance(Graph graph) {
    bool dominance[graph->num_vertices];
    for (int i = 0; i < graph->num_vertices; ++i) {
        dominance[i] = false;
    }
    bool visited[graph->num_vertices];
    int dominators[graph->num_vertices];
    for (int i = 0; i < graph->num_vertices; ++i) {
        visited[i] = false;
        dominators[i] = 0;
    }

    DFS(graph, 0, visited, dominance, dominators);

    for (Vertex v = 0; v < graph->num_vertices; ++v) {
        if (v != 0 && dominance[v]) {
            printf("(%u#%u)", 0, v);
        }
    }
    printf("\n");
}

int main() {
    int num_vertices, num_edges;
    scanf("%d,%d", &num_vertices, &num_edges);
    
    Graph graph = createGraph(num_vertices, num_edges);

    for (int i = 0; i < num_edges; ++i) {
        Edge edge;
        scanf("%u,%u,%d", &edge.v, &edge.w, &edge.weight);
        addEdge(graph, edge);
    }

    findDominance(graph);

    freeGraph(graph);
    return 0;
}
