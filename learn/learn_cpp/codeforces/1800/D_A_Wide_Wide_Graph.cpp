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
vi dp1;
vi dp2;

int dfs1(int v, int p){
    int ret = 0;
    int ch = 0;
    for (auto & ele: graph[v]){
        if (ele == p){continue;}
        ret = max(ret, dfs1(ele, v));
        ch += 1;
    }
    if (ch == 0){
        return dp1[v] = 0;
    }else{
        return dp1[v] = ret + 1;
    }
}

void dfs2(int v, int p, int upval){
    int mx1 = -1, mx2 = -1;
    for (auto & ele: graph[v]){
        if (ele == p){continue;}
        if (dp1[ele] >= mx1){
            mx2 = mx1;
            mx1 = dp1[ele];
        }else if (dp1[ele] >= mx2){
            mx2 = dp1[ele];
        }
    }
    dp2[v] = max(upval, mx1+1);
    for (auto & ele: graph[v]){
        if (ele == p){continue;}
        int x;
        if (dp1[ele] == mx1){
            x = mx2;
        }else{
            x = mx1;
        }
        dfs2(ele, v, 1 + max(upval, 1 + x));
    }
}

void solve(){
    
    int n;
    cin >> n;
    graph.resize(n+1);
    dp1.assign(n+1, 0);
    dp2.assign(n+1, 0);
    for (int i=0;i<n-1;i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs1(1, 0);
    dfs2(1, 0, 0);
    int val = 1;
    map<int, int> cnt;

    for (int i=1;i<=n;i++){
        cnt[dp2[i]] += 1;
    }

    for (int k=1;k<=n;k++){
        val += cnt[k-1];
        cout << min(val, n) << " ";
    }

    cout << endl;


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