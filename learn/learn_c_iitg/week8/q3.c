#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int length(char * s){
    int l = 0;
    for (int i=0;;i++){
        if (!s[i]){break;}
        l += 1;
    }
    return l;
}

char* countandsay(char * s, int x){
    if (x <= 0){
        return s;
    }
    const int n = length(s);
    char* out = (char*)malloc(sizeof(char)*(2*n+1));
    int i=0, j=0, k=0;
    while (i < n){
        while (j < n && s[j] == s[i]){
            j += 1;
        }
        char num[30] = "";
        sprintf(num, "%d", j-i);
        for (int l=0;;l++){
            if (!num[l]){
                break;
            }
            out[k] = num[l];
            k += 1;
        }
        out[k] = s[i];
        k += 1;
        i = j;
    }
    free(s);
    countandsay(out, x-1);
}

int main(){
    int n;
    scanf("%d", &n);
    char * ans;
    char * str = (char *)malloc((sizeof(char))*10);
    str[0] = '1';
    str[1] = 0;
    ans = countandsay(str, n-1);
    printf("%s\n", ans);
    return 0;
}