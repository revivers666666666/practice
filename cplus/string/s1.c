#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int Data;
    struct Node* next;
} *Linklist, Node;

int create(Linklist* L) {
    *L = (Node *)malloc(sizeof(Node));
    if (*L == NULL) {
        return -1;
    }
    (*L)->next = NULL;
    return 0;
}

int IsEmpty(Linklist L) {
    return L->next == NULL;
}

Node* Find(int X, Linklist L) {
    Node *p = L->next;
    while (p != NULL && p->Data != X) {
        p = p->next;
    }
    return p;
}

Node* FindPrevious(int X, Linklist L) {
    Node *p = L;
    while (p->next != NULL && p->next->Data != X) {
        p = p->next;
    }
    return p;
}

void Delete(int X, Linklist L) {
    Node *prev, *temp;
    prev = FindPrevious(X, L);
    while(prev -> next != NULL){
        temp = prev -> next;
        prev -> next = temp -> next;
        free(temp);
        prev = FindPrevious(X,L);
    }//线性结构一般不要使用递归调用
}

void printList(Linklist L) {
    Node *p = L->next;
    while (p != NULL) {
        printf("%d ", p->Data);
        p = p->next;
    }
    printf("\n");
}

void Insert(Linklist L) {
    Node *p, *q = L;
    int x;
    
    while (scanf("%d", &x) && x <= 10) {
        p = (Node*)malloc(sizeof(Node));
        if (p == NULL) {
            printf("内存分配失败。\n");
            return;
        }
        p->Data = x;
        p->next = NULL;
        q->next = p;
        q = p;  // 将 q 移动到新插入的节点
    }
}

int main(void) {
    Linklist L;
    int x;

    if (create(&L) != 0) {
        printf("创建链表失败。\n");
        return -1;
    }

    printf("输入要插入的数字（<= 10），以及要删除的整数：\n");
    Insert(L);
    
    printList(L);

    printf("输入要删除的数字：");
    scanf("%d", &x);
    Delete(x, L);

    printf("删除后的链表：\n");
    printList(L);

    return 0;
}


