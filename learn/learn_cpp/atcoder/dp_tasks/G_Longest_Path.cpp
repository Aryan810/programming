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
vector<vi> graph;
int dp[100002];

int helper(int v){
    if (graph[v].size() == 0){
        return 0;
    }
    if (dp[v] != -1){
        return dp[v];
    }

    int ret = 0;
    
    for (auto & ele: graph[v]){
        ret = max(ret, 1 + helper(ele));
    }
    return dp[v] = ret;
}

void solve(){
    int n, m;
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    graph.resize(n+1);
    for (int i=0;i<m;i++){
        int x, y, w;
        cin >> x >> y;
        graph[x].push_back(y);
    }

    for (int i=1;i<=n;i++){
        if (dp[i] == -1){
            helper(i);
        }
    }

    int ans = 0;
    for (int i=1;i<=n;i++){
        ans = max(ans, dp[i]);
    }

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