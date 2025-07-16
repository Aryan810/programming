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

int calc(int l, int r, vi & a, int & n, vi & cum, int & tot){
    int csl = 1 + (l-1)/n;
    int csr = 1 + (r-1)/n;
    
    int csb = n - (n - csr + csl - 1) - 2;
    int ans = csb * tot;
    l -= n*(csl - 1);
    r -= n*(csr - 1);
    if (csr == csl){
        int st1;
        int st2;
        if (l > n-csl+1){
            st1 = l - (n - csl + 1);
        }else{
            st1 = csl + l - 1;
        }
        if (r > n-csr+1){
            st2 = r - (n - csr + 1);
        }else{
            st2 = csr + r - 1;
        }
        if (l > n-csl+1 && r > n-csr+1){
            return cum[st2]-cum[st1-1];
        }else if (r > n-csl+1){
            return tot - (cum[csl-1]-cum[st2] + cum[st1-1]-cum[csl-1]);
        }else{
            return cum[st2]-cum[st1-1];
        }
    }
    int sr = 0;
    int sl = 0;
    // finding left sum;
    if (l > n-csl+1){
        sl += cum[csl-1] - cum[csl - n + l - 2];
    }else{
        int st = csl;
        sl += tot - cum[csl + l - 2] + cum[csl - 1];
    }
    // finding right sum
    if (r > n-csr+1){
        sr += tot - cum[csr-1] + cum[csr - n + r - 1];
    }else{
        int st = csr;
        sr += cum[r + st - 1] - cum[st-1];
    }
    ans += sr + sl;
    // cout << sl << " " << sr << endl;
    return ans;
}

void solve(){
    
    int n, q;
    cin >> n >> q;

    vi a(n);
    rep(i, n) cin >> a[i];
    vi cum(n+1, 0);
    cum[0] = 0;
    int tot = 0;
    for (int i=0;i<n;i++){
        tot += a[i];
        cum[i+1] = tot;
    }
    for (int i=0;i<q;i++){
        int l, r;
        cin >> l >> r;
        cout << calc(l, r, a, n, cum, tot) << endl;   
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