#include <stdio.h>

void enqueue(int val, int * h, int * t, int * arr, int * sz, int mx){
    if (*sz >= mx){
        printf("QUEUE IF FULL !");
    }
    arr[((*t+1)%mx)] = val;
    *t = (*t+1)%mx;
    (*sz) += 1;
}

void dequeue(int * h, int * t, int * arr, int * sz, int mx){
    if (*sz == 0){
        printf("QUEUE IS EMPTY !");
    }
    *h = (*h + 1)%mx;
    (*sz) -= 1;
}

void printarr(int * arr, int h, int t){
    for (int i=(h+1);i<=t;i++){
        printf("%d ", arr[i]);
    }printf("\n");
}

int main(){
    int arr[12];
    int mx = 12;
    int sz = 0;
    int h = -1;
    int t = -1;
    enqueue(32, &h, &t, arr, &sz, mx);
    enqueue(33, &h, &t, arr, &sz, mx);
    enqueue(34, &h, &t, arr, &sz, mx);
    printarr(arr, h, t);
    dequeue(&h, &t, arr, &sz, mx);
    printarr(arr, h, t);
    enqueue(99, &h, &t, arr, &sz, mx);
    printarr(arr, h, t);
    dequeue(&h, &t, arr, &sz, mx);
    dequeue(&h, &t, arr, &sz, mx);
    printarr(arr, h, t);
    return 0;
}