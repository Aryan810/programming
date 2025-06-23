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
    vector<vector<int> > dp(n+1, vector<int>(k+1, 1e15));
    vi a(n);
    rep(i, n) cin >> a[i];
    for (int i=0;i<=k;i++){
        dp[0][i] = 0;
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<=k;j++){
            int mn = 1e18;
            for (int ppos=i;(i-ppos)<=j && ppos > 0;ppos--){
                mn = min(mn, a[ppos-1]);
                int x = (i - ppos + 1)*mn;
                dp[i][j] = min(dp[i][j], x + dp[ppos-1][j-(i-ppos)]);
            }
        }
    }
    int ans = 1e18;
    for (int i=0;i<=k;i++){
        ans = min(ans, dp[n][i]);
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