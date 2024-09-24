#include <stdio.h>
#include <stdlib.h>

typedef unsigned int Vertex;

typedef struct {
    int vertex_num;
    int edge_num;
    int **edges;
} GraphStruct;

typedef struct {
    Vertex v;
    Vertex w;
    int weight;
} Edge;

GraphStruct *createGraph(int vertex_num, int edge_num) {
    GraphStruct *graph = (GraphStruct *)malloc(sizeof(GraphStruct));
    if (!graph) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    graph->vertex_num = vertex_num;
    graph->edge_num = edge_num;

    graph->edges = (int **)malloc(vertex_num * sizeof(int *));
    if (!graph->edges) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < vertex_num; ++i) {
        graph->edges[i] = (int *)calloc(vertex_num, sizeof(int));
        if (!graph->edges[i]) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
    }

    return graph;
}

void destroyGraph(GraphStruct *graph) {
    if (graph) {
        if (graph->edges) {
            for (int i = 0; i < graph->vertex_num; ++i) {
                free(graph->edges[i]);
            }
            free(graph->edges);
        }
        free(graph);
    }
}

void addEdge(GraphStruct *graph, Vertex v, Vertex w, int weight) {
    graph->edges[v][w] = weight;
}

void dfs(GraphStruct *graph, int *dom, Vertex v) {
    dom[v] = 1;
    for (int i = 0; i < graph->vertex_num; ++i) {
        if (graph->edges[v][i] && !dom[i]) {
            dfs(graph, dom, i);
        }
    }
}

void computeDomination(GraphStruct *graph) {
    int *dom = (int *)calloc(graph->vertex_num, sizeof(int));
    if (!dom) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    dfs(graph, dom, 0);

    for (int i = 1; i < graph->vertex_num; ++i) {
        if (dom[i]) {
            printf("(%d#%d)", i, i);
            for (int j = 0; j < graph->vertex_num; ++j) {
                if (i != j && dom[j]) {
                    printf("(%d#%d)", i, j);
                }
            }
        }
    }

    free(dom);
}

int main() {
    int vertex_num, edge_num;
    scanf("%d,%d", &vertex_num, &edge_num);

    GraphStruct *graph = createGraph(vertex_num, edge_num);

    for (int i = 0; i < edge_num; ++i) {
        int v, w, weight;
        scanf("%d,%d,%d", &v, &w, &weight);
        addEdge(graph, v, w, weight);
    }

    computeDomination(graph);

    destroyGraph(graph);

    return 0;
}

