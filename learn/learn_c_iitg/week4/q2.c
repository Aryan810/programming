#include <stdio.h>

int main(){
    int units;
    char due;
    scanf("%d\n%c", &units, &due);
    float tarif = 0;
    int unit = units;
    if (units > 0){
        if (units >= 100){tarif += 1.5f * (100);units -= 100;}else{
            tarif += 1.5f * (units);
            units = 0;
        }
    }
    if (units > 0){
        if (units >= 100){tarif += 2 * (100);units -= 100;}else{
            tarif += 2 * (units);
            units = 0;
        }
    }
    if (units > 0){
        if (units >= 100){tarif += 2.5f * (100);units -= 100;}else{
            tarif += 2.5f * (units);
            units = 0;
        }
    }
    if (units > 0){
        tarif += 3 * (units);
        units = 0;
    }
    if (unit > 300){
        tarif = tarif * (1.05f);
    }
    if (unit <= 150){
        tarif = tarif * (0.9f);
    }
    if (due == 'Y'){
        tarif += 20;
    }
    tarif += 50;
    printf("%.2f", tarif);
    return 0;
}