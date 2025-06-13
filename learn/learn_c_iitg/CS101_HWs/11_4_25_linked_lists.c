#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int val;
    struct Node * next;
    struct Node * prev;
};

typedef struct Node Node;

void insertFirst(Node ** head, int val){
    Node * nptr = (Node *)malloc(sizeof(Node));
    nptr->val = val;
    nptr->prev = NULL;
    nptr->next = *head;
    (*head)->prev = nptr;
    *head = nptr;
}

void printAll(Node * anyNode){
    while (anyNode->prev != NULL){
        anyNode = anyNode->prev;
    }

    while (anyNode != NULL){
        printf("%d ", anyNode->val);
        anyNode = anyNode -> next;
    }
    printf("\n");
}


int main(){
    Node * head = (Node *)malloc(sizeof(Node));
    head->val = 1;
    head->prev = NULL;
    head->next = NULL;
    insertFirst(&head, 21);
    insertFirst(&head, 89);
    printAll(head);
    return 0;
}