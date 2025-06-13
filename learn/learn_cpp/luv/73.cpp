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

vector<int> h;
vector<int> d;
vector<vector<int> > graph;
vector<int> visited;
vector<int> subTreeSum;
vector<int> noOfEvenInSubTree;
void dfs(int v, int p_depth){
    if (visited[v]){return;}
    visited[v] = 1;
    d[v] = p_depth + 1;
    bool childfound = 0;
    int ret = v;
    int evens = (v%2 == 0);
    for (int i=0;i<graph[v].size();i++){
        if (!visited[graph[v][i]]){
            dfs(graph[v][i], d[v]);
            ret += subTreeSum[graph[v][i]];
            evens += noOfEvenInSubTree[graph[v][i]];
            h[v] = max(h[v], h[graph[v][i]] + 1ll);
            childfound = 1;
        }
    }
    subTreeSum[v] = ret;
    noOfEvenInSubTree[v] = evens;
    if (!childfound){
        h[v] = 0;
    }
}

void solve(){

    int n, m;
    cin >> n >> m;
    graph.clear();
    graph.resize(n+1);
    visited.clear();
    visited.resize(n+1);
    subTreeSum.clear();
    subTreeSum.resize(n+1);
    noOfEvenInSubTree.clear();
    noOfEvenInSubTree.resize(n+1);
    for (int i=0;i<m;i++){
        int u, v;cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    h.clear();d.clear();h.resize(n+1);d.resize(n+1);

    dfs(1, -1);

    // for (int i=1;i<=n;i++){
    //     cout << "I: " << i << " => " << "Depth: " << d[i] << " " << "Height: " << h[i] << endl;
    // }
    for (int i=1;i<=n;i++){
        cout << "I: " << i << " => " << "Sum: " << subTreeSum[i] << " " << "Evens: " << noOfEvenInSubTree[i] << endl;
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


        solve();


    return 0;
}