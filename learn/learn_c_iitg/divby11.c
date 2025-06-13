#include <stdio.h>
#include <math.h>

int abs(int n){
    if (n >= 0){return n;}
    else{return (-1*n);}
}

int main(){
    int n;
    scanf("%d", &n);
    int even = 0;
    int odd = 0;

    int x = n;
    int e = 0;
    while (x > 0){
        int y = x%10;
        if (e){even += y;e = 0;}else{
            odd += y;e = 1;
        }
        x /= 10;
    }

    if (abs(even - odd)%11 == 0){
        printf("YES\n");
    }else{printf("NO\n");}
    
    return 0;
}