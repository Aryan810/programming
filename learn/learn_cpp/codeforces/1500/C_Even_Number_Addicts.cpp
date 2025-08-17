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

int dp[101][101][2][2];

int helper(int e, int o, int chance, int parity){
    // cout << e << " " << o << " " << chance << " " << parity << endl;
    if (e == 0 && o == 0){
        return parity;
    }
    if (dp[e][o][chance][parity] != -1){
        return dp[e][o][chance][parity];
    }

    int ret;
    if (chance){
        ret = (e>0 && helper(e-1, o, 1-chance, parity)) | (o>0 && helper(e, o-1, 1-chance, 1-parity));
    }else{
        ret = !((e>0 && !helper(e-1, o, 1-chance, parity)) | (o>0 && !helper(e, o-1, 1-chance, parity)));
    }
    // cout << ret << endl;
    return dp[e][o][chance][parity] = ret;
}


void solve(){
    
    int n;
    cin >> n;
    int e = 0;
    int o = 0;
    vi a(n);
    memset(dp, -1, sizeof(dp));
    rep(i, n){
        int x;
        cin >> x;
        if (((int)(x+1e9))&1){
            o += 1;
        }else{
            e += 1;
        }
    }

    int ans = helper(e, o, 1, 1);
    cout << (ans?"Alice":"Bob") << endl;





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