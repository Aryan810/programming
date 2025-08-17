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
vector<int> dp;
vi a;
int helper(int i){
    if (i == 0){
        return 1;
    }else if (i == 1){
        if (a[0] > a[i]){
            return 3;
        }else{
            return 2;
        }
    }

    if (dp[i] != -1){
        return dp[i];
    }

    int ret = 1;
    if (a[i-1] < a[i]){
        ret += 1 + helper(i-2) + i - 1;
    }else{
        if (a[i-2] > a[i-1]){
            ret += i + helper(i-1);
        }else if (a[i-2] < a[i]){
            ret += i + helper(i-1);
        }else{
            ret += 2 + helper(i-2) + i-1;
        }
    }

    return dp[i] = ret;
}

void solve(){
    
    int n;
    cin >> n;
    a.resize(n);
    rep(i, n) cin >> a[i];
    dp.assign(n+1, -1);

    int ans = 0;
    for (int i=n-1;i>=0;i--){
        ans += helper(i);
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