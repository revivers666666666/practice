typedef struct Node{
    DataType data;
    struct Node *LChild;
    struct Node *RChild;
}BiTNode ,*BiTree;

typedef struct node{
    int data;
    struct node *firstchild, *nextsibling;
}Tnode, *Ptree;

void layer(cstree root,queue *Q){
    cstree p;
    p = root;
    if(p = NULL) return ;
    push(Q,p);
    while(!queue_empty(Q)){
        queue_out(Q,P);
        visit(p);
        if(p -> first != NULL){
            queue_in(Q,p->first);
        }
        if(p -> silbling != NULL){
            Queue_in(Q, p->silbling);
        }
    }
}