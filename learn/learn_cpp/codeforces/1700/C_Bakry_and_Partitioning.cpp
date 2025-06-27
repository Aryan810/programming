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
vector<int> vis;
int edfs(int v, bool & poss, vi & a, int & tot){
    vis[v] = 1;
    int ret;
    if (v != 0){
        ret = a[v-1];
    }else{
        ret = 0;
    }
    for (auto & ele: graph[v]){
        if (!vis[ele]){
            ret = ret ^ edfs(ele, poss, a, tot);
        }
    }

    if (tot ^ ret == ret){
        poss = 1;
    }
    return ret;
}

int odfs(int v, vi & a, int & tot, int & seg){
    vis[v] = 1;
    int ret;
    if (v != 0){
        ret = a[v-1];
    }else{
        ret = 0;
    }
    for (auto & ele: graph[v]){
        if (!vis[ele]){
            ret = ret ^ odfs(ele, a, tot, seg);
        }
    }
    if (v > 1 && (seg < 3 && ret == tot)){
        seg += 1;
        ret = 0;
    }
    return ret;
}


void solve(){
    
    int n, k;
    cin >> n >> k;
    vi a(n);
    int axor = 0;
    graph.clear();
    vis.clear();
    vis.assign(n+1, 0);
    graph.resize(n+1);
    rep(i, n){
        int x;
        cin >> x;
        axor = axor ^ x;
        a[i] = x;
    }
    graph[0].push_back(1);
    graph[1].push_back(0);

    for (int i=0;i<(n-1);i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    // case of even
    if (axor == 0){
        bool poss = 0;
        edfs(0, poss, a, axor);
        if (poss){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        return;
    }

    // case of odd
    if (k == 2){
        cout << "NO" << endl;return;
    }
    int seg = 1;
    int ret = odfs(0, a, axor, seg);
    if (seg == 3){
        if (ret == axor){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }else{
        cout << "NO" << endl;
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