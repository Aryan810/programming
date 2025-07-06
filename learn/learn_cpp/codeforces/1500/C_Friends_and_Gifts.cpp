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
vi vis;

void dfs(int v, int & l, int & h, set<int> & wgive, set<int> & wtake, vvi & graph){
    vis[v] = 1;
    if (wgive.find(v) != wgive.end()){
        h = v;
    }
    if (wtake.find(v) != wtake.end()){
        l = v;
    }
    for (auto & ele: graph[v]){
        if (!vis[ele]){
            dfs(ele, l, h, wgive, wtake, graph);
        }
    }
}

void solve(){
    
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    vis.clear();
    vis.assign(n+1, 0);
    vvi graph(n+1);
    set<int> wgive;
    set<int> wtake;
    for (int i=0;i<n;i++){
        if (a[i] != 0){
            graph[a[i]].push_back(i+1);
            graph[i+1].push_back(a[i]);
        }
        if (a[i] == 0){
            wgive.insert(i+1);
        }
    }

    for (int i=1;i<=n;i++){
        if (graph[i].size() == 1){
            if (wgive.find(i) == wgive.end()){
                wtake.insert(i);
            }
        }else if (graph[i].size() == 0){
            wtake.insert(i);
        }
    }
    // for (auto & ele: wgive){
    //     cout << ele << " ";
    // }cout << endl;

    // for (auto & ele: wtake){
    //     cout << ele << " ";
    // }cout << endl;
    vector<pair<int, int> > out;
    for (int i=1;i<=n;i++){
        if (!vis[i]){
            int l = -1;
            int h = -1;
            dfs(i, l, h, wgive, wtake, graph);
            if (l != -1 && h != -1){out.push_back({l, h});}
        }
    }

    for (int i=0;i<(out.size()-1);i++){
        a[out[i].second-1] = out[i+1].first;
    }

    a[out[out.size()-1].second-1] = out[0].first;

    for (auto & ele: a){
        cout << ele << " ";
    }cout << endl;

}

signed main(){
    fast_io;   
    // mint::set_mod(M);
    int test = 1;
    while(test--){
        solve();
    }

    return 0;
}