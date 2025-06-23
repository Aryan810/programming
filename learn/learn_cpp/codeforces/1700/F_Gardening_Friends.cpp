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
#define vvi vector<vector<int> >
const int M = 1e9 + 7;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key
vvi graph;

int bfs(int & n, int & k, int & c){
    queue<int> q;
    vi vis(n+1, 0);
    vi lev(n+1, 0);
    q.push(1);
    int mxdis = 0;
    int mxnode = 0;
    while (q.size() > 0){
        int curr = q.front();q.pop();
        vis[curr] = 1;
        for (auto & ele: graph[curr]){
            if (!vis[ele]){
                lev[ele] = lev[curr] + 1;
                if (lev[ele] > mxdis){
                    mxdis = max(mxdis, lev[ele]);
                    mxnode = ele;
                }
                q.push(ele);
            }
        }
    }

    q.push(mxnode);
    vis.assign(n+1, 0);
    vi lev2(n+1, 0);
    int ans = mxdis*k;
    while (q.size() > 0){
        int curr = q.front();q.pop();
        // cout << curr << " " << lev2[curr]<< endl;
        ans = max(ans, k*lev2[curr] - lev[curr]*c);
        vis[curr] = 1;
        for (auto & ele: graph[curr]){
            if (!vis[ele]){
                lev2[ele] = lev2[curr] + 1;
                q.push(ele);
            }
        }
    }
    return ans;
}

void solve(){
    
    int n, k, c;
    cin >> n >> k >> c;
    graph.clear();
    graph.resize(n+1);
    for (int i=0;i<(n-1);i++){
        int u, v;
        cin >> u >> v;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    cout << bfs(n, k, c) << endl;
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