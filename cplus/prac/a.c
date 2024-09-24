#include <stdio.h>  
#include <stdlib.h>  

typedef struct {  
    int vertex_num;  
    int edge_num;  
    int **edges;  
} GraphStruct;  

int visited[100] = {0};

int DFS(GraphStruct *G, int v0, int pre) {
    visited[v0] = 1;
    for (int vj = 0; vj < G->vertex_num; vj++) {
        if (G->edges[v0][vj] != 0) {
            if (vj != pre && visited[vj]) { 
                return 1;
            }
            if (!visited[vj]) {
                if (DFS(G, vj, v0)) {
                    return 1; 
                }
            }
        }
    }
    return 0; 
}

int ExamineCircle(GraphStruct *G) {
    for (int i = 0; i < G->vertex_num; i++) {
        for (int j = 0; j < G->vertex_num; j++) {
            visited[j] = 0;
        }
        if (!visited[i]) {
            if (DFS(G, i, -1)) {
                return 1; 
            }
        }
    }
    return 0; 
}

int main(void) {  
    int vn, en, x, y, weight;  
    GraphStruct *G = (GraphStruct *)malloc(sizeof(GraphStruct));  
      
    scanf("%d %d", &vn, &en);  
    G->vertex_num = vn;  
    G->edge_num = en;  
  
    G->edges = (int **)malloc(vn * sizeof(int*));  
    for (int i = 0; i < vn; i++) {  
        G->edges[i] = (int *)malloc(vn * sizeof(int));  
    }

    for (int i = 0; i < G->vertex_num; i++) {  
        for (int j = 0; j < G->vertex_num; j++) {  
            G->edges[i][j] = 0;  
        }  
    }  

    for (int i = 0; i < en; i++) {  
        scanf("%d %d %d", &x, &y, &weight);  
        G->edges[x][y] = weight; 
        G->edges[y][x] = G ->edges[x][y]; 
    }  

    if (ExamineCircle(G)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    for (int i = 0; i < vn; i++) {  
        free(G->edges[i]);  
    }  
    free(G->edges);  
    free(G);  
  
    return 0;  
}
