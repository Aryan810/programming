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
vvi graph;
vector<int> sts;
vector<int> vis;
int calcsts(int v){
    vis[v] = 1;
    int ret = 1;
    for (auto & ele: graph[v]){
        if (!vis[ele]){
            ret += calcsts(ele);
        }
    }
    sts[v] = ret;
    return ret;
}

void dfs(int v, bool & is2c, int & p, int & q, int & tot){
    vis[v] = 1;
    for (auto & ele: graph[v]){
        if (!vis[ele]){
            int f = sts[ele];
            int s = tot - sts[ele];
            if (f == s){
                is2c = true;
                p = v;
                q = ele;
            }
            dfs(ele, is2c, p, q, tot);
        }
    }
}

void dfs1(int v, pi & edg){
    vis[v] = 1;
    int ch = 0;
    int c = -1;
    for (auto & ele: graph[v]){
        ch += 1;
        c = ele;
        if (!vis[ele]){
            dfs1(ele, edg);
        }
    }
    if (ch == 1){
        edg = {c, v};
    }

}

void solve(){
    
    int n;
    cin >> n;
    graph.clear();
    graph.resize(n+1);
    sts.clear();
    sts.resize(n+1);
    sts.assign(n+1, 0);
    vis.clear();
    vis.resize(n+1);
    for (int i=0;i<n-1;i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vis.assign(n+1, 0);
    int tot = calcsts(1);
    vis.assign(n+1, 0);
    int p = -1;
    int q = -1;
    bool is2c = 0;
    dfs(1, is2c, p, q, tot);
    if (!is2c){
        cout << 1 << " " << graph[1][0] << endl;
        cout << 1 << " " << graph[1][0] << endl;return;
    }
    // cout << "HERE" << endl;
    vis.assign(n+1, 0);
    vis[p] = 1;
    pair<int, int> edg = {-1, -1};
    dfs1(q, edg);

    cout << edg.first << " " << edg.second << endl;
    cout << p << " " << edg.second << endl;
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