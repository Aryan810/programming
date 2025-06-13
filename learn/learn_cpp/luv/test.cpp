#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[6];
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 3;
    a[4] = 3;
    a[5] = 4;

    cout << lower_bound(&a[0], &a[6], 3)-&a[0] << endl;

   
    

    return 0;
}