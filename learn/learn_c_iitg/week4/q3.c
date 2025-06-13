#include <stdio.h>

int max(int a, int b){
    if (a > b){return a;}else{
        return b;
    }
}

int main(){
    int a, b, c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    // check if valid triangle ?
    if (!(a+b > c && (b+c > a && a+c > b))){
        printf("Not a valid triangle\n");
        return 0;
    }
    int mx = max(a, max(b, c));
    if (a == b && b == c){
        printf("Equilateral\n");
    }else{
        if (a == b || (b == c || c == a)){
        printf("Isosceles\n");
        }else{
            printf("Scalene\n");
        }
        int s1, s2;
        if (a == mx){
            s1 = b;s2 = c;
        }else if (b == mx){
            s1 = a;s2 = c;
        }else if (c == mx){
            s1 = a;s2 = b;
        }
        if (mx*mx == (s1*s1) + (s2*s2)){
            printf("Right-angled\n");
        }else{
            printf("Not right-angled\n");
        }
    }

}