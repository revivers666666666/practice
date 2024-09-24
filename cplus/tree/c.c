while(!Stackempty(st) || p!=NULL){
    while(p!=NULL){
        printf("%d",p->data);
        Push(st,p);
        p = p->LChild;
    }
    if(!isEmpty(st)){
        Pop(st,p);
        p = p->RChild;
    }
}

while(!Stackempty(st) || p !=NULL){
    while(p!=NULL){
        Push(st,p);
        p = p->LChild;
    }
    if(!isEmpty(st)){
        Pop(st,p);
        printf("%d",p ->data);
            p = p -> RChild;
    }
}

while(!StackEmpty(st)|| p != NULL){
    while(p != NULL){
        Push(st,p);
        p = p->LChild;
    }
    if(!isStack(st)){
        GetTop(st,p);
        if(p ->RChild == NULL || p->RChild == q){
            printf("%d",&c);
            q = p;
            Pop(st,p);
            p = NULL;
        }else{
            p = p ->RChild;
        }
    }
}