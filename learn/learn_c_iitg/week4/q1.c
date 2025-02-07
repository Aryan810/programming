#include <stdio.h>

int main(){
    int m, d;
    scanf("%d",&d);
    scanf("%d",&m);
    
    if (m > 12){
        printf("Invalid date\n");
        return 0;
    }
    if (m == 2 && (d > 29 || d < 1)){
        printf("Invalid date\n");
        return 0;
    }else{
        if (d > 31 || d < 1){
            printf("Invalid date\n");
            return 0;
        }
    }

    // for aries
    if (m == 3 && (d >= 21 && d <= 31)){
        printf("Aries");
    }else if (m == 4 && (d <= 19)){
        printf("Aries");
    }

    else if (m == 4){
        printf("Taurus");
    }else if (m == 5 && (d <= 20)){
        printf("Taurus");
    }

    else if (m == 5){
        printf("Gemini");
    }else if (m == 6 && (d <= 20)){
        printf("Gemini");
    }
    else if (m == 6){
        printf("Cancer");
    }else if (m == 7 && (d <= 2)){
        printf("Cancer");
    }
    else if (m == 7){
        printf("Leo");
    }else if (m == 8 && (d <= 22)){
        printf("Leo");
    }
    else if (m == 8){
        printf("Virgo");
    }else if (m == 9 && (d <= 22)){
        printf("Virgo");
    }
    else if (m == 9){
        printf("Libra");
    }else if (m == 10 && (d <= 22)){
        printf("Libra");
    }
    else if (m == 10){
        printf("Scorpio");
    }else if (m == 11 && (d <= 21)){
        printf("Scorpio");
    }
    else if (m == 11){
        printf("Sagittarius");
    }else if (m == 12 && (d <= 21)){
        printf("Sagittarius");
    }
    else if (m == 12){
        printf("Capricorn");
    }else if (m == 1 && (d <= 19)){
        printf("Capricorn");
    }
    else if (m == 1){
        printf("Aquarius");
    }else if (m == 2 && (d <= 18)){
        printf("Aquarius");
    }
    else if (m == 2){
        printf("Pisces");
    }else if (m == 4 && (d <= 20)){
        printf("Pisces");
    }
    printf("\n");
    
}