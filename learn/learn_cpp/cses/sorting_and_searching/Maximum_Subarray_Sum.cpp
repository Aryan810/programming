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
    
    int n;
    cin >> n;
    vi a(n);
    int sm = 0;
    vi cum(n+1);
    cum[0] = 0;
    multiset<int> vals;
    vals.insert(0);
    rep(i, n){
        int x;
        cin >> x;
        sm += x;
        cum[i+1] = sm;
        vals.insert(sm);
        a[i] = x;
    }
    int ans = -1e18;
    for (int i=0;i<n;i++){
        vals.erase(vals.find(cum[i]));
        int mx = *(--vals.end());
        ans = max(ans, mx-cum[i]);
    }
    cout << ans << endl;
    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // mint::set_mod(M);
    // int test;
    // cin >> test;

    // while(test--){
        solve();
    // }

    return 0;
}