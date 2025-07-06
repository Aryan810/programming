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
void solve(){
    vector<int> odddiv;
    int n;
    cin >> n;
    vi a(n);
    int xr = 0;
    int mx = log2(n);
    mx += 1;
    mx = (1ll << mx);
    for (int i=0;i*i<mx;i++){
        odddiv.push_back(i*i);
    }
    vector<int> cnt(mx, 0);
    vi cum(n+1, 0);
    cum[0] = 0;
    rep(i, n){
        int x;
        cin >> x;
        xr = x ^ xr;
        cum[i+1] = xr;
        cnt[xr] += 1;
        a[i] = x;
    }
    int withodd = 0;
    for (int j=0;j<odddiv.size();j++){
        auto tcnt = cnt;
        for (int i=0;i<n;i++){
            int prev = cum[i];
            int req = prev ^ odddiv[j];
            if (req < mx){
                withodd += tcnt[req];
                tcnt[cum[i+1]] -= 1;
            }
        }
    }
    int y = n;
    y *= n+1;
    y /= 2;

    cout << (y - withodd) << endl;
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