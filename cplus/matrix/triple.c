#define MAXSIZE 100

typedef struct{
    int row,col;
    int e;
}Triple;
typedef struct{
    Triple data[MAXSIZE];
    int m , n ,len;
}TSMatrix;

void Tranmatrix(TSMatrix A,TSMatrix *B){
    int col,t,p,q;
    int num[MAXSIZE] ,position[MAXSIZE];
    B ->len = A.len;B -> m = A.n; B -> n = A.m;
    for(int i = 0 ;i < A.len ; i++){
        num[i] = 0;
    }
    for(int i = 0; i <= A.len;i++){
        num[A.data[i].col]++;      
    }
    position[0] = 0;
    for(int j = 1 ; j <= A.n;j++){
        position[j] = position[j - 1]+ num[j - 1];  
    }
    for(int k = 0; k<= A.len;k++){
        col = A.data[k].col;
        q = position[col];
        (B -> data[q]).row = A.data[k].col;
        B -> data[q] . col = A.data[k].row;
        B -> data[q].e = A.data[k].e;
        position[col]++;
    }
}