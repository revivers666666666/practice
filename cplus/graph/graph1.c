
int visited[100];


void DFS1(graph G){
    int vi;
    for(vi = 0;vi < g.maxnum;vi++){
        visited[vi] = 0;
    }
    for(vi = 0; vi< h.vexnum;vi++){
        if(!visited[vi]){
            DFS(G,vi);
        }
    }
}
void DFS(Graph g, int v0){
    visit(v0);
    visited[v0] = 1;
    int w = FAV(g,v0);
    while(w != -1){
        if(!visited[w]){
            DFS(g,w);
        }
        w = NFS(g,v0,w);
    }


void BFS(Graph g, int v0){
    visit(v0);
    visited[v0] = 1;
    InitQueue(&Q);
    EnterQueue(&Q,v0);
    while(!Empty(Q)){
        dequeue(Q,v0);
        w = fad(Q,v0);
        while(w!= -1){
            if(!visited[w]){
                visited(w);
                visited[w] = t;
                enterqueue(&Q,w);
            }
            w = adj(g,v,w);
        }
    }
}