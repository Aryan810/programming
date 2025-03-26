#include <stdio.h>

int main(){
    int a[2][2] = {1, 2, 3, 4};
    int x = *(*a + 3);
    printf("%d\n", x);
    return 0;
}