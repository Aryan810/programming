#include <stdio.h>
#include <stdlib.h>

struct Node{
    int digit;
    struct Node * next;
};

typedef struct Node Node;

Node * addll(Node * num1, Node * num2){
    Node * sum = (Node *)malloc(sizeof(Node));
    Node * iter = sum;
    int carry = 0;
    while (num1 != NULL || (num2 != NULL || carry > 0)){
        int sm = ((num1 == NULL)?0:num1->digit) + ((num2 == NULL)?0:num2->digit) + carry;
        if (num1 != NULL){num1 = num1->next;}
        if (num2 != NULL){num2 = num2->next;}
        iter->digit = sm%10;
        iter->next = NULL;
        carry = sm/10;
        if (!(num1 == NULL && (num2 == NULL && carry == 0))){
            iter->next = (Node *)malloc(sizeof(Node));
            iter = iter->next;
        }
    }
    return sum;
}

int main(){
    // first take input
    int a;
    scanf("%d", &a);
    Node * num1 = (Node *)malloc(sizeof(Node));
    Node * last = num1;
    num1->next = NULL;
    for (int i=0;i<a;i++){
        int x;
        scanf("%d", &x);
        last->digit = x;
        if (i != a-1){
            last->next = (Node *)malloc(sizeof(Node));
            last = last->next;
            last->next = NULL;
        }
    }

    int k;
    scanf("%d", &k);
    Node * tmp = num1;
    while (tmp->next != NULL){
        tmp = tmp -> next;
    }
    tmp->next = num1; // making circular linked list.
    
    for (int i=0;i<k;i++){
        Node * temp = num1->next;
        int last = num1->digit;
        for (int j=0;j<a;j++){
            int x = last;
            last = temp->digit;
            temp->digit = x;
            temp = temp->next;
        }
    }
    tmp = num1;
    for (int i=0;i<a;i++){
        printf("%d ", tmp->digit);
        Node * last = tmp;
        tmp = tmp->next;
        free(last);
    }

    printf("\n");

    return 0;
}