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
    int dp[n+3];
    memset(dp, 0, sizeof(dp));
    vector<pi> cats(m);
    vi lows(m);
    vi highs(m);
    for (int i=0;i<m;i++){
        int l, r;
        cin >> l >> r;
        cats[i] = {r, l};
        lows.push_back(l);
        highs.push_back(r);
    }
    sort(all(lows));
    sort(all(highs));
    sort(all(cats));  
    vi mxr(n+2, 0);
    int j = m-1;
    queue<pi> q;
    for (int i=n;i>=1;i--){
        while(j >= 0 && i == cats[j].first){
            q.push({cats[j].second, cats[j].first});
            j -= 1;
        }
        while (q.size() > 0){
            auto curr = q.front();
            if (i >= curr.first && i <= curr.second){
                break;
            }
            q.pop();
        }
        if (q.size() == 0){
            mxr[i] = -1;
        }else{
            mxr[i] = q.front().second;
        }
    }
    for (int i=n;i>=1;i--){
        int mx = mxr[i];
        int ncats = 0;
        auto it1 = upper_bound(all(lows), i);
        auto it2 = lower_bound(all(highs), i);
        ncats = (it1-lows.begin())-(it2-highs.begin());
        if (mx == -1){
            dp[i] = dp[i+1];
        }else{
            // cout << i << " " << dp[mx+1] + ncats << endl;
            dp[i] = max(dp[i+1], dp[mx+1] + ncats);
        }
    }
    // for (int i=1;i<=n;i++){
    //     cout << i << " " << dp[i] << endl;
    // }cout << endl;
    cout << dp[1] << endl;
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