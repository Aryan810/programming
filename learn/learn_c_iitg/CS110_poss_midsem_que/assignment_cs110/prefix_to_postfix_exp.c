#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char * val;
    struct Node * next;
};
typedef struct Node Node;

void pop(Node ** st){
    Node * temp = *st;
    if (*st != NULL){
        *st = (*st)->next;
    }
    free(temp);
}

void push(Node ** st, char * newe){
    Node * newpt = (Node *)malloc(sizeof(Node));
    newpt->val = newe;
    newpt->next = *st;
    *st = newpt;
}

int main(){
    char * pre = (char *)malloc(sizeof(char)*100);
    scanf("%s", pre);

    Node * st = NULL;
    int n = strlen(pre);
    for (int i=n-1;i>=0;i--){
        if (!(pre[i]-'A' >= 0 && pre[i]-'A' < 26)){
            int j = 0;
            char * f = st->val;
            char * s = st->next->val;
            char * temp = (char *)malloc(sizeof(char)*(strlen(f)+strlen(s)+2));
            temp[strlen(f)+strlen(s)+1] = 0;
            for (int i=0;i<strlen(f);i++){
                temp[j] = f[i];
                j += 1;
            }
            for (int i=0;i<strlen(s);i++){
                temp[j] = s[i];
                j += 1;
            }
            temp[j] = pre[i];
            pop(&st);pop(&st);push(&st, temp);
        }else{
            char * x = (char *)malloc(sizeof(char)*2);
            x[0] = pre[i];
            x[1] = 0;
            push(&st, x);
        }
    }
    printf("Postfix expression: %s\n", st->val);
    if (st != NULL){free(st);}
    return 0;
}