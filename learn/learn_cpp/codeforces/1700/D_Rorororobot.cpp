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
    
    int n, m;
    cin >> n >> m;

    vi a(m);
    rep(i, m) cin >> a[i];

    int q;
    cin >> q;

    int mx = log2(m);

    vvi sparse(m, vector<int>(mx + 1, 0));

    for (int i=0;i<m;i++){
        sparse[i][0] = a[i];
    }

    for (int i=1;i<=mx;i++){
        int val = (1ll<<i);
        for (int j=0;j<=(m-val);j++){
            sparse[j][i] = max(sparse[j][i-1], sparse[j+val/2][i-1]);
        }
    }

    for (int i=0;i<q;i++){
        pi s, e;
        cin >> s.first >> s.second >> e.first >> e.second;
        int k;
        cin >> k;

        if (abs(s.first-e.first)%k != 0 || abs(s.second - e.second)%k != 0){
            cout << "NO" << endl;continue;
        }
        // cout << s.first << " " << s.second << endl;
        // cout << e.first << " " << e.second << endl;
        int ext = (n - s.first);
        int mxh = ext - ext%k + s.first;
        int f = min(s.second, e.second);
        int l = max(s.second, e.second);
        int mxpov = log2(l - f + 1);
        int mxtow = max(sparse[f-1][mxpov], sparse[l-(1ll<<mxpov)][mxpov]);
        if (mxh > mxtow){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
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