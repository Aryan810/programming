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
int dp[5001][5001];

int helper(int i, int j, int & n, int & m, string & a, string & b){
    // cout << i << " " << j << endl;
    if (i >= n && j >= m){
        // cout << "HERE" << endl;
        return 0;
    }else if (i >= n){
        return m-j;
    }else if (j >= m){
        return n-i;
    }
    if (dp[i][j] != -1){
        return dp[i][j];
    }

    int ret = 1e18;
    // cout << "I am here" << endl;
    if (a[i] == b[j]){
        // cout << "HERE 1" << endl;
        ret = min(ret, helper(i+1, j+1, n, m, a, b));
    }else{
        // case 1 - make a[i] -> b[j] OR b[j] -> a[i];
        ret = min(ret, 1 + helper(i+1, j+1, n, m, a, b));

        // case 2 - delete a[i];
        ret = min(ret, 1 + helper(i, j+1, n, m, a, b));

        // case 3 - delete b[j];
        ret = min(ret, 1 + helper(i+1, j, n, m, a, b));
    }
    return dp[i][j] = ret;
}

void solve(){
    
    string a, b;
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    int n = a.size();
    int m = b.size();
    int ans = helper(0, 0, n, m, a, b);
    // cout << dp[3][4] << endl;
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