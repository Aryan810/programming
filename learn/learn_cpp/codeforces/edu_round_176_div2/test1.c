#include <stdio.h>

int main(){
    char * ptr = "GarbageValue";
    printf("%c\n", *&*&*ptr);
    return 0;
}