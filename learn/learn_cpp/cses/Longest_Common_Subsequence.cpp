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

int dp[1000][1000];

int helper(int i, int j, vi & a, vi & b){
    int n = a.size();
    int m = b.size();

    if (i >= n || j >= m){
        return 0;
    }

    if (dp[i][j] != -1){
        return dp[i][j];
    }

    int ret = 0;
    if (a[i] == b[j]){
        ret = 1 + helper(i+1, j+1, a, b);
    }else{
        ret = max(ret, helper(i+1, j, a, b));
        ret = max(ret, helper(i, j+1, a, b));
    }
    return dp[i][j] = ret;
}

void solve(){
    
    int n, m;
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    vi a(n);
    rep(i, n) cin >> a[i];
    vi b(m);
    rep(i, m) cin >> b[i];
    int ans = helper(0, 0, a, b);
    // for (int i=0;i<n;i++){
    //     for (int j=0;j<m;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // finding LCS ->
    int i = 0;
    int j = 0;
    int left = ans;
    vi out;
    while (left > 0 && (i < n && j < m)){
        while (a[i] != b[j]){
            // cout << i << " " << j << endl;
            int r = -1;
            if (i+1 < n){
                r = dp[i+1][j];
            }
            int d = -1;
            if (j+1 < m){
                d = dp[i][j+1];
            }

            if (d >= r){
                j += 1;
            }else{
                i += 1;
            }
        }
        // cout << i << " ";
        out.push_back(a[i]);
        left -= 1;
        i += 1;
        j += 1;
    }
    cout << ans << endl;
    for (auto & ele: out){
        cout << ele << " ";
    }cout << endl;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // mint::set_mod(M);
    solve();

    return 0;
}