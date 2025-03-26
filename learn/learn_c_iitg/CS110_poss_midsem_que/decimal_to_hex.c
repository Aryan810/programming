#include <stdio.h>

int main(){
    int num;
    scanf("%d", &num);
    char placedef[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    // convert to hex;
    char ans[100];
    int tmp = num;
    int place = 0;
    while (tmp > 0){
        ans[place] = placedef[tmp%16];
        tmp /= 16;
        place += 1;
    }
    place -= 1;
    while (place >= 0){
        printf("%c", ans[place]);
        place -= 1;
    }
    printf("\n");
    return 0;
}