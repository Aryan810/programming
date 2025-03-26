#include <stdio.h>
#include <stdlib.h>

int length(char * str){
    int len = 0;
    for (int i=0;;i++){
        if (!str[i]){
            break;
        }
        len += 1;
    }
    return len;
}

char * multiply(char* num1, char* num2){
    const int n=length(num1), m=length(num2);
    int vals[n+m+2];
    for (int i=0;i<(n+m+2);i++){
        vals[i] = 0;
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            int x=num1[i]-'0', y=num2[j]-'0';
            vals[n-1-i+m-1-j] += (x*y);
        }
    }
    int temp[n+m+2];
    for (int i=0;i<(n+m+2);i++){
        temp[i] = 0;
    }
    for (int i=0;i<(n+m+1);i++){
        int x = vals[i];
        temp[i] += x%10;
        vals[i+1] += x/10;
    }
    char * ans;
    ans = (char*)malloc((sizeof(char))*(n+m));
    // char ans[n+m];
    int found = 0;
    int j = 0;
    for (int i=(n+m);i>=0;i--){
        if (temp[i] != 0){
            found = 1;
        }
        if (found){
            ans[j] = temp[i]+'0';
            j += 1;
        }
    }
    return ans;
}
int main(){
    char a[201], b[201];
    scanf("%s\n%s", a, b);
    char * ans = multiply(a, b);
    if (length(ans) == 0){
        ans[0]='0';
    }
    printf("%s\n", ans);
    free(ans);
    return 0;
}