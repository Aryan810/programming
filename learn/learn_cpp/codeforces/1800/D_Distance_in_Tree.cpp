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
vvi graph;
int ans = 0;
int n, k;
vi vis;
vvi dp;

void dfs(int v){
    vis[v] = 1;
    vi sm(k+1, 0);
    sm[0] = 1;
    int j = 0;
    int par = -1;
    for (auto & ele: graph[v]){
        if (vis[ele]){par = ele;continue;}
        dfs(ele);
        for (int i=1;i<=k;i++){
            sm[i] += dp[ele][i-1];
        }
        j += 1;
    }


    int tmp = 0;
    // cout << "V: " << v << endl;
    for (auto & ele: graph[v]){
        if (ele == par){continue;}
        // for (auto & e: dp[ele]){
        //     cout << e << " ";
        // }cout << endl;
        for (int i=1;i<=(k-1)/2;i++){
            // cout << "DP: " << dp[ele][k-i-1] << " " << k-i-1 << endl;
            tmp += dp[ele][k-i-1] * (sm[i] - dp[ele][i-1]);
        }
    }
    if (k%2 == 0){
        int x = 0;
        for (auto & ele: graph[v]){
            if (ele == par){continue;}
            tmp += (dp[ele][k/2-1]) * (sm[k/2]-x-dp[ele][k/2-1]);
            x += dp[ele][k/2 - 1];
        }
    }
    tmp += sm[k];
    ans += tmp;
    // cout << v << " " << tmp << " " << par << endl;
    // for (auto & ele: sm){
    //     cout << ele << " ";
    // }cout << endl;
    dp[v] = sm;
}

void solve(){
    cin >> n >> k;
    vis.assign(n+1, 0);
    graph.resize(n+1);
    dp.assign(n+1, vector<int>(k+1, 0));
    for (int i=0;i<n-1;i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfs(1);
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