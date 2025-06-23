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

    int q;
    cin >> q;
    vi a(n);
    rep(i, n) cin >> a[i];

  
    vector<int> l(q), r(q);
    for (int i=0;i<q;i++){
        int x, y;
        cin >> x >> y;
        l[i] = x;
        r[i] = y;
    }
    sort(all(l));
    sort(all(r));

    vector<int> v;
    for (int i=0;i<n;i++){
        // cout << i << endl;
        auto it1 = upper_bound(all(l), i+1);
        auto it2 = lower_bound(all(r), i+1);
        int ri = l.size() - (int)(it1 - l.begin());
        int lf = it2 - r.begin();
        // cout << lf << " " << ri << endl;
        // cout << "Q: " << (q) << endl;
        v.push_back(q - ri - lf);
    }
    sort(rall(v));
    sort(rall(a));
    int ans = 0;
    for (int i=0;i<n;i++){
        ans += v[i] * a[i];
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