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
    
    int n;
    cin >> n;

    vi a(n);
    rep(i, n) cin >> a[i];

    vi b(n+1);
    rep(i, n+1) cin >> b[i];
    int lst = b[n];

    bool btw = 0;
    int ind = -1;
    int ans = 0;
    int mxx = 0;

    int mnn = 1e18;
    pi mgape = {1e18, -1};
    for (int i=0;i<n;i++){
        int mn = min(a[i], b[i]);
        int mx = max(a[i], b[i]);
        mxx = max(mxx, mx);
        mnn = min(mn, mnn);
        ans += mx - mn;
        if (lst >= mn && lst <= mx){
            btw = 1;
            ind = i;
            continue;
        }
        if (lst > mx){
            if (mgape.first > lst-mx){
                mgape = {lst-mx, mx};
            }
        }else{
            if (mgape.first > mn-lst){
                mgape = {mn-lst, mn};
            }
        }
    }

    if (btw){
        cout << ans + 1 << endl;return;
    }


    cout << ans + mgape.first + 1 << endl;


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