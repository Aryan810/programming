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
vi vis;
void dfs(int v, vi & conn){
    conn.push_back(v);
    vis[v] = 1;
    for (auto & ele: graph[v]){
        if (!vis[ele]){
            dfs(ele, conn);
        }
    }
}
void solve(){
    
    int n;
    cin >> n;
    graph.clear();
    graph.resize(n+1);
    vis.assign(n+1, 0);
    vi a(n);
    rep(i, n){
        int x;
        cin >> x;
        graph[i+1].push_back(x);
        a[i] = x;
    }
    bool found = 0;
    int ans = 0;
    for (int i=1;i<=n;i++){
        if (!vis[i]){
            vi conn;
            dfs(i, conn);
            sort(all(conn));
            ans += conn.size() - 1;
            for (int i=0;i<conn.size()-1;i++){
                if (conn[i+1]-conn[i] == 1){
                    found = 1;
                    break;
                }
            }
        }
    }
    if (found){
        ans -= 1;
    }else{
        ans += 1;
    }
    cout << ans << endl;


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