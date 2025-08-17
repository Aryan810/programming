// #include<atcoder/modint>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
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
const int mod7 = 1e9 + 7;
const int mod9 = 998244353;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

#ifdef LOCAL
#include "/Users/aryangupta/Documents/programming/templets/algo/debug.h"
#else
#define debug(...) 42
#endif

void solve(){
    int n;
    cin >> n;
    vi a(n);
    vi b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    int dp[n+1][2];
    memset(dp, 0, sizeof(dp));
    dp[n-1][0] = n-1;
    dp[n-1][1] = n-1;
    for (int i=n-2;i>=0;i--){
        for (int j=0;j<2;j++){
            int tmp = i;
            int curr;
            if (j){
                curr = a[i];
            }else{
                curr = b[i];
            }
            if (a[i+1] > curr){
                tmp = max(tmp, dp[i+1][1]);
            }
            if (b[i+1] > curr){
                tmp = max(tmp, dp[i+1][0]);
            }
            // cout << i << " " << tmp << endl;
            dp[i][j] = tmp;
        }
    }

    int ans = 0;
    for (int i=0;i<n;i++){
        int l = i;
        int h = max(dp[i][0], dp[i][1]);
        // cout << i << " " << l << " " << h << endl;
        ans += max(0ll, h-l+1);
    }
    
    cout << ans << endl;


}

signed main(){
    fast_io;   
    // mint::set_mod(M);
    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}