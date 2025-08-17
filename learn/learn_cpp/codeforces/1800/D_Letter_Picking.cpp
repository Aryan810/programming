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

bool helper(int l, int h, string & s, vvi & dp){
    if (l >= h){
        return 1;
    }

    if (dp[l][h] != -1){
        return dp[l][h];
    }

    bool ret = 1;

    if (s[l]==s[h]){
        ret = ret & helper(l+1, h-1, s, dp);
    }else if (s[l+1] == s[l] && s[h] == s[h-1]){
        ret = ret & helper(l+2, h, s, dp);
        ret = ret & helper(l, h-2, s, dp);
    }else{
        ret = 0;
    }

    
    return dp[l][h] = ret;
}

void solve(){
    
    string s;
    cin >> s;
    vector<vector<int> > dp(s.size(), vector<int>(s.size(), -1));
    bool ans = helper(0, s.size()-1, s, dp);

    if (ans){
        cout << "Draw" << endl;
    }else{
        cout << "Alice" << endl;
    }
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