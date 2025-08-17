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

int calc(int sm, int m){
    sm %= m;
    return (m - sm)%m;
}

int calc1(int x, int to, int m){
    x %= m;
    if (to == x){return 0;}
    else if (to > x){
        return to-x;
    }else{
        return to + m - x;
    }
}

void solve(){
    
    int n, m, l;
    cin >> n >> m >> l;

    vi a(n);
    rep(i, n) cin >> a[i];

    int ans = 1e18;
    int f[l][m];
    int dp[l+1][m+1];
    memset(dp, 0, sizeof(dp));
    for (int i=0;i<l;i++){
        for (int j=0;j<m;j++){
            int tmp = 0;
            for (int k=i;k<n;k+=l){
                tmp += calc1(a[k], j, m);
            }
            f[i][j] = tmp;
        }
    }

    for (int i=0;i<m;i++){
        dp[0][i] = f[0][i];
    }

    for (int i=1;i<l;i++){
        for (int j=0;j<m;j++){
            int tmp = 1e18;
            for (int k=0;k<m;k++){
                tmp = min(tmp, f[i][k] + dp[i-1][(j-k+m)%m]);
            }
            dp[i][j] = tmp;
        }
    }

    cout << dp[l-1][0] << endl;
}

signed main(){
    fast_io;   
    // mint::set_mod(M);
    int test = 1;
    while(test--){
        solve();
    }

    return 0;
}