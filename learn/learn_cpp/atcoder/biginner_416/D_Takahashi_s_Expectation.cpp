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
int dp[10001][501];
vector<array<int, 3> > a;
int n;

int helper(int i, int val){
    if (i >= n){
        return val;
    }
    if (dp[i][val] != -1){
        return dp[i][val];
    }

    if (a[i][0] >= val){
        return helper(i+1, val + a[i][1]);
    }else{
        return helper(i+1, max(0ll, val - a[i][2]));
    }
}

void solve(){
    
    cin >> n;
    a.resize(n);
    memset(dp, -1, sizeof(dp));
    int sma = 0;
    int smb = 0;
    rep(i, n) cin >> a[i][0] >> a[i][1] >> a[i][2];
    for (int i=0;i<n;i++){
        sma += a[i][1];
        smb += a[i][2];
    }
    vi cum(n+1, 0);
    for (int i=0;i<n;i++){
        cum[i+1] = cum[i] + a[i][2];
    }
    int q;
    cin >> q;
    for (int i=0;i<q;i++){
        int x;
        cin >> x;
        if (x <= 500){
            cout << helper(0, x) << endl;
            continue;
        }

        auto it = lower_bound(all(cum), x-500);
        int ind = it - cum.begin();
        if (it == cum.end()){
            cout << x - cum[n] << endl;
        }else{
            cout << helper(ind, max(0ll, x - *it)) << endl;
        }
    }

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