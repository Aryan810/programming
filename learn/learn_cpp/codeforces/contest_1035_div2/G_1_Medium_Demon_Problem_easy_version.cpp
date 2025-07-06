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
vvi graph1;
vi vis;
void dfs1(int v, int & loop){
    vis[v] = 1;
    for (auto & ele: graph[v]){
        if (vis[ele]){
            loop = ele;
        }
        if (!vis[ele]){
            dfs1(ele, loop);
        }
    }
}

void dfs2(int v, set<int> & q){
    q.insert(v);
    vis[v] = 1;
    for (auto & ele: graph[v]){
        if (!vis[ele]){
            dfs2(ele, q);
        }
    }
}
vi vis1;
void dfs3(int v){
    vis1[v] = 1;
    vis[v] = 1;
    for (auto & ele: graph1[v]){
        if (!vis1[ele]){
            dfs3(ele);
        }
    }
}

int bfs(int & n){
    queue<int> q;
    set<int> loopparts; 
    set<int> lp;
    vis1.clear();
    vis1.assign(n+1, 0);
    for (int i=1;i<=n;i++){
        int loop = -1;
        if (!vis[i]){
            dfs1(i, loop);
            if (loop != -1){
                loopparts.insert(loop);
                dfs3(i);
            }
        }
    }
    vis.assign(n+1, 0);
    for (auto & ele: loopparts){
        dfs2(ele, lp);
    }
    vi lev(n+1, 0);
    for (auto & ele: lp){
        q.push(ele);
    }
    while (q.size() > 0){
        int curr = q.front();q.pop();
        vis[curr] = 1;
        for (auto & ele: graph1[curr]){
            if (!vis[ele]){
                lev[ele] = lev[curr] + 1;
                q.push(ele);
            }
        }
    }

    return mxv(lev) + 2;
}

void solve(){
    
    int n;
    cin >> n;
    graph.clear();
    graph.resize(n+1);
    graph1.clear();
    graph1.resize(n+1);
    vis.clear();
    vis.assign(n+1, 0);
    vi a(n);
    rep(i, n){
        int x;
        cin >> x;
        graph[i+1].push_back(x);
        graph1[i+1].push_back(x);
        graph1[x].push_back(i+1);
    }
    int ans = bfs(n);
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