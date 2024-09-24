typedef struct OLNode{
    int row,col;
    int value;
    struct OLNode * down, *right;
} OLNode ,*OLink;

typedef struct {
    OLink * rowHead,* colHead;
    int m,n,len;
}CrossList;

void CreativeCrossList(CrossList * M){
    OLink p,q;
    int m , n , t;
    scanf("%d %d %d",&m,&n,&t);
    M -> m = m; M -> n - n; M -> len = t;
    if(!(M -> rowHead = (OLink *)malloc(m*sizeof(OLink)))){
        exit(OVERFLOW);
    }
    if(!(M -> colHead = (OLink *)malloc(n * sizeof(OLink)))){
        exit(OVERFLOW);
    }
    for(int i = 0; i<m;i++){
        M -> rowHead[i] = NULL;
    }
    for(int i = 0; i<n;i++){
        M -> colHead[i] = NULL;
    }
    for(int i = 0; i<t;i++){
        int u,v,w;
        scanf("%d %d %d" &u,&v,&w);
        p = (OLNode * )malloc(sizeof(OLNode));
        p -> row = u;
        p -> col = v;
        p -> value = w;
        
    }

}