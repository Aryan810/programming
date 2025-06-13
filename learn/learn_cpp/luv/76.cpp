#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace __gnu_pbds;
using namespace std;
#define int long long
#define vi vector<int>
#define vii vector<int>::iterator
#define rep(i, n) for(int i=0;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector<vector<int> > graph;
vector<int> visited;
vector<int> d;
int dfs(int v, int n1, int n2, int & lca, int p_dep=(-1)){
    if (visited[v]){return 0;}
    visited[v] = 1;
    int found = 0;
    if (v == n1 || v == n2){
        found = 1;
    }
    d[v] = p_dep + 1;
    for (int i=0;i<graph[v].size();i++){
        found += dfs(graph[v][i], n1, n2, lca, d[v]);
    }
    
    // cout << v << " " << found << endl;
    if (found >= 2){
        if (lca < 1e18){
            if (d[lca] < d[v]){
                lca = v;
            }
        }else{
            lca = v;
        }
    }
    return found;
}

void solve(){

    int n, m;
    cin >> n >> m;
    graph.clear();
    graph.resize(n+1);
    visited.clear();
    visited.resize(n+1);
    d.clear();
    d.resize(n+1);
    for (int i=0;i<m;i++){
        int u, v;cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int n1, n2;cin >> n1 >> n2;
    // cout << "n1: " << n1 << " n2: " << n2 << endl;
    int lca = 1e18;
    dfs(1, n1, n2, lca);
    if (lca < 1e18){
        cout << "LCA: " << lca << endl;
    }else{
        cout << "NOT FOUND !" << endl;
    }


}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


        solve();


    return 0;
}