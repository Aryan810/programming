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
const int M = 1e9 + 7;
const int mod9 = 998244353;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

#ifdef LOCAL
#include "/Users/aryangupta/Documents/programming/templets/algo/debug.h"
#else
#define debug(...) 42
#endif

vvi graph;
vi vis;
vi subtreesum;
vi val;
int n;
int dfs(int v){
    vis[v] = 1;
    int ret = 0;
    vector<int> eles;
    for (auto & ele: graph[v]){
        if (vis[ele]) continue;
        int y = dfs(ele);
        eles.push_back(y);
        ret += y;
    }
    int x = 0;
    int p = n-1;
    for (auto & ele: eles){
        x += ele * (p - ele);
    }
    x += (n-1-ret) * (ret);
    x /= 2;
    x += n-1;
    val[v] = x;
    return ret+1;
}

int binexpiter(int a, int b){
    int ans = 1;
    while (b){
        if (b&1){
            ans = (ans * a)%M;
        }
        a = (a * a)%M;
        b >>= 1;
    }
    return ans;
}

void solve(){
    
    int k;
    cin >> n >> k;
    graph.resize(n+1);
    vis.assign(n+1, 0);
    subtreesum.assign(n+1, 0);
    val.assign(n+1, 0);
    for (int i=0;i<n-1;i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1);

    if (k == 1 || k == 3){
        cout << 1 << endl;return;
    }

    int inv = binexpiter(n, M-2) * binexpiter(n-1, M-2);
    inv %= M;

    int sm = 0;
    for (int i=0;i<n;i++){
        // cout << i+1 << " " <<  val[i+1] << endl;
        sm += val[i+1]%M;
        sm %= M;
    }
    // cout << sm << endl;
    sm *= 2;
    sm %= M;
    sm *= inv;
    sm %= M;

    cout << sm << endl;

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