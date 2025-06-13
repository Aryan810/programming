#include <stdio.h>
#include <stdlib.h>

struct Node{
    int val;
    struct Node * next;
};

typedef struct Node Node;

int main(){
    Node * head;
    int n;
    scanf("%d", &n);
    Node * temp = head;
    for (int i=0;i<n;i++){
        int x;
        scanf("%d", &x);
        temp = (Node *)malloc(sizeof(Node));
        temp->val = x;
        temp->next = 
    }
    return 0;
}