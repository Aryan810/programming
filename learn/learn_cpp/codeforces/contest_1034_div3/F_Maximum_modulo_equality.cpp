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
#define mne(v) *min_element(v.begin(), v.end())
#define mxe(v) *max_element(v.begin(), v.end())
#define umap(x, y) unordered_map<x, y, custom_hash>
const int mod7 = 1e9 + 7;
const int mod9 = 998244353;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

void solve(){
    
    int n, q;
    cin >> n >> q;
    int mx = log2(n);
    vi a(n);
    rep(i, n)cin >> a[i];
    vi b(n-1);
    for (int i=0;i<(n-1);i++){
        b[i] = abs(a[i+1] - a[i]);
    }
    vvi stable(n, vector<int>(mx+1, 0));
    int gape = 1;
    for (int i=0;i<n-1;i++){
        stable[i][0] = b[i];
    }
    int m = n-1;
    while ((1ll << gape) <= m){
        int val = (1ll << gape);
        for (int i=0;i<=(m-val);i++){
            int f = i;
            int l = i + val/2;
            stable[i][gape] = gcd(stable[f][gape-1], stable[l][gape-1]);
        }
        gape += 1;
    }
    // for (auto & ele: stable){
    //     for (auto & e: ele){
    //         cout << e << " ";
    //     }cout << endl;
    // }
    for (int i=0;i<q;i++){
        int l, r;
        cin >> l >> r;
        if (l == r){
            cout << 0 << " ";
        }else{
            int f = l-1;
            int s = r-2;
            int sz = s - f + 1;
            int p = log2(sz);
            int l = s - (1ll<<p) + 1;
            int ans = gcd(stable[f][p], stable[l][p]);
            cout << ans << " ";
        }
    }
    cout << endl;

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