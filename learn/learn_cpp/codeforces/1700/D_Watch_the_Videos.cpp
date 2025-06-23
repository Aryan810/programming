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
    
    int n, m;
    cin >> n >> m;

    vi a(n);
    rep(i, n) cin >> a[i];

    sort(all(a));

    int i = 0;
    int j = n-1;
    int curr = 1;
    int ans = 0;
    while (i < j){
        if (a[j]+a[i] > m){
            if (curr){
                ans += a[j] + 1;
                j -= 1;
            }else{
                ans += a[i] + 1;
                i += 1;
                curr = 1 - curr;
            }
        }else{
            if (curr){
                ans += a[j];
                j -= 1;
                curr = 1 - curr;
            }else{
                ans += a[i];
                i += 1;
                curr = 1 - curr;
            }
        }
    }
    if (i == j){
        ans += a[i] + 1;
    }
    cout << ans << endl;


}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // mint::set_mod(M);
    
    solve();

    return 0;
}