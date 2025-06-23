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
const int N = 1e6;
int dp[N + 1][2];

void solve(){
    
    int t;
    cin >> t;

    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i=2;i<=N;i++){
        dp[i][0] = 4 * dp[i-1][0] + dp[i-1][1];
        dp[i][1] = 2 * dp[i-1][1] + dp[i-1][0];
        dp[i][0] %= M;
        dp[i][1] %= M;
    }

    for (int i=0;i<t;i++){
        int n;
        cin >> n;
        cout << (dp[n][0] + dp[n][1])%M << endl;
    }
    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}