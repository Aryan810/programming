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

int dp[101][4];
string l, r;

int helper(int i, int t){
    if (i >= l.size()){
        return 0;
    }
    if (t == 0 || t == 1){
        return dp[i][t] = 9 * (l.size()-i);
    }

    if (dp[i][t] != -1){
        return dp[i][t];
    }

    int ret = 0;

    if (t == 2){
        ret = max(ret, helper(i+1, 2)+r[i]-'0');
        if (r[i] > '0'){ret = max(ret, helper(i+1, 0)+r[i]-'1');}
    }else{
        if (l[i]==r[i]){
            ret = max(ret, helper(i+1, 3) + r[i]-'0');
        }else{
            ret = max(ret, helper(i+1, 2) + r[i]-'0');
            if (r[i]-l[i]==1){
                ret = max(ret, helper(i+1, 1) + r[i]-'1');
            }else{
                ret = max(ret, helper(i+1, 0) + r[i]-'1');
            }
        }
    }
    return dp[i][t] = ret;
}

void solve(){
    
    
    cin >> l >> r;
    while (l.size() < r.size()){
        l.insert(l.begin(), '0');
    }
    memset(dp, -1, sizeof(dp));
    cout << helper(0, 3) << endl;
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
