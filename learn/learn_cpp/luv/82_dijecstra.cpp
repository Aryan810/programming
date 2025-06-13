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
#define INF 1e9+7
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
vector<vector<pair<int, int> > > graph;
vector<int> dist;
vector<int> visited;
int dijkstra(int source, int dest){
    set<pair<int, int> > q;
    q.insert({0, source});
    dist[source] = 0;
    while (q.size() > 0){   
        auto curr = *q.begin();
        q.erase(q.begin());
        if (visited[curr.second]){continue;}
        visited[curr.second] = 1;
        for (auto child: graph[curr.second]){
            int d = dist[curr.second] + child.second;
            if (dist[child.first] > d){
                dist[child.first] = d;
                q.insert({d, child.first});
            }
        }
    }
    return dist[dest];
}

// void bfs(int v, int n){
//     vector<int> visited(n+1, 0);
//     queue<int> flow;
//     flow.push(v);
//     while (flow.size() > 0){
//         int curr = flow.front();
//         cout << curr << " ";
//         visited[curr] = 1;
//         for (auto child: graph[curr]){
//             if (!visited[child]){
//                 flow.push(child);
//             }
//         }
//         flow.pop();
//     }
//     cout << endl;
// }

void solve(){

    int n;
    cin >> n;
    int m;
    cin >> m;

    graph.clear();
    graph.resize(n+1);
    dist.clear();
    dist.assign(n+1, INF);
    visited.clear();
    visited.assign(n+1, 0);
    for (int i=0;i<m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    // bfs(1, n);
    int min_dis = dijkstra(1, 5);
    cout << min_dis << endl;
    

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


        solve();

    
    return 0;
}