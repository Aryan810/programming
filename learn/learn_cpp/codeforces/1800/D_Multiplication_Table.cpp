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

#ifdef LOCAL
#include "/Users/aryangupta/Documents/programming/templets/algo/debug.h"
#else
#define debug(...) 42
#endif

int check(int mid, int n, int m){
    int bk = 0;
    for (int i=1;i<=min(mid, n);i++){
        bk += min(m, mid/i);
    }
    return bk;
}

void solve(){
    
    int n, m, k;
    cin >> n >> m >> k;

    int l = 1;
    int h = n*m;

    while (h - l > 1){
        int mid = (l + h)/2;
        int bk = check(mid, n, m);
        if (bk >= k){
            h = mid;
        }else{
            l = mid;
        }
    }

    if (check(l, n, m) == k){
        cout << l << endl;
    }else{
        cout << h << endl;
    }

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