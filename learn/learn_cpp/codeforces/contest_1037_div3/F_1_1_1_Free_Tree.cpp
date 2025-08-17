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
vector<vector<pi> > graph;
vi vis;
vi par;
vi parwt;
void dfs(int v, map<pi, int> & sums, vi & a){
    vis[v] = 1;
    for (auto & ele: graph[v]){
        if (!vis[ele.first]){
            sums[{v, a[ele.first-1]}] += ele.second;
            par[ele.first] = v;
            parwt[ele.first] = ele.second;
            dfs(ele.first, sums, a);
        }
    }


}

void solve(){
    
    int n, q;
    cin >> n >> q;
    graph.clear();
    graph.resize(n+1);
    par.assign(n+1, 0);
    vis.assign(n+1, 0);
    parwt.assign(n+1, 0);
    vi a(n);
    rep(i, n) cin >> a[i];
    int ans = 0;
    for (int i=0;i<n-1;i++){
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back({y, w});
        graph[y].push_back({x, w});
        if (a[x-1]!=a[y-1]){
            ans += w;
        }
    }
    map<pi, int> sums;
    dfs(1, sums, a);

    for (int i=0;i<q;i++){
        int v, x;
        cin >> v >> x;
        if (a[v-1] == x){
            cout << ans << endl;
            continue;
        }
        int s1 = 0;
        if (sums.find({v, x}) != sums.end()){s1 = sums[{v, x}];}
        int s2 = 0;
        if (sums.find({v, a[v-1]}) != sums.end()){s2 = sums[{v, a[v-1]}];}
        if (v != 1){
            if (a[par[v]-1] == x){
                s1 += parwt[v];
            }else if (a[par[v]-1] == a[v-1]){
                s2 += parwt[v];
            }
            // cout << "Sum: " << sums[{par[v], a[v-1]}] << " " << parwt[v] << endl;
            sums[{par[v], a[v-1]}] -= parwt[v];
            sums[{par[v], x}] += parwt[v];
        }
        // cout << s1 << " " << s2 << endl;
        ans -= s1;
        ans += s2;
        cout << ans << endl;
        a[v-1] = x;
    }

    // for (auto & ele: sums){
    //     cout << ele.first.first << " " << ele.first.second << " -> " << ele.second << endl;
    // }




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