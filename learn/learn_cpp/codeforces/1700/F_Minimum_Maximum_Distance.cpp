// #include<atcoder/modint>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;
// using mint = modint;
#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator
#define umap(x, y) unordered_map<x, y, custom_hash>
const int M = 1e9 + 7;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key
vector<vector<int> > graph;
int bfs(int v, vector<int> & a, int & n){
    queue<int> q;
    q.push(v);
    vector<int> lev(n+1, 0);
    vector<int> vis(n+1, 0);
    while (q.size() > 0){
        auto curr = q.front();q.pop();
        // lev[curr[0]] = max(lev[curr[0]], curr[2]);
        // int from = curr[1];
        vis[curr] = 1;
        for (auto & ele: graph[curr]){
            if (!vis[ele]){
                lev[ele] = lev[curr] + 1;
                q.push(ele);
            }
        }
    }
    int mx = 0;
    int node = 0;
    for (auto & ele: a){
        if (mx < lev[ele]){
            mx = lev[ele];
            node = ele;
        }
    }

    q.push(node);
    lev.assign(n+1, 0);
    vis.assign(n+1, 0);
    while (q.size() > 0){
        auto curr = q.front();q.pop();
        // lev[curr[0]] = max(lev[curr[0]], curr[2]);
        // int from = curr[1];
        vis[curr] = 1;
        for (auto & ele: graph[curr]){
            if (!vis[ele]){
                lev[ele] = lev[curr] + 1;
                q.push(ele);
            }
        }
    }
    
    mx = 0;
    for (auto & ele: a){
        if (mx < lev[ele]){
            mx = lev[ele];
            node = ele;
        }
    }
    
    return (mx+1)/2;
}

void solve(){
    
    int n, k;
    cin >> n >> k;
    vi a(k);
    rep(i, k) cin >> a[i];
    graph.clear();
    graph.resize(n+1);
    for (int i=0;i<(n-1);i++){
        int u, v;
        cin >> u >> v;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    cout << bfs(a[0], a, n) << endl;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // mint::set_mod(M);
    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}