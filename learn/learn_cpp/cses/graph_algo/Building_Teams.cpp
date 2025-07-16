// #include<atcoder/modint>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
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
vi out;
vi vis;
void dfs(int v, bool & poss){
    vis[v] = 1;
    for (auto & ele: graph[v]){
        if (!vis[ele]){
            if (out[ele] == out[v]){
                poss = 0;
            }else{
                out[ele] = ((out[v] == 1)?2:1);
                dfs(ele, poss);
            }
        }
    }
}

void solve(){
    
    int n, m;
    cin >> n >> m;
    graph.clear();
    out.assign(n+1, -1);
    graph.resize(n+1);
    vis.assign(n+1, 0);

    for (int i=0;i<m;i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    bool poss = 1;
    for (int i=1;i<=n;i++){
        if (!vis[i]){
            out[i] = 1;
            dfs(i, poss);
        }
    }
    for (int i=1;i<=n;i++){
        for (auto & ele: graph[i]){
            if (out[ele] == out[i]){
                poss = 0;
                break;
            }
        }
        if (!poss){
            break;
        }
    }
    if (!poss){
        cout << "IMPOSSIBLE" << endl;
    }else{
        for (int i=1;i<=n;i++){
            cout << out[i] << " ";
        }cout << endl;
    }
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