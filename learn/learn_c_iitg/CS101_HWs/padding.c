#include <stdio.h>

struct Name{
   char a;
   char b;
   char b1;
   char b2;
   char b3;
   int c;
};

int main(){
    struct Name ar;
    printf("%d\n", sizeof(ar));
    return 0;
}