#include<stdio.h>
#include<stdlib.h>
#define Stack_Size 50

typedef struct{
    int elem[Stack_Size];
    int top;
}SeqStack;

void InitStack(SeqStack *S){
    S -> top = -1;
}
int isEmpty(SeqStack *S){
    if(S ->top == -1){
        return 1;
    }else[
        return 0;
    ]
}

int Push(SeqStack *S, int x){
    if(S -> top = Stack_Size - 1){
        return(-1);
    }
    S -> top++;
    S -> elem[S ->top] = x;
    return(1); 
}

int Pop(SeqStack *S , int* x){
    if(S -> top =  -1){
        return -1 ;
    }
    *x = S -> elem[S -> top];
    S -> top--;
    return 1; 
}

int GetTop(SeqStack *S ,int *x){
    if(S -> top = -1){
        return(0);
    }else{
        *x = S -> elem[S -> top];
        return 1;
    }
}

typedef struct Node{
    int Data;
    struct Node *LChild;
    struct Node *RChild;
}BiTNode,*BiTree;

int depth;
void PreOrder(BiTree root){
    if(root != NULL){
        visit(root -> Data);
        PreOrder(root ->LChild);
        PreOrder(root ->RChild);
    }
}

void InOrder(BiTree root){
    if(root != NULL){
        PreOrder(root ->LChild);
        visit(root -> Data);
        PreOrder(root ->RChild);
    }
}

void PostOrder(BiTree root){
    if(root != NULL){
        PreOrder(root ->LChild);
        PreOrder(root ->RChild);
        visit(root -> Data);
    }
}

void CreateBiTree(BiTree *bt){
    char ch;
    ch = getchar();
    if(ch == '.'){
        *bt = NULL;
    }else{
        bt = (BiTNode*)malloc(sizeof(BiTNode));
        (*bt) ->Data = ch;  
        CreateBiTree(&(*bt) -> LChild);
        CreateBiTree(&(*bt) -> RChild);
    }
}

int Post(BiTree bt){
    int hl,hr,max;
    if(bt != NULL){
        hl = Post(bt -> LChild);
        hr = Post(bt -> RChild);
        max = hl >hr?hl:hr;
        return(max+1);
    }
    else return 0;
}

void PreTreeDepth(BiTree bt,int h){
    if(bt != NULL){
        if(h>depth){
            depth = h;
            PreTreeDepth(bt ->LChild,h+1);
            PreTreeDepth(bt ->RChild,h+1);
        }
    }
}

#define MAXSIZE 1000
void LevelOrder(BiTree bt){
    BiTree Queue[MAXSIZE];
    int front ,rear;
    if(bt ==NULL){
        return ;
    }
    front = 0;
    rear = 0;
    Queue[rear] = bt;
    rear++;
    while(rear != front){
        visit(Queue[front++] -> Data);
        if(Queue[front]->LChild!=NULL){
            Queue[rear] = Queue[front]->LChild;
            rear++;
        }
        if(Queue[front]->LChild!=NULL){
            Queue[rear] = Queue[front]->LChild;
            rear++;
        }
    }
}

void PreONS(BiTree t){
    BiTree p,q;
    SeqStack *st;

    p = t;
    while(p != NULL || StackEmpty(st)){
        while( p != NULL){
            Push(st,p);
            p = p -> LChild;
        }
        if(!isEmpty(st)){
            Gettop(st,p);
            if(p ->RChild == q|| p->LChild == q){
                printf("%c",p ->Data);
                q = p;
                Pop(st,p);
                p = NULL;
            }
        }else{
            p = p ->RChild;
        }
    }
}