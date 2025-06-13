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
#define INF 1e9+7
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
const int N = 2*(1e3)+10;
int parent[N];
int sz[N];
vector<int> c;
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

// int cost = 0;

// pair<int, int> dfs(int v){
//     visited[v] = 1;
//     pair<int, int> ret = {c[v], v};
//     int parentWt = 0;
//     for (int i=0;i<minTree[v].size();i++){
//         if (!visited[minTree[v][i].second]){
//             ret = minf(ret, dfs(minTree[v][i].second));
//         }else{
//             parentWt = minTree[v][i].first;
//         }
//     }
//     if (parentWt > ret.first){
//         plants.push_back(ret.second);
//         ret.first = INF;
//         ret.second = -1;
//     }
//     return ret;

// }

void solve(){

    int n;
    cin >> n;
    vector<pair<int, int> > nodes(n);
    rep(i, n) cin >> nodes[i].first >> nodes[i].second;

    c.clear();
    c.resize(n);
    rep(i, n) cin >> c[i];

    vector<int> k(n);
    rep(i, n) cin >> k[i];
    if (n == 1){
        cout << c[0] << endl;
        cout << "1\n1\n0" << endl;
        return;
    }
    vector<array<int, 3> > graph;
    for (int i=1;i<=(n-1);i++){
        for (int j=(i+1);j<=n;j++){
            graph.push_back({(abs(nodes[i-1].first-nodes[j-1].first) + abs(nodes[i-1].second - nodes[j-1].second))*(k[i-1]+k[j-1]), i, j});
        }
    }
    for (int i=1;i<=n;i++){
        graph.push_back({c[i-1], 0, i});
    }
    sort(all(graph));
    for (int i=0;i<=n;i++){
        make(i);
    }
    int cost = 0;
    vector<array<int, 3> > mytree;
    vector<int> plants(n+1);
    for (int i=0;i<graph.size();i++){
        auto curr = graph[i];
        if (find(curr[1]) != find(curr[2])){
            int p = find(curr[1]);
            int q = find(curr[2]);
            Union(curr[1], curr[2]);  
            cost += curr[0];
            if (curr[1] == 0){
                plants[curr[2]] = 1;
            }else{
                mytree.push_back(curr);
            }
        }
    }
    // here we got the minimum spanning tree.
    cout << cost << endl;
    vector<int> out;
    for (int i=1;i<plants.size();i++){
        if (plants[i]){
            out.push_back(i);
        }
    }
    cout << out.size() << endl;
    for (auto ele: out){
        cout << ele << " ";
    }cout << endl;
    cout << mytree.size() << endl;
    for (int i=0;i<mytree.size();i++){
        cout << mytree[i][1] << " " << mytree[i][2] << endl;
    }







}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}