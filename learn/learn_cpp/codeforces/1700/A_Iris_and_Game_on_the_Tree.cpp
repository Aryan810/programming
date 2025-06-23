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
vector<vector<int> > graph;
vector<int> vis;
vector<int> leafs;

void dfs(int v){
    vis[v] = 1;
    int ch = 0;
    for (auto ele: graph[v]){
        if (!vis[ele]){
            ch += 1;
            dfs(ele);
        }
    }
    if (ch == 0){
        leafs.push_back(v);
    }
}

void solve(){
    
    int n;
    cin >> n;
    graph.clear();
    graph.resize(n+1);
    vis.clear();
    vis.assign(n+1, 0);
    leafs.clear();
    rep(i, n-1){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    string s;
    cin >> s;
    dfs(1);
    int unkl = 0;
    int unkt = 0;
    for (int i=0;i<n;i++){
        if (s[i] == '?'){
            unkt += 1;
        }
    }
    int one = 0;
    int zero = 0;
    for (auto ele: leafs){
        if (s[ele-1] == '?'){
            unkl += 1;
        }else if (s[ele-1] == '1'){
            one += 1;
        }else{
            zero += 1;
        }
    }
    if (s[0] == '?'){
        // cout << "HERE" << endl;
        // cout << unkl << " " << leafs[0] << endl;
        if (one != zero){cout << (max(one, zero) + (unkl)/2) << endl;}else{
            if ((unkt-1-unkl)&1){
                cout << one + (unkl+1)/2 << endl;
            }else{
                cout << one + (unkl)/2 << endl;
            }
        }
    }else{
        int old = 0;
        if (s[0] == '1'){
            old += zero;
        }else{
            old += one;
        }
        cout << (unkl+1)/2 + old << endl;
    }



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