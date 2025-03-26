#include <stdio.h>

int add(int a, int b){
    return (a+b);
}

int main(){
    int (*ptr)(int, int);
    ptr = &add;
    int k = (*add)(3, 4);
    int l = (add)(3, 4);
    int m = add(3, 4);
    printf("%d\n", k);
    printf("%d\n", l);
    printf("%d\n", m);
    return 0;
}