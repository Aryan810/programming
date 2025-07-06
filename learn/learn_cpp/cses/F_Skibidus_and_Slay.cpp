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
vvi graph;
vi vis;
void dfs(int v, string & out, vi & a){
    vis[v] = 1;
    set<int> done;
    for (auto & ele: graph[v]){
        if (out[a[ele-1]-1] == '0' && a[ele-1] == a[v-1]){
            out[a[ele-1]-1] = '1';
        }
        if (out[a[ele-1]-1] == '0' && done.find(a[ele-1]) != done.end()){
            out[a[ele-1]-1] = '1';
        }
        done.insert(a[ele-1]);
        if (!vis[ele]){
            dfs(ele, out, a);
        }
    }
}

void solve(){
    
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    graph.clear();
    graph.resize(n+1);
    for (int i=0;i<(n-1);i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vis.clear();
    vis.assign(n+1, 0);
    string out(n, '0');
    dfs(1, out, a);
    cout << out << endl;


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