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
const int mod7 = 1e9 + 7;
const int mod9 = 998244353;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key
// int dp[5001][5001];
const int INF = 1e15;

int helper(int i, int gc, vi & a, int & req, vvi & dp){
    int n = a.size();
    if (i >= n){
        if (gc == req){
            return 0;
        }else{
            return INF;
        }
    }
    if (dp[i][gc] != -1){
        return dp[i][gc];
    }

    int ret = min(helper(i+1, gcd(gc, a[i]), a, req, dp) + 1, helper(i+1, gc, a, req, dp));
    return dp[i][gc] = ret;
}

void solve(){
    
    int n;
    cin >> n;

    vi a(n);
    int req = 0;
    rep(i, n){
        int x;
        cin >> x;
        req = gcd(req, x);
        a[i] = x;
    }
    int cnt = 0;
    for (auto & ele: a){
        if (ele == req){
            cnt += 1;
        }
    }
    if (cnt > 0){
        cout << n-cnt << endl;return;
    }
    vvi dp(n+1, vector<int>(5001, -1));
    int ans = helper(0, 0, a, req, dp);
    cout << ans+n-2 << endl;

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