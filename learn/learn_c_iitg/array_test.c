#include <stdio.h>

void func(int arr[]){
    printf("%d\n", (int)sizeof(arr));
    int temp = arr[3];
    arr[3] = arr[0];
    arr[0] = temp;
}

int main(){
    int arr[4] = {1, 2, 3, 4};
    func(arr);
    for (int i=0;i<4;i++){
        printf("%d ", arr[i]);
    }printf("\n");

}