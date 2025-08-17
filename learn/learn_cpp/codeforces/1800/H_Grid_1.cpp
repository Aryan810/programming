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
vector<string> grid;
int dp[1002][1002];
vector<pi> poss = {
    {1, 0}, {0, 1}
};


void solve(){
    
    int n, m;
    cin >> n >> m;
    grid.resize(n+1);
    for (int i=0;i<n;i++){
        string s;
        cin >> s;
        grid[i] = s;
    }
    for (int i=n-1;i>=0;i--){
        for (int j=m-1;j>=0;j--){
            if (grid[i][j]=='#'){continue;}
            if (i == n-1 && j == m-1){
                dp[i][j] = 1;continue;
            }
            int tmp = 0;
            for (auto & ele: poss){
                pi nxt = {ele.first + i, ele.second + j};
                if (((nxt.first >= 0 && nxt.first < n) && (nxt.second >= 0 && nxt.second < m)) && grid[nxt.first][nxt.second] != '#'){
                    tmp += dp[nxt.first][nxt.second];
                    tmp %= M;
                }
            }
            dp[i][j] = tmp;
        }
    }
    cout << dp[0][0] << endl;

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