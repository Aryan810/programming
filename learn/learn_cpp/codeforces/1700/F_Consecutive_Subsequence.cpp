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
    
    int n;
    cin >> n;
    vi a(n);
    map<int, vector<int> > ind;
    rep(i, n){
        int x;
        cin >> x;
        ind[x].push_back(i);
        a[i] = x;
    }

    vector<int> dp(n, 0);
    map<int, int> cnt;
    for (int i=0;i<n;i++){
        int last = a[i];
        dp[i] = 1 + cnt[last-1];
        cnt[last] = max(cnt[last], dp[i]);
    }
    pair<int, int> mx = {0, -1};
    for (int i=0;i<n;i++){
        if (dp[i] > mx.first){
            mx.first = dp[i];
            mx.second = i;
        }
    }

    cout << mx.first << endl;
    vi out(mx.first);
    int curr = a[mx.second];
    int mxind = mx.second;
    for (int i=mx.first-1;i>=0;i--){
        vi & v = ind[curr];
        auto it = upper_bound(all(v), mxind)-1;
        out[i] = 1 + (*it);
        mxind = *it;
        curr -= 1;
    }       
    each(ele, out){
        cout << ele << " ";
    }cout << endl;

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