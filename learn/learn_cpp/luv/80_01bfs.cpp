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
vector<vector<pair<int, int> > > graph;
#define INF 1e9+7
vector<int> level;

void bfs(int v, int n){
    // vector<int> visited(n+1, 0);
    deque<int> flow;
    flow.push_back(v);
    while (flow.size() > 0){
        int curr = flow.front();
        flow.pop_front();
        cout << curr << " ";
        // visited[curr] = 1;
        for (auto child: graph[curr]){
            if (level[curr] + child.second < level[child.first]){
                if (child.second > 0){
                    flow.push_back(child.first);
                    level[child.first] = level[curr] + 1;
                }else{
                    flow.push_front(child.first);
                    level[child.first] = level[curr];
                }
            }
        }
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
    level.clear();
    level.assign(n+1, INF);
    for (int i=0;i<m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    level[1] = 0;
    bfs(1, n);
    for (auto ele: level){
        cout << ele << " ";
    }cout << endl;

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


        solve();

    
    return 0;
}