struct ListNode* oddEvenList(struct ListNode* head) {
    struct ListNode *p,*l,*r,*pre;
    struct ListNode *q;
    p = (struct ListNode *)malloc(sizeof(struct ListNode));
    q = p;
    p -> next = NULL;
    r = head -> next;
    l = r -> next;
    while(r != NULL && l != NULL){
        pre = l;
        r -> next = l -> next;
        p -> next = l;
        r = r -> next;
        p = p -> next;
        l = l -> next;
    }
    if(r != NULL){
        r -> next = q -> next;
    }else{
        pre -> next = q -> next;
    }
    free(q);
    return head;
}