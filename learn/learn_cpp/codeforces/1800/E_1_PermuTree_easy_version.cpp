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
int dfs(int v, int & ans){
    vis[v] = 1;
    vector<int> coins;
    int tot = 0;
    for (auto & ele: graph[v]){
        if (vis[ele]) continue;
        int res = dfs(ele, ans);
        coins.push_back(res);
        tot += res;
    }
    if (coins.size() <= 1){
        return tot + 1;
    }
    vi sums(tot+1, 0);
    sums[0] = 1;
    int cans = 0;
    for (int i=0;i<coins.size();i++){
        int curr = coins[i];
        auto tmp = sums;
        for (int j=0;j<=tot-curr;j++){
            if (sums[j]){
                tmp[j+curr] = 1;
            }
        }
        sums = tmp;
    }

    for (int i=1;i<tot;i++){
        if (sums[i]){cans = max(cans, i*(tot-i));}
    }
    ans += cans;
    return tot + 1;
}


void solve(){
    
    int n;
    cin >> n;
    graph.resize(n+1);
    vis.assign(n+1, 0);
    for (int i=2;i<=n;i++){
        int x;
        cin >> x;
        int y = i;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }


    int ans = 0;
    dfs(1, ans);

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