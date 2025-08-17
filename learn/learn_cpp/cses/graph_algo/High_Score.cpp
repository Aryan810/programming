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
const int INF = 1e15;

void dfs(int v, vvi & graph, vi & vis){
    vis[v] = 1;
    for (auto & ele: graph[v]){
        if (!vis[ele]){
            dfs(ele, graph, vis);
        }
    }
}

void solve(){
    
    int n, m;
    cin >> n >> m;
    vvi graph(n+1);
    vvi graph1(n+1);
    vi vis(n+1, 0);
    vi vis1(n+1, 0);
    vector<array<int, 3> > edges(m);
    for (int i=0;i<m;i++){
        int x, y;
        cin >> x >> y;
        int w;cin >> w;
        graph[x].push_back(y);
        graph1[y].push_back(x);
        edges[i] = {x, y, -1*w};
    }

    vi lev(n+1, INF);
    lev[1] = 0;
    dfs(1, graph, vis);
    dfs(n, graph1, vis1);
    bool poss = 1;

    for (int i=0;i<n;i++){
        poss = 1;
        for (auto & ele: edges){
            int u, v, wt;
            u = ele[0];v = ele[1];wt = ele[2];
            if (vis[u] && vis1[v] && (lev[u]+wt < lev[v])){
                poss = 0;
                lev[v] = lev[u] + wt;
            }
        }
    }
    
    if (!poss){
        cout << -1 << endl;return;
    }

    cout << -1 * lev[n] << endl;


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