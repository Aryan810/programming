#include <stdio.h>

int foo(int i){
    return i++;
}

int main() {
    int i = 2;
    printf("%d\n", foo(i++) + i + ++i);
    return 0;
}