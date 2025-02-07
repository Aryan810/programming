#include <stdio.h>
int n, m;
void gaussian_elim(int mat[n][m], int out[n][m]){
    int p = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            out[i][j] = mat[i][j];
        }
    }
    while (p < m && p < n){
        int a = out[p][p];
        for (int i=p+1;i<n;i++){
            int b = out[i][p];
            for (int j=p;j<m;j++){
                out[i][j] = a*out[i][j] - b*out[p][j];
            }
        }
        p += 1;
    }
}
void gaussian_elim_red(int mat[n][m], int out[n][m]){
    int p = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            out[i][j] = mat[i][j];
        }
    }
    while (p < m && p < n){
        int a = out[p][p];
        for (int i=p+1;i<n;i++){
            int b = out[i][p];
            for (int j=p;j<m;j++){
                out[i][j] = a*out[i][j] - b*out[p][j];
            }
        }
        for (int j=p;j<m;j++){
            out[p][j] /= a;
        }
        p += 1;
    }
}

int main(){

    printf("Enter dim of matrix i.e 'n' and 'm': ");
    scanf("%d %d", &n, &m);
    int mat[n][m];
    for (int i=0;i<n;i++){
        printf("Enter row %d: ", i);
        for (int j=0;j<m;j++){
            scanf("%d", &mat[i][j]);
        }
        printf("\n");
    }
    printf("Input matrix: \n");
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            printf("%d ", mat[i][j]);
        }printf("\n");
    }
    int out[n][m];
    // gaussiam elim;
    gaussian_elim(mat, out);
    printf("Gaussian eliminated form: \n");
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            printf("%d ", out[i][j]);
        }printf("\n");
    }
    
    // reduced gaussian elemination
    gaussian_elim_red(mat, out);
    printf("Reduced Gaussian eliminated form: \n");
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            printf("%d ", out[i][j]);
        }printf("\n");
    }

}