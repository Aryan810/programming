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
int binexpiter(int a, int b){
    int ans = 1;
    while (b){
        if (b&1){
            ans = ans * a;
        }
        a = a * a;
        b >>= 1;
    }
    return ans;
}
int helper(int ind, int g, int b, int & n, vi & cum, vi & a, int h){
    if (ind >= n){
        return 0;
    }
    int ret = 0;
    int x = h;
    if (h > a[ind]){
        return helper(ind+1, g, b, n, cum, a, h+a[ind]/2) + 1;
    }
    for (int i=0;i<=g;i++){
        for (int j=0;j<=b;j++){
            if (i == 0 && j == 0){continue;}
            if (x*(binexpiter(2, i)*(binexpiter(3, j))) > a[ind]){
                int tmp = x*(binexpiter(2, i)*(binexpiter(3, j)));
                ret = max(ret, helper(ind+1, g-i, b-j, n, cum, a, tmp + a[ind]/2) + 1);
            }
        }
    }
    return ret;
}

void solve(){
    
    int n, h;
    cin >> n >> h;

    vi a(n);
    vi cum(n+1, 0);
    cum[0] = 0;
    int sm = 0;
    rep(i, n){
        int x;
        cin >> x;
        a[i] = x;
    }
    // index, green, blue.
    int dp[n+1][3][2];
    sort(all(a));
    for (int i=0;i<n;i++){
        sm += a[i]/2;
        cum[i+1] = sm;
    }
    memset(dp, -1, sizeof(dp));
    // for (auto & ele: cum){
    //     cout << ele << " ";
    // }cout << endl;
    int ans = helper(0, 2, 1, n, cum, a, h);
    cout << ans << endl;



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