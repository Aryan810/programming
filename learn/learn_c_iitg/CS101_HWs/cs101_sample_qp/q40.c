#include <stdio.h>

int main(){
    void func();
    void (*ptr)();

    ptr = func;

    (*ptr)();
    ptr();
    return 0;
}

void func(){
    printf("Hello ");
}