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

vector<vector<pi> > graph;
vector<int> vis;
vector<int> xdis;
set<int> xdiss;

void cxdis(int v){
    vis[v] = 1;
    for (auto & ele: graph[v]){
        if (!vis[ele.first]){
            xdis[ele.first] = xdis[v] ^ ele.second;
            // cout << ele.first << " " << xdis[ele.first] << endl;
            xdiss.insert(xdis[ele.first]);
            cxdis(ele.first);
        }
    }
}

vector<int> axdis;

void dfs(int v, bool & poss){
    if (xdiss.find(axdis[v]) != xdiss.end()){
        poss = 1;
    }
    vis[v] = 1;
    for (auto & ele: graph[v]){
        if (!vis[ele.first]){
            axdis[ele.first] = axdis[v] ^ ele.second;
            dfs(ele.first, poss);
        }
    }
}

void solve(){
    
    int n, a, b;
    cin >> n >> a >> b;

    graph.clear();
    graph.resize(n+1);

    vis.clear();
    vis.assign(n+1, 0);
    // cout << vis.size() << endl;
    xdiss.clear();
    xdis.clear();
    xdis.assign(n+1, 0);
    axdis.clear();
    axdis.assign(n+1, 0);
    for (int i=0;i<(n-1);i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    cxdis(b);
    vis.assign(n+1, 0);
    // for (auto & ele: xdiss){
    //     cout << ele << " ";
    // }cout << endl;
    vis[b] = 1;
    bool poss = 0;
    dfs(a, poss);

    if (poss){
        cout << "YES" << endl;return;
    }else{
        cout << "NO" << endl;return;
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