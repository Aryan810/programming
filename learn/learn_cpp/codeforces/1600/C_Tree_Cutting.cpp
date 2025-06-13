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
vector<vector<int> > graph;
vector<int> visited;
int leaf;

int dfs(int v, int & mid, int & total){
    visited[v] = 1;
    int sm = 1;
    for (auto ele: graph[v]){
        if (!visited[ele]){
            sm += dfs(ele, mid, total);
        }
    }
    // cout << v << "  -  " << total << endl;
    if (sm >= mid){
        total += 1;
        return 0;
    }else{
        return sm;
    }
}

bool check(int mid, int k, int n){
    int total = 0;
    // cout << "MID: " << mid << endl;
    visited.clear();
    visited.resize(n+1);
    int sm = dfs(leaf, mid, total);
    if (sm >= mid){
        total += 1;
    }
    // cout << mid << " " << total << endl;
    if (total >= k+1){
        return 1;
    }else{
        return 0;
    }
}

void solve(){

    int n, k;cin >> n >> k;
    graph.clear();
    graph.resize(n+1);

    for (int i=0;i<(n-1);i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    leaf = 1;
    for (int i=1;i<=n;i++){
        if (graph[i].size() == 1){
            leaf = i;break;
        }
    }

    int l = 1;
    int h = n/(k+1);

    while (h - l > 1){
        int mid = (h+l)/2;
        if (check(mid, k, n)){
            l = mid;
        }else{
            h = mid-1;
        }
    }

    if (check(h, k, n)){
        cout << h << endl;
    }else{
        cout << l << endl;
    }

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