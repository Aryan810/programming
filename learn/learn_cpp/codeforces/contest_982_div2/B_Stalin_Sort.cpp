#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

void logic(vlli & a, lli & ans){
    auto M = max_element(a.begin(), a.end());
    if (ans > (M-a.begin())){
        ans = M-a.begin();
    }
    a.erase(M);

    // if (M != a.begin()){
    //     ans += 1;
    //     a.erase(M, a.end());
    //     if (*a.begin() < *max_element(a.begin(), a.end())){
    //         a.erase(a.begin());
    //         ans += 1;
    //     }
    //     logic(a, ans);
    // }else{
    //     return;
    // }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vlli a(n);
        for (int i=0;i<n;i++) cin >> a[i];
        
        lli ans = 1e18;
        lli rem = 0;
        while (ans != 0 && a.size() > 0){
            auto M = max_element(a.begin(), a.end());
            lli x = (M-a.begin()) + rem;
            if (ans > x){
                ans = x;
            }
            if (M != a.end()){
                a.erase(M);
            }
            rem += 1;
        }
        cout << ans << endl;

    }

    return 0;
}