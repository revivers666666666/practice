#include <stdio.h>
#include <stdlib.h>

typedef unsigned int Vertex;

// 图的数据结构
typedef struct GraphStruct {
    int vertex_num;
    int edge_num;
    int **edges;
} GraphStruct;

typedef struct GraphStruct *Graph;

// 边的数据结构
typedef struct {
    Vertex v;
    Vertex w;
    int weight;
} Edge;

// 初始化图
Graph initGraph(int vertex_num, int edge_num) {
    Graph G = (Graph)malloc(sizeof(GraphStruct));
    G->vertex_num = vertex_num;
    G->edge_num = edge_num;
    
    G->edges = (int **)malloc(vertex_num * sizeof(int *));
    for (int i = 0; i < vertex_num; i++) {
        G->edges[i] = (int *)calloc(vertex_num, sizeof(int)); // 初始化为 0
    }
    
    return G;
}

// 释放图的内存
void freeGraph(Graph G) {
    for (int i = 0; i < G->vertex_num; i++) {
        free(G->edges[i]);
    }
    free(G->edges);
    free(G);
}

// 读取图的边信息
void readEdges(Graph G) {
    int x, y, z;
    for (int i = 0; i < G->edge_num; i++) {
        scanf("%d,%d,%d", &x, &y, &z);
        G->edges[x][y] = z; // 存储边的权重
    }
}

void findDominators(Graph G) {
    int n = G->vertex_num;
    
    // 输出支配关系
    printf("Dominance relationship:\n");
    for (int i = 0; i < n; i++) {
        if (i == 0) { // 入口结点支配所有结点，不输出该信息
            continue;
        }
        for (int j = 0; j < n; j++) {
            if (G->edges[0][j] && G->edges[i][j]) {
                printf("(%d#%d) ", i, j);
            }
        }
    }
    printf("\n");
}

int main(void) {
    int vertex_num, edge_num;
    scanf("%d,%d", &vertex_num, &edge_num);
    
    Graph G = initGraph(vertex_num, edge_num);
    readEdges(G);
    findDominators(G);
    
    freeGraph(G);

    return 0;
}

