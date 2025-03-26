#include <stdio.h>
int OPER = 0;
void printHailstone(int n){
    printf("%d ", n);
    if (n == 1){return;}
    OPER += 1;
    if (n&1){
        printHailstone(3*n + 1);
    }else{
        printHailstone(n/2);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    OPER = 0;
    printHailstone(n);
    printf("\n%d\n", OPER);
    return 0;
}