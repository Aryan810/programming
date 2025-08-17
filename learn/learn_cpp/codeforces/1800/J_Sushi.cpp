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
double dp[301][301][301];
int vis[301][301][301];
int n;
double helper(int c1, int c2, int c3){
    if (c1 == 0 && (c2 == 0 && c3 == 0)){
        return 0.0;
    }

    if (vis[c1][c2][c3]){
        return dp[c1][c2][c3];
    }

    double ret = n;
    if (c1 > 0){
        ret += ((double)c1*helper(c1-1, c2, c3));
    }
    if (c2 > 0){
        ret += ((double)c2*helper(c1+1, c2-1, c3));
    }
    if (c3 > 0){
        ret += ((double)c3*helper(c1, c2+1, c3-1));
    }
    ret /= double(c1 + c2 + c3);
    vis[c1][c2][c3] = 1;
    return dp[c1][c2][c3] = ret;
}

void solve(){
    
    cin >> n;
    vi E = {0, 0, 0};
    rep(i, 300){
        rep(j, 300){
            rep(k, 300){
                dp[i][j][k] = -1.0;
            }
        }
    }

    dp[0][0][0] = 0.0;
    vi a(n);
    rep(i, n){
        int x;
        cin >> x;
        if (x != 0) E[x-1] += 1;
        a[i] = x;
    }

    printf("%0.10lf\n", helper(E[0], E[1], E[2]));


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