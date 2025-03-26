#include <stdio.h>
#include <stdlib.h>

struct Data
{
    int a;
    char c;
    float f;
};

int main(){
    printf("%lu\n", sizeof(struct Data));
    return 0;
}
