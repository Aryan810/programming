// #include<atcoder/modint>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;
// using mint = modint;
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define each(x, a) for (auto &x : a)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pi pair<int, int>
#define p(a, b) pair<a, b>
#define vi vector<int>
#define vii vector<int>::iterator
#define vvi vector<vector<int> >
#define vv(x) vector<vector<x> >
#define PRECISION(x) cout << fixed << setprecision(x);
#define mnv(v) *min_element(v.begin(), v.end())
#define mxv(v) *max_element(v.begin(), v.end())
#define umap(x, y) unordered_map<x, y, custom_hash>
const int mod7 = 1e9 + 7;
const int mod9 = 998244353;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key
vector<vector<int> > graph;
vi vis;
void dfs(int v, bool d, vector<pair<int, int> > & out){
    vis[v] = 1;
    for (auto & ele: graph[v]){
        if (!vis[ele]){
            if (d){
                out.push_back({ele, v});
            }else{
                out.push_back({v, ele});
            }
            dfs(ele, 1 - d, out);
        }
    }
}

void solve(){
    int n;
    cin >> n;

    graph.clear();
    graph.resize(n+1);
    vis.assign(n+1, 0);
    vector<pair<int, int> > out;
    for (int i=0;i<n-1;i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bool found = 0;

    int x;
    int c1, c2;
    for (int i=1;i<=n;i++){
        if (graph[i].size() == 2){
            x = i;
            found = 1;
            break;
        }
    }

    if (!found){
        cout << "NO" << endl;return;
    }
    vis[x] = 1;
    out.push_back({x, graph[x][0]});
    out.push_back({graph[x][1], x});
    dfs(graph[x][0], 1, out);
    dfs(graph[x][1], 0, out);
    cout << "YES" << endl;
    for (auto & ele: out){
        cout << ele.first << " " << ele.second << endl;
    }
}

signed main(){
    fast_io;   
    // mint::set_mod(M);
    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}