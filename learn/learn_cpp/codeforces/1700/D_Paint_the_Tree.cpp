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
vi vis;

int dfs(int v, int & b){
    vis[v] = 1;
    int dis = -1;
    for (auto & ele: graph[v]){
        if (!vis[ele]){
            dis = max(dis, dfs(ele, b));
        }
    }
    if (v == b){
        return 0;
    }
    if (dis == -1){
        return dis;
    }else{
        return dis + 1;
    }
}

int dfs1(int v, int & b, int & req, int h){
    vis[v] = 1;
    int dis = -1;
    for (auto & ele: graph[v]){
        if (!vis[ele]){
            dis = max(dis, dfs1(ele, b, req, h));
            if (dis == h && req == -1){
                req = ele;
            }
        }
    }

    if (v == b){
        return 0;
    }
    if (dis == -1){
        return dis;
    }else{
        return dis + 1;
    }
}

int bfs(int v, int & n){
    vis.assign(n+1, 0);
    queue<int> q;
    q.push(v);
    vi lev(n+1, 0);
    int mxlev = 0;
    while (q.size() > 0){
        auto curr = q.front();
        vis[curr] = 1;
        q.pop();
        for (auto & ele: graph[curr]){
            if (!vis[ele]){
                lev[ele] = lev[curr] + 1;
                mxlev = max(mxlev, lev[ele]);
                q.push(ele);
            }
        }
    }
    return mxlev + 2 * (n-1-mxlev);
}

void solve(){
    
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;

    graph.clear();
    graph.resize(n+1);
    vis.clear();
    vis.assign(n+1, 0);
    for (int i=0;i<(n-1);i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int dis = dfs(a, b);
    vis.assign(n+1, 0);
    int req = -1;
    dfs1(a, b, req, (dis + 1)/2);
    if (req == -1){
        req = a;
    }
    int ans = (dis + 1)/2;
    int tmp = bfs(req, n);
    ans += tmp;
    cout << ans << endl;




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