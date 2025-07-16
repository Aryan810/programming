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

int helper(int i, int k, int & n, int & m, vvi & dp, vi & a, vi & b){
    // cout << i << " " << k << endl;
    if (i >= n){
        return 0;
    }else if (k >= m){
        return 1e18;
    }
    if (dp[i][k] != -1){
        return dp[i][k];
    }

    int ret = 1e18;
    int sm = 0;
    int len = 0;
    int j = i;
    while (j < n){
        if (sm + a[j] <= b[k]){
            sm += a[j];
            j += 1;
        }else{
            break;
        }
    }
    if (j == i){
        return dp[i][k] = 1e18;
    }

    // keep this 'k' and do a full possible operation.
    ret = min(ret, helper(j, k, n, m, dp, a, b) + (m-k-1));

    // increase the value of 'k' by one.
    ret = min(ret, helper(i, k+1, n, m, dp, a, b));

    return dp[i][k] = ret;

}

void solve(){
    
    int n, m;
    cin >> n >> m;
    vvi dp(n, vector<int>(m, -1));
    vi a(n);
    rep(i, n) cin >> a[i];

    vi b(m);
    rep(i, m) cin >> b[i];

    if (mxv(a) > b[0]){
        cout << -1 << endl;return;
    }
    int ans = helper(0, 0, n, m, dp, a, b);
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