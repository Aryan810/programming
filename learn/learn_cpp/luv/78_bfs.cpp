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

void bfs(int v, int n){
    vector<int> visited(n+1, 0);
    queue<int> flow;
    flow.push(v);
    while (flow.size() > 0){
        int curr = flow.front();
        cout << curr << " ";
        visited[curr] = 1;
        for (auto child: graph[curr]){
            if (!visited[child]){
                flow.push(child);
            }
        }
        flow.pop();
    }
    cout << endl;
}

void solve(){

    int n;
    cin >> n;
    int m;
    cin >> m;

    graph.clear();
    graph.resize(n+1);

    for (int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bfs(1, n);
    

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


        solve();

    
    return 0;
}