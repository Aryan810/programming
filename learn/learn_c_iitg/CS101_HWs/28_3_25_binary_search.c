#include <stdio.h>

int binsearch(int * a, int n, int x){
    int f = 0;
    int r = n;
    while (f < r){
        int mid = (f + r)/2; // as we get lower number when r-f = 1 and we find mid, that is why we are using (f < r) for condition here.
        if (a[mid] == x){return mid;}
        else if (a[mid] > x){r = mid;}
        else{
            f = mid + 1;
        }
    }
    return -1;
}

int main(){
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i=0;i<n;i++){
        scanf("%d", arr+i);
    }
    int x;
    scanf("%d", &x);

    printf("%d\n", binsearch(arr, n, x));
    return 0;
}