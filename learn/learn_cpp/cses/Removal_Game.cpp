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
int dp[5001][5001][2];
// pair<int, int> helper(int i, int j, int first, vi & a){
//     // cout << i << " " << j << " " << first << endl;
//     if (i > j){
//         return {0, 0};
//     }
//     if (dp[i][j][first][0] != -1 || dp[i][j][first][1] != -1){
//         return {dp[i][j][first][1], dp[i][j][first][0]};
//     }

//     int ret = -1e18;
//     if (first){
//         auto f = helper(i+1, j, 1 - first, a);
//         auto s = helper(i, j-1, 1 - first, a);
//         int p = a[i] + f.first;
//         int q = a[j] + s.first;
//         // taking first
//         ret = max(ret, p);
        
//         // taking second
//         ret = max(ret, q);

//         dp[i][j][first][1] = ret;
//         int r1;
//         if (p > q){
//             dp[i][j][first][0] = f.second;
//             r1 = f.second;
//         }else{
//             dp[i][j][first][0] = s.second;
//             r1 = s.second;
//         }
//         return {ret, r1};
//     }else{
//         auto f = helper(i+1, j, 1 - first, a);
//         auto s = helper(i, j-1, 1 - first, a);
//         int p = a[i] + f.second;
//         int q = a[j] + s.second;
//         // taking first
//         ret = max(ret, p);
        
//         // taking second
//         ret = max(ret, q);

//         dp[i][j][first][0] = ret;
//         int r1;
//         if (p > q){
//             dp[i][j][first][1] = f.first;
//             r1 = f.first;
//         }else{
//             dp[i][j][first][1] = s.first;
//             r1 = s.first;
//         }
//         return {r1, ret};
//     }

// }

void solve(){
    int n;
    cin >> n;
    // vector<vector<array<array<int, 2>, 2> > > dp(n+1, vector<array<array<int, 2>, 2> >(n+1));
    // for (int i=0;i<n;i++){
    //     for (int j=0;j<n;j++){
    //         dp[i][j][0][0] = -1;
    //         dp[i][j][0][1] = -1;
    //         dp[i][j][1][0] = -1;
    //         dp[i][j][1][1] = -1;
    //     }
    // }
    // memset(dp, -1, sizeof(dp));
    vi a(n);
    rep(i, n) cin >> a[i];
    // pair<int, int> ans = helper(0, n-1, 1, a);
    for (int i=0;i<n;i++){
        dp[i][i][1] = a[i];
        dp[i][i][0] = 0;
    }

    for (int i=n-1;i>=0;i--){
        for (int j=0;j<n;j++){
            if (i >= j){
                continue;
            }
            dp[i][j][1] = max(a[i] + dp[i+1][j][0], dp[i][j-1][0] + a[j]);
            dp[i][j][0] = min(dp[i+1][j][1], dp[i][j-1][1]);
        }
    }

    cout << dp[0][n-1][1] << endl;



}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // mint::set_mod(M);

    solve();

    return 0;
}