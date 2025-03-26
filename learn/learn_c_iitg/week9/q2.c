#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int r, c, v;
    struct Node * next;
};

int main(){

    // first matrix
    int a1, b1;
    scanf("%d %d", &a1, &b1);
    struct Node n1;
    struct Node * curr = &n1;
    int q;
    scanf("%d", &q);
    for (int i=0;i<q;i++){
        int r, c, v;
        scanf("%d %d %d", &r, &c, &v);
        curr->r = r;
        curr->c = c;
        curr->v = v;
        if (i == q-1){
            curr->next = NULL;
        }
        curr->next = (struct Node *)malloc(sizeof(struct Node));
        curr = curr->next;
    }

    // second matrix
    int a2, b2;
    scanf("%d %d", &a2, &b2);
    struct Node n2;
    curr = &n2;
    scanf("%d", &q);
    for (int i=0;i<q;i++){
        int r, c, v;
        scanf("%d %d %d", &r, &c, &v);
        curr->r = r;
        curr->c = c;
        curr->v = v;
        if (i == q-1){
            curr->next = NULL;
        }
        curr->next = (struct Node *)malloc(sizeof(struct Node));
        curr = curr->next;
    }

    if (!(a1 == a2 && b1 == b2)){
        printf("-999\n");
        return 0;
    }

    // for storing ans;
    struct Node ans;
    curr = &ans;
    for (int i=0;i<a1;i++){
        for (int j=0;j<b1;j++){
            // find this in first
            int v1 = 0;
            struct Node * ptr = &n1;
            while (ptr != NULL){
                if (ptr->r == i && ptr->c == j){
                    v1 = ptr->v;
                    break;
                }
                ptr = ptr->next;
            }

            int v2 = 0;
            ptr = &n2;
            while (ptr != NULL){
                if (ptr->r == i && ptr->c == j){
                    v2 = ptr->v;
                    break;
                }
                ptr = ptr->next;
            }
            
            if (v1+v2 != 0){
                curr->r = i;
                curr->c = j;
                curr->v = v1+v2;
                curr->next = (struct Node *)malloc(sizeof(struct Node));
                curr = curr->next;
                curr->next = NULL;
            }
        }
    }

    //printing ans.
    struct Node * ptr = &ans;
    while (ptr->next != NULL){
        printf("%d %d %d\n", ptr->r, ptr->c, ptr->v);
        ptr = ptr->next;
    }

    // freeing all
    // ptr = &n1;
    // while (ptr->next != NULL){
    //     struct Node * temp = ptr;
    //     free(temp);
    //     ptr = ptr->next;

    // }

    // ptr = &n2;
    // while (ptr->next != NULL){
    //     struct Node * temp = ptr;
    //     free(temp);
    //     ptr = ptr->next;
    // }

    // ptr = &ans;
    // while (ptr->next->next != NULL){
    //     struct Node * temp = ptr;
    //     ptr = ptr->next;
    //     free(temp);
    // }
    
    return 0;
}