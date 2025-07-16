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

void solve(){
    
    int n, m, k;
    cin >> n >> m >> k;

    vvi grid(n, vector<int>(m));
    rep(i, n){
        rep(j, m){
            cin >> grid[i][j];
        }
    }
    vvi cum(n+1, vector<int>(m+1, 0));
    int so = 0;
    int sz = 0;
    vvi typ(n, vector<int>(m));
    rep(i, n){
        rep(j, m){
            char c;
            cin >> c;
            cum[i+1][j+1] = cum[i+1][j] + cum[i][j+1] - cum[i][j] + (c-'0');
            if ((c-'0')){
                so += grid[i][j];
            }else{
                sz += grid[i][j];
            }
        }
    }
    int gc = 0;
    for (int i=0;i<=(n-k);i++){
        for (int j=0;j<=(m-k);j++){
            int sumone = cum[i+k][j+k] - cum[i][j+k] - cum[i+k][j] + cum[i][j];
            int sumzero = k*k -  sumone;
            int diff = abs(sumone-sumzero);
            gc = gcd(diff, gc);
        }
    }
    int dif = abs(so-sz);
    if (dif == 0 || (gc != 0 && dif%gc == 0)){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
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