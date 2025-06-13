#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int y = n;
    int x = 0;
    while (y > 0){
        int p = y%10;
        x = x*10 + p;
        y /= 10;
    }
    int Aryan = 0;
    printf("%s pallindrome\n", (x != n)?"NOT a":"It is a");
    return 0;
}