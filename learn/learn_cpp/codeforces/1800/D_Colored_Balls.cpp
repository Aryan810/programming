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
const int M = 998244353;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

int dp[5001][5001];

void solve(){
    
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    sort(all(a));
    dp[0][a[0]] = 1;
    dp[0][0] = 1;
    int ans = 0;
    for (int i=1;i<n;i++){
        for (int j=0;j<5001;j++){
            int tmp = dp[i-1][j];
            tmp %= M;
            if (j >= a[i]){
                tmp += dp[i-1][j-a[i]];
                tmp %= M;
            }
            
            dp[i][j] = tmp;
        }
    }
    // for (int i=0;i<n;i++){
    //     for (int j=0;j<10;j++){
    //         cout << dp[i][j] << " ";
    //     }cout << endl;
    // }
    for (int j=0;j<5001;j++){
        ans += dp[n-1][j] * ((j+1)/2);
        ans %= M;
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<5001;j++){
            if (a[i] > j){
                ans += (a[i] - (a[i] + j + 1)/2)*(dp[n-1][j]);
                ans %= M;
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