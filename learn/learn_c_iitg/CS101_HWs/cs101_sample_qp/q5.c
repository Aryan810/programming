#include <stdio.h>

int mult(int a, int b){
    int m = a*b;
    return  (m, a ,b);
}

int main(){
    int a = 24;
    int b = 2;
    int p = mult(a, b);
    printf("%d\n", p);
    return 0;
}