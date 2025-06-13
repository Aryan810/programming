#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator
#define umap(x, y) unordered_map<x, y, custom_hash>

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
vector<int> out;
vector<int> visited;
vector<vector<int> > graph;
vi a;

void dfs(int v, int pval, int ppval){
    if (visited[v]){
        return;
    }
    visited[v] = 1;
    int val_p = 0;
    for (int i=0;i<graph[v].size();i++){
        if (visited[graph[v][i]]){
            val_p = a[graph[v][i]-1];
            break;
        }
    }
    out[v] = max(a[v-1], a[v-1] + ppval - val_p);
    for (auto child: graph[v]){
        dfs(child, out[v], pval);
    }
}

void solve(){

    int n;
    cin >> n;
    a.clear();
    a.resize(n);
    rep(i, n) cin >> a[i];
    out.clear();
    out.resize(n+1);
    visited.clear();
    visited.resize(n+1);
    graph.clear();
    graph.resize(n+1);
    for (int i=0;i<(n-1);i++){
        int u, v;cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, 0, 0);
    for (int i=1;i<=n;i++){
        cout << out[i] << " ";
    }cout << endl;


}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}