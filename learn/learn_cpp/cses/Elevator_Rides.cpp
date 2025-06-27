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

pair<int, int> dp[1ll<<21];

void solve(){
    
    int n;
    cin >> n;
    int x;
    cin >> x;
    // memset(dp, -1, sizeof(dp));
    vi a(n);
    rep(i, n) cin >> a[i];
    dp[0] = {0, 1e18};
    for (int i=1;i<=((1ll<<n) - 1);i++){
        pair<int, int> temp = {n, 0};
        for (int j=0;j<n;j++){
            if ((1ll<<j)&i){
                int tmp = i - ((1ll<<j)&i);
                if (dp[tmp].second + a[j] <= x){
                    if (temp.first > dp[tmp].first){
                        temp.first = dp[tmp].first;
                        temp.second = (dp[tmp].second+a[j]);
                    }else if (temp.first == dp[tmp].first){
                        if (temp.second > dp[tmp].second + a[j]){
                            temp.second = dp[tmp].second + a[j];
                        }
                    }
                }else{
                    if (temp.first > dp[tmp].first + 1){
                        temp.first = dp[tmp].first + 1;
                        temp.second = a[j];
                    }
                }
            }
        }
        
        dp[i] = temp;
    }
    // cout << dp[11].first << " " << dp[1].second << endl;
    cout << dp[(1ll<<(n))-1].first << endl;

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