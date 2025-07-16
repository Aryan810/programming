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
vi a, b;
vvi graph;
vi vb;
vi vis;
vi ans;
int sb = 0;
void dfs(int v, int sa){
    vis[v] = 1;
    // cout << v << " " << sa << " " << sb << endl;
    if (sb != 0){vb.push_back(sb);}
    ans[v] = upper_bound(all(vb), sa) - vb.begin();
    for (auto & ele: graph[v]){
        if (!vis[ele]){
            sb += b[ele];
            dfs(ele, sa + a[ele]);
            sb -= b[ele];
        }
    }
    if (sb != 0){vb.pop_back();}
}

void solve(){
    
    int n;
    cin >> n;
    a.assign(n+1, 0);
    b.assign(n+1, 0);
    vis.assign(n+1, 0);
    ans.assign(n+1, 0);
    graph.clear();
    graph.resize(n+1);
    for (int i=1;i<(n);i++){
        int p, x, y;
        cin >> p >> x >> y;
        a[i+1] = x;
        b[i+1] = y;
        // cout << p << " " << i+1 << endl; 
        graph[p].push_back(i+1);
        graph[i+1].push_back(p);
    }

    dfs(1, 0);

    for (int i=2;i<=n;i++){
        cout << ans[i] << " ";
    }cout << endl;




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