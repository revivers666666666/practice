#include<stdio.h>
#include<stdlib.h>
#define Stack_Size 50

typedef struct{
    int elem[Stack_Size];
    int top;
}SeqStack;

void InitStack(SeqStack *S){
    S -> top = 1;
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

