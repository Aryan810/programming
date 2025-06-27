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
#define vai(x) vector<array<int, x> >
#define vv(x) vector<vector<x> >
#define PRECISION(x) cout << fixed << setprecision(x);
#define mnv(v) *min_element(v.begin(), v.end())
#define mxv(v) *max_element(v.begin(), v.end())
#define umap(x, y) unordered_map<x, y, custom_hash>
const int mod7 = 1e9 + 7;
const int mod9 = 998244353;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key
int dp[200001];
vector<array<int, 3> > a; 

int helper(int i, int & n){
    if (i >= n){
        return 0;
    }
    if (dp[i] != -1){
        return dp[i];
    }

    int ret = 0;
    // taking it.
    auto curr = a[i];
    array<int, 3> ar = {curr[1], (int)1e10, (int)1e10};
    auto nxt = upper_bound(all(a), ar);
    ret = max(ret, curr[2] + helper(nxt-a.begin(), n));
    ret = max(ret, helper(i+1, n));
    return dp[i] = ret;
}

void solve(){
    
    int n;
    cin >> n;
    a.resize(n);
    for (int i=0;i<n;i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    sort(all(a));
    memset(dp, -1, sizeof(dp));

    cout << helper(0, n) << endl;



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