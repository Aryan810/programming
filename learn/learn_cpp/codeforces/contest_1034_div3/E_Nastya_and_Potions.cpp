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
vvi graph;

int helper(int v, vi & c, vi & dp){
    if (dp[v] != -1){
        return dp[v];
    }
    if (graph[v].size() == 0){
        return dp[v] = c[v-1];
    }
    int ret = 1e18;
    int t1 = 0;
    for (auto & ele: graph[v]){
        t1 += helper(ele, c, dp);
    }
    ret = min(c[v-1], t1);
    return dp[v] = ret;
}

void solve(){
    
    int n, k;
    cin >> n >> k;
    vi c(n);
    rep(i, n) cin >> c[i];
    vi p(k);
    graph.clear();
    graph.resize(n+1);
    vector<int> dp(n+1, -1);
    rep(i, k){
        int x;
        cin >> x;
        c[x-1] = 0;
        p[i] = x;
    }


    for (int i=0;i<n;i++){
        int m;
        cin >> m;
        for (int j=0;j<m;j++){
            int x;
            cin >> x;
            graph[i+1].push_back(x);
        }
    }

    for (int i=1;i<=n;i++){
        if (dp[i] != -1){
            cout << dp[i] << " ";
        }else{
            cout << helper(i, c, dp) << " ";
        }
    }
    cout << endl;
    







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