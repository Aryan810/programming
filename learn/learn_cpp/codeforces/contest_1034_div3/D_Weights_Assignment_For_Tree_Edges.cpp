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
// #define p(a, b) pair<a, b>
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
vi dis;


void solve(){
    
    int n;
    cin >> n;
    dis.clear();
    dis.assign(n+1, -1);
    graph.clear();
    graph.resize(n+1);
    vi b(n);
    rep(i, n) cin >> b[i];
    int rt = -1;
    for (int i=0;i<n;i++){
        if (b[i] == i+1){
            rt = i+1;
        }else{
            graph[i+1].push_back(b[i]);
            graph[b[i]].push_back(i+1);
        }
    }
    dis[rt] = 0;
    vi p(n);
    rep(i, n) cin >> p[i];
    int dep = 0;
    vi w(n, 0);
    if (p[0] != rt){
        cout << -1 << endl;return;
    }
    for (int i=1;i<n;i++){
        int last = dis[b[p[i]-1]];
        if (last == -1){
            cout << -1 << endl;return;
        }
        w[p[i]-1] = dep + 1 - last;
        dep += 1;
        dis[p[i]] = dep;
    }

    for (auto & ele: w){
        cout << ele << " ";
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