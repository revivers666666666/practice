#include <stdio.h>
#define MAXLEN 40
typedef struct {
    char ch[MAXLEN];
    int len;
}SString;

int StrInsert(SString *s , int pos ,SString t){
    int i;
    if(pos < 0 || pos > s -> len){
        return -1;
    }
    if(t.len + s -> len <= MAXLEN){
        for(int i = t .len + s -> len - 1; i >= pos + t.len ; i--){
            s -> ch[i] = s -> ch[i - (t.len)];
                }
        for(int j = t.len-1; j >= 0;j--){
            s -> ch[j + pos] = t.ch[j];
        }
        s -> len = t.len + s -> len;
    }else if(pos + t.len <= MAXLEN){
        for(int i = MAXLEN -1 ; i > pos + t.len - 1;i--){
            s ->ch[i] = s -> ch[i - t.len];
        }
        for(int j = 0; j < t.len ; j++){
            s -> ch[pos + i] = t.ch[i];
        }
        s -> len = MAXLEN;
    }else if(pos + t.len > MAXLEN){
        for(int i = 0 ; i < MAXLEN - pos; i++){
           s->ch[i+pos] = t .ch[i];
        }
        s -> len = MAXLEN;
    }
    return 1;
}

int StrDelete(SString *s,int pos,int len){
    if(pos + len > s -> len || pos < 0){
        return -1;
    }else{
        for(int i = pos + len; i < s -> len ; i++){
             s -> ch[i - len]  = s -> ch[i];
             s -> len = s -> len - len;
        }
    }    
}

int SrcCompare(SString s,SString t){
    int i;
    for(int i = 0 ; i < t.len && i < s.len ; i++){
        if(s.ch[i] != t.ch[i]){
            return(s.ch[i] - t.ch[i]);
        }
    }
    return(t.len - s.len);
}