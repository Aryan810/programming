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
    
    int n, k;
    cin >> n >> k;
    if (n <= 61 && k > (1ll<<(n-1))){
        cout << -1 << endl;return;
    }
    // cout << log2(k) << endl;
    vi out(n);
    for (int i=1;i<=n;i++){
        out[i-1] = i;
    }
    int skips = 0;
    int i = 0;
    while (n-i > 61){
        i += 1;
    }
    // cout << (1ll<<(n-i-1)) << endl;
    if (n-i <= 61 && k > (1ll<<(n-1-i))){
        cout << -1 << endl;return;
    }
    while (i < n && n-i > 1){
        int sz = n-i;
        int st = out[i];
        int val = 1ll<<(sz-2);
        int inc = 0;
        // cout << k << " " << val << " " << sz << endl;
        while (k > val){
            // cout << k << " " << val << endl;
            inc += 1;
            st += 1;
            k -= val;
            if (val > 1){val /= 2;}
        }
        out[i++] = st--;
        while (inc--){
            out[i++] = st--;
        }
    }

    for (auto & ele: out){
        cout << ele << " ";
    }cout << endl;

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