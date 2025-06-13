#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *f;
    f = fopen("1.txt", "r");

    while (1){
        char c, space, c2;
        c = getc(f); // first number
        if ((c-'0')>=0 && (c-'0')<=9){
            space = getc(f); // space between numbers
            c2 = getc(f); // next number of the line
            getc(f); // newline;
            printf("%c %c\n", c, c2);
        }else{
            printf("->EOF<-\n");
            break;
        }
    }

    fclose(f);
    return 0;
}