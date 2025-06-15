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
    
    int n, m, k;
    cin >> n >> m >> k;

    vi a(n);
    rep(i, n) cin >> a[i];

    vi b(m);
    rep(i, m) cin >> b[i];

    sort(all(a));
    sort(all(b));
    int i = 0;
    int j = 0;

    int ans = 0;
    while (i < n && j < m){
        // cout << b[j] << " " << a[i] << " " << k << endl;
        if (b[j] >= a[i]-k && b[j] <= a[i]+k){
            i += 1;
            j += 1;
            ans += 1;
        }else{
            if (!(b[j] >= a[i]-k)){j += 1;}else{
                i += 1;
            }
        }
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