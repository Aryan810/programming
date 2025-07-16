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
    vi cum(n+1, 0);
    cum[0] = 0;
    int sm = 0;
    rep(i, n){
        int x;
        cin >> x;
        sm += x;
        cum[i+1] = sm;
        a[i] = x;
    }

    stack<pi> st;
    st.push({-1e18, n+1});
    vi nxts(n+1);
    for (int i=n;i>=0;i--){
        while (st.size() > 0 && st.top().first >= cum[i]) st.pop();
        nxts[i] = st.top().second;
        st.push({cum[i], i});
    }

    vi dp(n+1, 0);

    for (int i=n;i>=0;i--){
        if (nxts[i] > n){
            dp[i] = i;
        }else{
            dp[i] = dp[nxts[i]];
        }
    }

    pi ans = {-1e18, -1};
    for (int i=0;i<=n;i++){
        int mxr = cum[i] + cum[n] - cum[dp[i]];
        if (mxr > ans.first){
            ans = {mxr, cum[i]};
        }
    }

    cout << ans.second << endl;



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