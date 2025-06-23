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

int dp[501][501];

int helper(int a, int b){
    // cout << a << " " << b << endl;
    if (a == b){
        return 0;
    }
    if (dp[a][b] != -1){
        return dp[a][b];
    }

    int ret = 1e9;
    for (int i=1;i<=a/2;i++){
        ret = min(ret, 1 + helper(i, b) + helper(a-i, b));
    }
    for (int i=1;i<=b/2;i++){
        ret = min(ret, 1 + helper(a, i)) + helper(a, b-i);
    }
    return dp[a][b] = ret;
}

void solve(){
    int a, b;
    cin >> a >> b;
    memset(dp, 0, sizeof(dp));
    for (int i=1;i<=500;i++){
        dp[i][i] = 0;
    }
    for (int i=1;i<=a;i++){
        for (int j=1;j<=b;j++){
            int temp = 1e9;
            if (i == j){
                continue;
            }
            for (int k=1;k<=(i/2);k++){
                temp = min(temp, dp[k][j] + dp[i-k][j] + 1);
            }
            for (int k=1;k<=(j/2);k++){
                temp = min(temp, dp[i][k] + dp[i][j-k] + 1);
            }
            dp[i][j] = temp;
        }
    }
    cout << dp[a][b] << endl;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // mint::set_mod(M);

        solve();


    return 0;
}