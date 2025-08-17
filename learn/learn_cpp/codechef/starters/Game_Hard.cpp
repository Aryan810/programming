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
    sort(rall(a));
    vi cum(n+1);
    cum[0] = 0;
    for (int i=0;i<n;i++){
        cum[i+1] = cum[i] + a[i];
    }

    int mk = 1;
    int sm = 0;
    int tot = 0;
    for (int i=0;i<n;i++){
        tot += i;
        sm += a[0];
        if (cum[min(n, 2*(i+1))]-cum[i+1] <= tot){
            mk = i+1;
            break;
        }
    }
    tot = 0;
    for (int i=mk+1;i<=2*mk;i++){
        int ext = i - mk - 1;
        tot += 2*mk - i;
        if (cum[(min(n, mk + ext + 1))] - cum[mk] <= tot){
            mk = i;
            break;
        }
    }
    vi cum1(n+1, 0);
    for (int i=0;i<n-1;i++){
        cum1[i+1] = cum1[i] + a[i+1] - 3*(i+1);
    }
    vi b(n, 0);
    for (int i=0;i<n-1;i++){
        b[i] = a[i+1] - 3*(i+1);
    }

    for (int k=1;k<=2*n;k++){
        int mx = (k + 1)/2;
        int mnans = cum[mx] - cum[0];
        // cout << mnans << endl;
        auto it = lower_bound(b.rbegin(), b.rend() - mx + 1, 2 - 2 * k);
        int ind = min(k, min((int)(b.rend() - it + 1ll), n));
        // cout << ind << " ";
        int s1 = cum[ind]-cum[0];

        int lft = min(k - ind, ind);
        int s2 = (lft*(2*ind - 1 - lft))/2;
        cout << s1 + s2 << " ";
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