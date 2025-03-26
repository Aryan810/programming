#include <stdio.h>

void reverse(int arr[], int i, int n){
    if (i >= n/2){
        return;
    }
    int temp = arr[i];
    arr[i] = arr[n-1-i];
    arr[n-1-i] = temp;
    reverse(arr, i+1, n);
}

int main(){
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i=0;i<n;i++){
        scanf("%d", arr+i);
    }
    reverse(arr, 0, n);
    for (int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}