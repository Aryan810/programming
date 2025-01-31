#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace __gnu_pbds;
using namespace std;
#define int long long
#define vi vector<int>
#define vii vector<int>::iterator
#define rep(i, n) for(int i=0;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
unordered_map<int, int> DP;
int dofib(int n){
    if (n == 0){
        return 0;
    }else if (n == 1){return 1;}
    if (DP[n] != 0){return DP[n];}
    return DP[n] = dofib(n-1) + dofib(n-2);
}

void solve(){

    int n;
    cin >> n;
    // vi a(2);
    // a[0] = 0;
    // a[1] = 1;
    // dofib(a, n);
    // for (auto ele: a){
    //     cout << ele << " ";
    // }cout << endl;
    rep(i, n){
        cout << dofib(i) << " ";
    }cout << endl;

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        solve();

    }

    return 0;
}