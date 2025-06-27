// #include<atcoder/modint>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;
// using mint = modint;
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define each(x, a) for (auto &x : a)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pi pair<int, int>
#define p(a, b) pair<a, b>
#define vi vector<int>
#define vii vector<int>::iterator
#define vvi vector<vector<int> >
#define vv(x) vector<vector<x> >
#define PRECISION(x) cout << fixed << setprecision(x);
#define mnv(v) *min_element(v.begin(), v.end())
#define mxv(v) *max_element(v.begin(), v.end())
#define umap(x, y) unordered_map<x, y, custom_hash>
const int M = 1e9 + 7;
const int mod9 = 998244353;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

int dp[501][126000];
int binexpiter(int a, int b){
    int ans = 1;
    while (b){
        if (b&1){
            ans = (ans * a)%M;
        }
        a = (a * a)%M;
        b >>= 1;
    }
    return ans;
}
void solve(){
    
    int n;
    cin >> n;
    int mx = (n*(n+1))/2;
    if (mx&1){
        cout << 0 << endl;return;
    }
    mx /= 2;
    // cout << mx << endl;
    // vector<int> lastRow(63000)
    dp[1][0] = 1;
    dp[1][1] = 1;
    // cout << n << " " << mx << endl; 
    for (int i=2;i<=n;i++){
        // cout << i << " " << dp[i][mx] << endl;
        for (int sm=0;sm<=(i*(i+1))/2;sm++){
            int temp = 0;
            if (sm >= i){
                temp += dp[i-1][sm-i];
                temp %= M;
            }
            temp = (temp + dp[i-1][sm]%M)%M;
            // cout << i << " " << temp << " " << dp[n][mx] << endl;
            dp[i][sm] = temp;
        }
    }
    // cout << "er" << endl;
    cout << (dp[n][mx]*binexpiter(2, M-2))%M << endl;
    
    

}

signed main(){
    fast_io;   
    // mint::set_mod(M);
    // int test;
    // cin >> test;

    // while(test--){
        solve();
    // }

    return 0;
}