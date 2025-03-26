#include <stdio.h>

int main(){
    int b1, b2;
    int num;
    scanf("%d", &num);
    scanf("%d", &b1);
    scanf("%d", &b2);

    int base10 = 0;
    int tmp = num;
    int placevalue = 1;
    while (tmp > 0){
        base10 += (tmp%10)*placevalue;
        placevalue *= b1;
        tmp /= 10;
    }

    int ans = 0;
    tmp = base10;
    placevalue = 1;
    while (tmp > 0){
        ans += placevalue * (tmp%b2);
        placevalue *= 10;
        tmp /= b2;
    }
    printf("%d\n", ans);

    return 0;
}