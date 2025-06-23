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

void solve(){
    
    int n, m;
    cin >> n >> m;
    vvi graph(n+1);
    vector<vector<int> > edges(n+1, vector<int>(n+1, -1));
    for (int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        edges[u][v] = i;
        edges[v][u] = i;
    }
    bool complete = 1;
    int v = -1;
    for (int i=1;i<=n;i++){
        if (graph[i].size() < n-1){
            complete = 0;
            v = i;
            break;
        }
    }
    
    if (!complete){
        cout << 2 << endl;
        vector<int> out(m, -1);
        for (auto & ele: graph[v]){
            out[edges[ele][v]] = 1;
        }
        
        for (auto & ele: out){
            if (ele != -1){cout << ele << " ";}else{
                cout << 2 << " ";
            }
        }cout << endl;return;
    }
    v = 1;
    vector<int> out(m, -1);
    int v1 = graph[v][0];
    int v2 = graph[v][1];
    // cout << "here" << endl;
    for (int i=1;i<=n;i++){
        if (i != v){

            if (i != v1){out[edges[i][v1]] = 3;}
            if (i != v2){out[edges[i][v2]] = 3;}
        }
    }

    out[edges[v][v1]] = 2;
    out[edges[v][v2]] = 1;
    cout << 3 << endl;
    for (auto & ele: out){
        if (ele == -1){
            cout << 1 << " ";
        }else{
            cout << ele << " ";
        }
    }cout << endl;
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