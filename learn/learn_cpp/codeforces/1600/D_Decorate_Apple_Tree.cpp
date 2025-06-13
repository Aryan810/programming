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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// DSU
const int N = 1e5+10;
int parent[N];
int sz[N];

void make(int v){
    parent[v] = v;
    sz[v] = 1;
}

int find(int v){
    if (v == parent[v]){return v;}
    return parent[v] = find(parent[v]);
}

void Union(int i, int j){
    int p = find(i);
    int q = find(j);
    if (p != q){
        if (sz[p] > sz[q]){
            parent[q] = p;
            sz[p] += sz[q];
        }else{
            parent[p] = q;
            sz[q] += sz[p];
        }
    }
}
vector<int> visited;
vector<vector<int> > graph;
vector<int> num;
int leafs = 0;
int dfs(int v){
    visited[v] = 1;
    int ret = 0;
    int childs = 0;
    for (int i=0;i<graph[v].size();i++){
        if (!visited[graph[v][i]]){
            ret += dfs(graph[v][i]);
            childs += 1;
        }
    }
    if (childs == 0){
        ret += 1;
        leafs += 1;
    }
    num[ret] += 1;
    return ret;
}

void solve(){

    int n;cin >> n;

    visited.clear();
    visited.resize(n+1);
    graph.clear();
    graph.resize(n+1);
    num.clear();
    num.resize(n+1);
    for (int i=2;i<=n;i++){
        int x;
        cin >> x;
        graph[x].push_back(i);
        graph[i].push_back(x);
    }

    dfs(1);

    int sm = 0;
    vector<int> nm(leafs+1);
    for (int i=1;i<=leafs;i++){
        sm += num[i];
        nm[i] = sm;
    }
    // for (auto ele: num){
    //     cout << ele << " ";
    // }cout << endl;
    int curr = 1;
    for (int i=1;i<=leafs;i++){
        int x = nm[i];
        while (curr <= n && curr <= x){
            cout << i << " ";curr++;
        }
        if (curr > n){break;}
    }

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int test;
    // cin >> test;

    // while(test--){
        solve();
    // }

    return 0;
}