#include<stdio.h>
#include<stdlib.h>

int visited[100] = {0};
typedef struct GraphStruct{
    int   vertex_num;
    int   edge_num;
    int **edges;
}GraphStruct;
typedef struct GraphStruct *Graph;
typedef unsigned int Vertex;

Graph readGraph(){
    int vertex_num,edge_num,c,x,y,z;
    scanf("%d %d",&vertex_num,&edge_num);
    Graph G = (Graph) malloc (sizeof(GraphStruct));
    (G -> edges) = (int **)malloc(vertex_num * sizeof(int));
    for(int i = 0 ; i < vertex_num; i++){
        G -> edges[i] = (int *)malloc(vertex_num * sizeof(int));
        for(int j = 0; j < vertex_num;j++){
            G -> edges[i][j] = 0; 
        }
    }
    for(int i = 0; i < edge_num ; i++){
        scanf("%d %d %d",&x,&y,&z);
        G -> edges[x][y] = 1;
    }
    return G;
}

typedef struct Node{
    int data;
    struct Node *next;
}LinkQueueNode;

typedef struct{
    LinkQueueNode *front;
    LinkQueueNode *rear;
}Queue;

int FirstAdjVertex(Graph G,int v){
    for(int i = 0; i < G ->vertex_num;i++){
        if(G -> edges[v][i] && !visited[i]){
            return i;
        }
    }
    return -1;
}

int SecondAdjVertex(Graph G,int v,int w){
    for(int i = 0; i < G -> vertex_num; i++){
        if(G ->edges[v][i] && !visited[i] && v != w){
            return i;
        }
    }
    return -1;
} 

void InitQueue(Queue *Q){
    Q -> front = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if(Q -> front != NULL){
        Q -> rear = Q -> front;
        Q -> front -> next = NULL;
    }
}

int EnterQueue(Queue *Q,int x){
    LinkQueueNode *new;
    new = (int *)malloc(sizeof(LinkQueueNode));
    if(new != NULL){
        new -> data = x;
        new -> next = NULL;
        Q ->rear->next = new;
        Q ->rear = new;
        return(1);
    }
    return(0);
}

int DeleteQueue(Queue *Q,int *x){
    LinkQueueNode *p;
    if(Q->front == Q->rear){
        return 0;
    }
    p = Q -> front -> next;
    Q -> front  = p ->next;
    if(Q -> rear = p){
        Q ->rear = Q ->front;
    }
        *x = p -> data;
        free(p);
        return 1;
}

int Empty(Queue *Q){
    if(Q ->rear == Q ->front){
        return 1;
    }else{
        return 0;
    }
}

void BFS(Graph G,int v0){
    visited[v0] = 1;
    Queue *Q;
    int v,w;
    InitQueue(Q);
    EnterQueue(Q,v0);
    while(!Empty(Q)){
        DeleteQueue(Q,&v);
        w = FirstAdjVertex(G,v);
        while(w != -1){
            if(!visited[w]){
                visited[w] = 1;
                EnterQueue(Q,w);               
            }
        }
        w = SecondAdjVertex(G,v,w);
    }
}

void findDominators(Graph g) {
    int n = g->vertex_num;
    int **dom = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        dom[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            dom[i][j] = 1; 
        }
    }
    dom[0][0] = 1;
}

int main(void){
    Graph G = readGraph();

}