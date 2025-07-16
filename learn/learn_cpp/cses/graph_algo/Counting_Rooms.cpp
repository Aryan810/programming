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
void dfs(int i, int j, pi par, vvi & grid, vvi & vis, int & n, int & m){
    vis[i][j] = 1;
    vector<pi> poss = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };
    for (auto & ele: poss){
        pi nxt = {ele.first + i, ele.second + j};
        if ((nxt.first >= 0 && nxt.first < n) && ((nxt.second >= 0 && nxt.second < m) && (!grid[nxt.first][nxt.second]))){
            if (!vis[nxt.first][nxt.second]){
                dfs(nxt.first, nxt.second, {i, j}, grid, vis, n, m);
            }
        }
    }
}
 
void solve(){
    
    int n, m;
    cin >> n >> m;
    vvi vis(n+1, vector<int>(m+1, 0));
    vvi grid(n+1, vector<int>(m+1, 1));
 
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            char c;
            cin >> c;
            if (c == '#'){
                grid[i][j] = 1;
            }else{
                grid[i][j] = 0;
            }
        }
    }
    int ans = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (!vis[i][j] && !grid[i][j]){
                dfs(i, j, {-1, -1}, grid, vis, n, m);
                ans += 1;
            }
        }
    }
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