#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

bool logic(vi & c, int & n){
    lli sum = c[0];
    if (c[0] != 1){return 0;}
    for (int i=1;i<n;i++){
        if (c[i] > sum){return 0;}
        sum += c[i];
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vi c(n);
        for (int i=0;i<n;i++) cin >> c[i];
        sort(c.begin(), c.end());
        cout << (logic(c, n)?"YES":"NO") << endl;
    }

    return 0;
}