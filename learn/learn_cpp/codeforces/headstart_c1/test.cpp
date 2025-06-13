#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    int x = n/m;
    long long ans = (n%m != 0);
    while(x >= 0){
        ans += x*(n - x*m + 1);
        x--;
    }
    cout << (ans) << endl;

    return 0;
}