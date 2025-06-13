#include <stdio.h>
#define MAX_TERMS 202

typedef struct {
    int exp;
    int coeff;
} Term;

typedef struct{
    Term terms[MAX_TERMS];
    int numTerms;
} Polynomial;

int main(){
    int n, m;
    scanf("%d", &n);
    Polynomial p1, p2;
    p1.numTerms = MAX_TERMS/2;
    for (int i=0;i<MAX_TERMS/2;i++){
        p1.terms[i].coeff = 0;
        p1.terms[i].exp = i;
    }
    for (int i=0;i<n;i++){
        int c, e;
        scanf("%d %d", &c, &e);
        p1.terms[e].coeff = c;
        p1.terms[e].exp = e;
    }
    scanf("%d", &m);
    p2.numTerms = MAX_TERMS/2;
    for (int i=0;i<MAX_TERMS/2;i++){
        p2.terms[i].coeff = 0;
        p2.terms[i].exp = i;
    }
    for (int i=0;i<m;i++){
        int c, e;
        scanf("%d %d", &c, &e);
        p2.terms[e].coeff = c;
        p2.terms[e].exp = e;
    }
    // add polynomials
    for (int i=(MAX_TERMS/2)-1;i>=0;i--){
        int coeff = p1.terms[i].coeff + p2.terms[i].coeff;
        if (coeff != 0){
            printf("(%d,%d) ", coeff, i);
        }
    }
    printf("\n");

    // multiply polynomails
    Polynomial ans;
    for (int i=0;i<MAX_TERMS;i++){
        ans.terms[i].coeff = 0;
        ans.terms[i].exp = i;
    }
    ans.numTerms = MAX_TERMS;
    for (int i=0;i<MAX_TERMS/2;i++){
        for (int j=0;j<MAX_TERMS/2;j++){
            ans.terms[p1.terms[i].exp + p2.terms[j].exp].coeff += p1.terms[i].coeff * p2.terms[j].coeff;
            ans.terms[p1.terms[i].exp + p2.terms[j].exp].exp += p1.terms[i].exp + p2.terms[j].exp;
        }
    }

    for (int i=MAX_TERMS-1;i>=0;i--){
        int coeff = ans.terms[i].coeff;
        if (coeff != 0){
            printf("(%d,%d) ", coeff, i);
        }
    }
    printf("\n");
    return 0;
}