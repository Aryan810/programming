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
const int M = 998244353;

vector<vector<int> > graph;
vector<int> level;
vector<int> vis;   
vector<int> parents;
void dfs(int v){
    vis[v] = 1;
    for (auto ele: graph[v]){
        if (!vis[ele]){
            level[ele] = level[v] + 1;
            dfs(ele);
        }
    }
}

// int helper(int v, vector<int> & dp){
//     if (dp[v] != -1){
//         return dp[v];
//     }
//     if (v != 1 && lev[level[v]+1].size() == 0){
//         return 1;
//     }
//     int ret = 1;
//     int l = level[v];
//     for (auto ele: lev[l+1]){
//         if (graph[v].find(ele) == graph[v].end()){
//             ret = (ret + helper(ele, dp))%M;
//         }
//     }
//     return dp[v] = ret;
// }


void solve(){
    int n;
    cin >> n;

    graph.clear();
    graph.resize(n+1);
    vis.clear();
    vis.assign(n+1, 0);
    level.clear();
    level.assign(n+2, 0);
    level[1] = 0;
    parents.clear();
    parents.resize(n+1);
    parents[1] = -1;

    vector<int> dp(n+1, 0);
    vector<vector<int> > lev(n+1);
    for (int i=2;i<=n;i++){
        int x;
        cin >> x;
        graph[x].push_back(i);
        graph[i].push_back(x);
    }
    dfs(1);
    int lastLevel = 0;
    for (int i=1;i<=n;i++){
        lev[level[i]].push_back(i);
        lastLevel = max(level[i], lastLevel);
    }
    int sm = 0;
    for (int i=lastLevel;i>=1;i--){
        int s = 0;
        for (auto ele: lev[i]){
            dp[ele] = (sm+1)%M;
            for (auto child: graph[ele]){
                dp[ele] = (dp[ele] - dp[child] + M)%M;
            }
            s += dp[ele];
            s %= M;
        }
        sm = s;
    }
    cout << (sm + 1)%M << endl;
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