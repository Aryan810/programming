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
vvi graph;
void dfs(int v, int cons, int mxcons, vi & a, int & m, int & ans){
    vis[v] = 1;
    if (a[v-1] == 1){
        cons += 1;
    }else{
        cons = 0;
    }
    // cout << v << " " << cons << endl;

    mxcons = max(cons, mxcons);
    for (auto & ele: graph[v]){
        if (!vis[ele]){
            dfs(ele, cons, mxcons, a, m, ans);
        }
    }

    if (v != 1 && graph[v].size() == 1){
        if (mxcons <= m){
            ans += 1;
        }
    }


}

void solve(){
    int n, m;
    cin >> n >> m;

    graph.clear();
    graph.resize(n+1);
    vis.clear();
    vis.resize(n+1);
    vis.assign(n+1, 0);
    vi a(n);
    rep(i, n) cin >> a[i];
    for (int i=0;i<n-1;i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int ans = 0;
    dfs(1, 0, 0, a, m, ans);
    cout << ans << endl;

    

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