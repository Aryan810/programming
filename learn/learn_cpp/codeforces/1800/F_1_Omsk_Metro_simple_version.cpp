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
    vector<array<array<int, 2> , 2> > a(n+10);
    
    a[1][0] = {1ll, 1ll};
    a[1][1] = {0ll, 0ll};
    int done = 1;
    for (int i=0;i<n;i++){
        char c;
        cin >> c;
        if (c == '+'){
            int v, x;
            cin >> v >> x;
            int nw = ++done;
            auto par = a[v];
            auto & y = a[nw];
            if (x == 1){
                y[0][1] = par[0][1] + 1;
                y[0][0] = max(par[0][0], y[0][1]);

                y[1][1] = min(0ll, par[1][1] + 1);
                y[1][0] = min(par[1][0], y[1][1]);
            }else{
                y[0][1] = max(0ll, par[0][1] - 1);
                y[0][0] = max(par[0][0], y[0][1]);

                y[1][1] = min(0ll, par[1][1] - 1);
                y[1][0] = min(par[1][0], y[1][1]);
            }
        }else{
            int u, v, k;
            cin >> u >> v >> k;
            if (k >= a[v][1][0] && k <= a[v][0][0]){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }

    // show(a[5]);

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