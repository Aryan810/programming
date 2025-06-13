#include <stdio.h>
#include <stdlib.h>

void main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[m];
    for (int i=0;i<m;i++){
        scanf("%d", arr+i);
    }

    int curr = 1;
    for (int i=0;i<m;i++){
        while (arr[i] != curr){
            printf("Push Pop ");
            curr += 1;
        }
        printf("Push ");
        curr += 1;
    }
    printf("\n");
}