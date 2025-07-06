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
int dp[100001][3];

int helper(int i, int lst, vector<array<int, 2> > & dta){
    int n = dta.size();
    if (i >= n){
        return 0;
    }

    if (dp[i][lst] != -1){
        return dp[i][lst];
    }

    int ret = 0;

    // case 1 - not taking this tree down.
    ret = max(ret, helper(i+1, 0, dta));

    // case 2 - down to right.
    if (i == n-1){
        ret = max(ret, 1 + helper(i+1, 2, dta));
    }else if (dta[i][0]+dta[i][1] < dta[i+1][0]){
        ret = max(ret, 1 + helper(i+1, 2, dta));
    }

    // case 3 - down to left.
    if (i == 0){
        ret = max(ret, 1 + helper(i+1, 1, dta));
    }else if (lst == 0 || lst == 1){
        if (dta[i][0]-dta[i][1] > dta[i-1][0]){
            ret = max(ret, 1 + helper(i+1, 1, dta));
        }
    }else{
        if (dta[i][0] - dta[i][1] > dta[i-1][0] + dta[i-1][1]){
            ret = max(ret, 1+helper(i+1, 1, dta));
        }
    }
    return dp[i][lst] = ret;
}

void solve(){
    
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    vector<array<int, 2> > dta(n);
    rep(i, n) cin >> dta[i][0] >> dta[i][1];

    int ans = helper(0, 0, dta);
    cout << ans << endl;


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