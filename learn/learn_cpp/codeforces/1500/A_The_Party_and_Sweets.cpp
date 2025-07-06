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
    
    int n, m;
    cin >> n >> m;
    vi b(n), g(m);
    rep(i, n) cin >> b[i];
    rep(i, m) cin >> g[i];

    int mxb = mxv(b);
    int mng = mnv(g);
    
    if (mng < mxb){
        cout << -1 << endl;return;
    }

    int ans = 0;
    int smg = accumulate(all(g), 0ll);
    ans += smg; 
    
    sort(rall(b));
    bool left = 0;
    for (int i=0;i<n;i++){
        if (i == 0){
            if (find(all(g), b[i]) == g.end()){
                left = 1;
                ans += b[i];
            }
        }else{
            if (left){
                ans += (m-1)*b[i];
                left = 0;
            }else{
                ans += m*b[i];
            }
        }
    }
    cout << ans << endl;
    

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