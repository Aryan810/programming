#include <stdio.h>
#include <string.h>

union Data {
    int i;
    float f;
    };
    

int main(){
    union Data d;
    d.i = 5;
    d.f = 2.5;
    printf("%f\n", d.f);
    printf("%d\n", d.i);
    return 0;
}