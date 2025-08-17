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
    
    int n, q;
    cin >> n >> q;

    vi a(n);
    map<int, vector<int> > ind;
    vi cum(n+1, 0);
    int xo = 0;
    for (int i=0;i<n;i++){
        int x;
        cin >> x;
        xo ^= x;
        cum[i+1] = xo;
        ind[xo].push_back(i+1);
        a[i] = x;
    }

    for (int i=0;i<q;i++){
        int l, r;
        cin >> l >> r;
        int xr = cum[r]^cum[l-1];
        // cout << xr << endl;
        if (xr == 0){
            cout << "YES" << endl;continue;
        }
        // first index till which we get xr as xor.
        auto & a1 = ind[xr^cum[l-1]];
        auto it = lower_bound(all(a1), l);
        if (it == a1.end()){
            cout << "NO" << endl;continue;
        }
        int m1 = *it;
        // cout << m1 << endl;
        if (m1 == r){cout << "NO" << endl;continue;}
        auto & a2 = ind[xr^cum[m1]];
        it = upper_bound(all(a2), m1);
        if (it == a2.end()){
            cout << "NO" << endl;continue;
        }
        int m2 = *it;
        // cout << m2 << endl;
        if (m2 <= r){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
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