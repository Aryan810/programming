// #include<atcoder/modint>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;
// using mint = modint;
#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator
#define umap(x, y) unordered_map<x, y, custom_hash>
const int M = 1e9 + 7;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

void solve(){
    
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, n){
        int x;
        cin >> x;
        a[i] = x;
    }
    int ans = 1e18;
    for (int v=0;v<=a[0];v++){
        int mn = v;
        int mx = 0;
        for (int i=0;i<n;i++){
            int val = a[i];
            int p = (v!=0?min(k, a[i]/v):k);
            mn = min(mn, val/p);
            mx = max(mx, val/p);
        }

        ans = min(ans, abs(mn-mx));
    }
    
    cout << ans << endl;


}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // mint::set_mod(M);
    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}