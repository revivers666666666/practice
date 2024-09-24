#include <stdio.h>
#define Maxsize 10
typedef struct queue{
    int data[Maxsize];
    int front,rear;
}SqQueue;

void InitQueue(SqQueue *Q){
    Q -> rear = 0;
    Q -> front = 0;
}

int IsEmpty(SqQueue *Q){
    if(Q -> rear == Q -> front){
        return 1;
    }else{
        return 0;
    }
}

int IsFull(SqQueue *Q){
    if((Q -> rear + 1) % Maxsize ==  Q -> front){
    return 1;
    }else{
        return 0;
    }
}

int EnterQueue(SqQueue *Q,int x){
    if(Isfull(Q)){
        return -1;
    }
    Q -> data[Q -> rear] = x;
    Q -> rear++;
    Q -> rear = Q -> rear % Maxsize;
    return 1;
}

int DeleteQueue(SqQueue *Q,int *x){
    if(IsEmpty(Q)){
        return -1;
    }
    *x = Q -> front;
    Q -> front = (Q -> front +1) %  Maxsize;
}