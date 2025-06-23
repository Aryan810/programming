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
    int dp[n+2][n+2][3];
    memset(dp, 0, sizeof(dp));
    int oper = 0;
    for (int i=1;i<=n;i++){
        string s;
        cin >> s;
        for (int j=1;j<=n;j++){
            int curr = s[j-1]-'0';
            dp[i][j][0] = dp[i-1][j-1][0] + dp[i-1][j][1];
            dp[i][j][1] = dp[i-1][j][1];
            dp[i][j][2] = dp[i-1][j+1][2] + dp[i-1][j][1];
            int tot = dp[i-1][j-1][0] + dp[i-1][j][1] + dp[i-1][j+1][2];
            // cout << "(" << tot << ", " << curr << ") ";
            if ((tot+curr)&1){
                // cout << curr << " ";
                oper += 1;
                dp[i][j][0] += 1;
                dp[i][j][1] += 1;
                dp[i][j][2] += 1;
            }
        }
    }
    // for (int i=1;i<=n;i++){
    //     for (int j=1;j<=n;j++){
    //         cout << dp[i][j][0] << dp[i][j][1] << dp[i][j][2] << " ";
    //     }cout << endl;
    // }
    cout << oper << endl;

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