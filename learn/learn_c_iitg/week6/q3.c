#include <stdio.h>

int main(){
    int n, m;
    scanf("%d\n%d", &n, &m);
    int grid[n][m];
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            scanf("%d", &grid[i][j]);
        }
    }
    int curr = -1;
    for (int i=0;i<n;i++){
        int j = 0;
        while (j < m && grid[i][j] == 0){
            j += 1;
        }
        if (j <= curr){
            printf("0\n");return 0;
        }else{
            curr = j;
        }
    }
    printf("1\n");
    return 0;
}