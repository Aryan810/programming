#include <stdio.h>
#include <stdlib.h>

void reverse(int f, int l, int * arr){
    if (f >= l){
        return;
    }
    int temp = arr[f];
    arr[f] = arr[l];
    arr[l] = temp;
    reverse(f+1, l-1, arr);
}

int main(){
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int)*n);

    for (int i=0;i<n;i++){
        scanf("%d", arr+i);
    }

    reverse(0, n-1, arr);

    for (int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }printf("\n");

    free(arr);
}