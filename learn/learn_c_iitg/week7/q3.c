#include <stdio.h>

void swap(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void waveSort(int * arr, int n){
    for (int i=0;i<n;i++){
        if (i&1){
            int mn=arr[i], k=i;
            for (int j=i;j<n;j++){
                if (arr[j] < mn){
                    mn = arr[j];
                    k = j;
                }
            }
            if (mn < arr[i]){
                swap(arr+i, arr+k);
            }
        }else{
            int mx=arr[i], k=i;
            for (int j=i;j<n;j++){
                if (arr[j] > mx){
                    mx = arr[j];
                    k = j;
                }
            }
            if (mx > arr[i]){
                swap(arr+i, arr+k);
            }
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i=0;i<n;i++){
        scanf("%d", arr+i);
    }

    waveSort(arr, n);
    for (int i=0;i<n;i++){
        printf("%d ", *(arr+i));
    }
    printf("\n");

    return 0;
}
