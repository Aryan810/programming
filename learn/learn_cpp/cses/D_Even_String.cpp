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
const int mod9 = 1e9 + 7;
const int mod7 = 998244353;
#define M7 mod7
#define M9 mod9
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key
const int N = 5 * (100000) + 1;
vector<int> fact(N, 1);
int binexpiter(int a, int b){
    int ans = 1;
    while (b){
        if (b&1){
            ans = (ans * a)%mod7;
        }
        a = (a * a)%mod7;
        b >>= 1;
    }
    return ans;
}
int calc(int a, int b, vi & num){
    int ans = fact[a] * fact[b];
    ans %= mod7;
    for (int i=0;i<26;i++){
        if (num[i] != 0){ans *= binexpiter(fact[num[i]], mod7-2);ans %= mod7;}
    }
    return ans;
}
int helper(int i, int left, vvi & dp, vi & num){
    if (i >= 26){
        if (left == 0){
            return 1;
        }else{
            return 0;
        }
    }
    if (dp[i][left] != -1){
        return dp[i][left];
    }

    int ret = 0;
    // take this element
    if (num[i] > 0 && num[i] <= left){
        ret += helper(i+1, left - num[i], dp, num);
        ret %= mod7;
    }

    ret += helper(i+1, left, dp, num);
    ret %= mod7;
    return dp[i][left] = ret;
}

void solve(){
    
    vector<int> num(26, 0);
    int sm = 0;
    rep(i, 26){
        int x;
        cin >> x;
        sm += x;
        num[i] = x;
    }
    // cout << sm << endl;
    vvi dp(27, vector<int>(sm+1, -1));
    int a = sm/2;
    int b = sm - a;

    int ways = helper(0, a, dp, num);
    int mult = calc(a, b, num);
    int ans = mult * ways;

    ans %= mod7;
    cout << ans << endl;

}

signed main(){
    fast_io;   
    // mint::set_mod(M);

    for (int i=2;i<N;i++){
        fact[i] = fact[i-1] * i;
        fact[i] %= mod7;
    }

    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}