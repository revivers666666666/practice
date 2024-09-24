#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node * next;
}Node;

typedef struct{
    Node * front;
    Node * rear;
}Queue;

int InitQueue(Queue *Q){
    Q -> front = (Node *)malloc(sizeof(Node));
    if(Q -> front != NULL){
        Q ->rear = Q ->front;
        Q ->front-> next = NULL;
        return 1;
    }else{
        return -1;
    }

}

int EnterQueue(Queue *Q,int x){
    Node *S;
    S = (Node *)malloc(sizeof(Node));
    if(S != NULL){
    S -> data = x;
    S -> next = NULL;
    Q -> rear -> next = S;
    Q -> rear = S;
    return 1;
    }else return -1;
}

int DeleteQueue(Queue *Q,int *x){
    Node *S;
    if(Q -> front = Q -> rear){
        return -1;
    }
    S =  Q ->front ->next;
    Q -> front -> next = S -> next;
    *x = S -> data;
    if(Q -> rear == S){
        Q ->rear = Q -> front;
    }// 1 非出队后为空情况下rear不受影响
    free(S);
    return 1;
}//从一般到特殊

