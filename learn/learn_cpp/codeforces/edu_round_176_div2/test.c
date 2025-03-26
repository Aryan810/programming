#include<stdio.h>
#include<stdlib.h>
void readar(int **x,int n) {
    int i;
    *x=(int *)malloc(sizeof(int) *n);
    for(i=0;i<n;i++) {
        scanf("%d",*x + i);
    }
}
void printar(int *x, int n) {
    int i;
    for(i=0;i<n;i++) {
        printf("%d\t",x[i]);
    }
    x[i]=100;
}
int main() {
    int *a,i;
    readar(&a,5);
    printar(a,5);
    printf("\n%d",a[2]);
    return 0;
}