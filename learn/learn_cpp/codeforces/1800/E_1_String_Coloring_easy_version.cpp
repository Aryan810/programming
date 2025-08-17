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

int dp[201][27][27];
string s;
int n;
int helper(int i, char l1, char l2){
    if (i >= n){
        return 1;
    }
    if (dp[i][l1-'a'][l2-'a'] != -1){
        return dp[i][l1-'a'][l2-'a'];
    }

    int ret = 0;
    if (s[i] >= l1){
        if (s[i] >= l2){
            ret |= helper(i+1, l1, s[i]);
        }
        ret |= helper(i+1, s[i], l2);
    }else{
        if (s[i] >= l2){
            ret |= helper(i+1, l1, s[i]);
        }
    }

    return dp[i][l1-'a'][l2-'a'] = ret;
}


void solve(){
    cin >> n;
    cin >> s;
    memset(dp, -1, sizeof(dp));
    int poss = helper(0, 'a', 'a');
    if (!poss){
        cout << "NO" << endl;return;
    }
    vector<int> out(n);
    char l1 = 'a';
    char l2 = 'a';
    cout << "YES" << endl;
    for (int i=0;i<n;i++){
        if (s[i] >= l1){
            if (s[i] >= l2){
                if (helper(i+1, l1, s[i])){
                    out[i] = 0;
                    l2 = s[i];
                    continue;
                }
            }
            if (helper(i+1, s[i], l2)){
                out[i] = 1;
                l1 = s[i];
                continue;
            }
        }else{
            if (s[i] >= l2){
                if (helper(i+1, l1, s[i])){
                    out[i] = 0;
                    l2 = s[i];
                    continue;
                }
            }
        }
    }

    for (int i=0;i<n;i++){
        cout << out[i];
    }cout << endl;

}

signed main(){
    fast_io;   
    // mint::set_mod(M);
    int test=1;

    while(test--){
        solve();
    }

    return 0;
}