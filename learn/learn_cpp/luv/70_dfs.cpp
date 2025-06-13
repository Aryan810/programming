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
const int N = 1e5 + 10;
vector<int> graph[N];
bool visited[N];
bool dfs(int v, int parent){
    visited[v] = 1;
    // cout << v << endl;
    // left.erase(v);
    // after entering the node - the action on vertex
    bool ret = 0;
    for (int i=0;i<graph[v].size();i++){
        if (!visited[graph[v][i]]){
            // action before entering the node
            ret = ret | dfs(graph[v][i], v);
            // action on child after leaving the node
        }else{
            if (parent != -1 && graph[v][i] != parent){
                return 1;
            }
        }
    }
    return ret;
    // action on vertex before leanving it
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i=0;i<m;i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    // set<int> left;
    // for (int i=1;i<=n;i++){
    //     left.insert(i);
    // }
    // int cc = 0;
    // while (left.size() > 0){
    //     cc += 1;
    //     dfs(*left.begin(), left);
    // }
    // cout << cc << endl;

    // does cycles exists ?
    for (int i=1;i<=n;i++){
        if (!visited[i]){cout << dfs(1, -1) << endl;}
    }
    return 0;
}