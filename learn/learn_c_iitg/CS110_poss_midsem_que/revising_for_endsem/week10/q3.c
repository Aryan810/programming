#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE * f;
    f = fopen("1.txt", "r");

    char strings[1000][100];
    int curr = 0;
    while (1){
        char s[100] = "";
        fscanf(f, "%s", s);
        if (strcmp("", s) == 0){
            break;
        }
        printf("%s\n", s);
    }

    fclose(f);

}