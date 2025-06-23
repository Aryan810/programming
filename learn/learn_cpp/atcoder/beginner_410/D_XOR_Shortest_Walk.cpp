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
vector<pair<int, int> > graph[1001][1024];
int vis[1001][1024];

void dfs(int v, int s){
    vis[v][s] = 1;
    // cout << v << " " << s << endl; 
    // cout << graph[v][s].size() << endl;
    for (auto &ele: graph[v][s]){
        if (!vis[ele.first][ele.second]){
            dfs(ele.first, ele.second);
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    for (int i=0;i<m;i++){
        int a, b, w;
        cin >> a >> b >> w;
        // cout << a << " " << b << endl;
        for (int j=0;j<1024;j++){
            graph[a][j].push_back({b, j^(w)});
        }
    }

    dfs(1, 0);

    for (int i=0;i<1024;i++){
        if (vis[n][i]){
            cout << i << endl;return;
        }
    }
    cout << -1 << endl;return;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // mint::set_mod(M);
    int test = 1;
    while(test--){
        solve();
    }

    return 0;
}