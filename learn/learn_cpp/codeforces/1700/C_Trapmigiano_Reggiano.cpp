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

struct dsu{
    int n;
    vector<int> parent, set_size;
    dsu(int n){
        this->n = n;

        parent.resize(n);

        set_size.resize(n);

        for (int i = 0; i < n; i++){

            parent[i] = i;

            set_size[i] = 1;
        }
    }
    int find(int v){
        if(v == parent[v]) return v;
        return parent [v] = find (parent [v]);
    }
    void set_union (int a, int b){
        a = find(a);
        b = find (b);
        if(a != b){
            if(set_size[a] < set_size [b]){
                swap (a, b) ;
            }
            parent[b] = a;
            set_size[a] += set_size[b];
        }   
    }
};

vector<vector<int> > graph;
vector<int> subtreesum;
vector<int> visited;
int dfs1(int v, int en){
    visited[v] = 1;
    int child = 0;
    int ret = (v == en)?1:0;
    for (auto ele: graph[v]){
        if (!visited[ele]){
            ret += dfs1(ele, en); 
        }
    }
    subtreesum[v] = ret;
    return ret;
}

void dfs2(int v, vector<int> & out){
    visited[v] = 1;
    int tovisit = -1;
    for (auto ele: graph[v]){
        if (!visited[ele]){
            if (subtreesum[ele] > 0){
                tovisit = ele;
            }else{
                dfs2(ele, out);
            }
        }
    }
    if (tovisit != -1){
        dfs2(tovisit, out);
    }
    out.push_back(v);
}

void solve(){

    int n, st, en;
    cin >> n >> st >> en;
    
    //clear the graph
    graph.clear();
    graph.resize(n+1);
    subtreesum.clear();
    subtreesum.resize(n+1);
    visited.clear();
    visited.assign(n+1, 0);

    for (int i=0;i<(n-1);i++){
        int u, v;
        cin >> u >> v;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    dfs1(st, en);
    visited.clear();
    visited.assign(n+1, 0);
    vector<int> out;
    dfs2(en, out);
    // cout << st << " ";
    for (auto ele: out){
        cout << ele << " ";
    }cout << endl;




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