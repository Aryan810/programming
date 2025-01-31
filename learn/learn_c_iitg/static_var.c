#include<stdio.h>

void show(){
    static int c = 1;
    c += 10;
    printf("%d\n", c);
}

int main(){
    show();
    show();
    show();
    show();
}