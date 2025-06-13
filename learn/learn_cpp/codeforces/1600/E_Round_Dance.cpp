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
bool loop_exists = 0;
void dfs(int v, vector<set<int> > & graph, vector<bool> & visited, int parent){
    visited[v] = 1;
    // cout << v << endl;
    for (auto child: graph[v]){
        if (!visited[child]){
            dfs(child, graph, visited, v);
        }else{
            if (parent != -1 && child != parent){
                loop_exists = 1;
            }
        }
    }
}   

void solve(){
    int n;
    cin >> n;
    vector<set<int> > graph(n+1);
    bool morethan3 = 0;
    for (int i=1;i<=n;i++){
        int x;
        cin >> x;
        graph[i].insert(x);
        graph[x].insert(i);
        // cout << "HERE" << endl;
        if (graph[i].size() >= 3){
            morethan3 = 1;
        }
    }
    if (morethan3){
        cout << "0 0" << endl;return;
    }

    vector<bool> visited(n+1, 0);
    int loops = 0;
    int other = 0;
    for (int i=1;i<=n;i++){
        if (!visited[i]){
            loop_exists = 0;
            dfs(i, graph, visited, -1);
            if (loop_exists){
                loops += 1;
            }else{
                other += 1;
            }
        }
    }

    cout << (loops + min(1ll, other)) << " " << (loops + other) << endl;


    

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