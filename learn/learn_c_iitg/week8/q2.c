#include <stdio.h>
#include <string.h>

int helper(int dp[21][21], int i, int j, char * a, char * b){
    int p = strlen(a);
    int q = strlen(b);
    // printf("i: %d j: %d\n", i, j);
    if (i >= p && j >= q){
        return 1;
    }else if (i >= p){
        return 0;
    }else if (j >= q){
        return 0;
    }
    int ans = 0;
    if (j+1 < p && b[j+1] == '*'){
        ans = ans || helper(dp, i, j+2, a, b);
        for (int k=i+1;k<p && a[k] == b[j];k++){
            ans = ans || helper(dp, k, j+2, a, b);
        }
    }else if (b[j] == '.'){
        ans = ans || helper(dp, i+1, j+1, a, b);
    }else{
        if (a[i] != b[j]){
            return dp[i][j] = 0;
        }else{
            ans = ans || helper(dp, i+1, j+1, a, b);
        }
    }
    return dp[i][j] = ans;
}

int isMatch(char * a, char * b){
    int dp[21][21];
    return helper(dp, 0, 0, a, b);
}

int main(){
    char a[21];
    char b[21];

    scanf("%s\n%s", a, b);

    printf("%d\n", isMatch(a, b));

    return 0;
}