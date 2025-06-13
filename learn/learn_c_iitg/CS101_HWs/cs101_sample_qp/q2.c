#include <stdio.h>

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int a = 2;
    void *ptr = (int *)(&a);
    printf("%d\n", *((int *)ptr));
    return 0;
}