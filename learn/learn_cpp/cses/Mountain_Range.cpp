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
int dp[200001];
void solve(){
    
    int n;
    cin >> n;

    vi a(n);
    vector<pair<int,int> > b(n);
    rep(i, n){
        int x;
        cin >> x;
        a[i] = x;
        b[i] = {x, i};
    }
    sort(all(b));
    int ans = 0;
    dp[b[0].second] = 1;
    for (int i=0;i<n;i++){
        int curr = b[i].first;
        int j = b[i].second;
        int temp = 0;
        int k = j-1;
        while (k >= 0 && a[k] < curr){
            temp = max(temp, dp[k]);
            k -= 1;
        }
        k = j+1;
        while (k < n && a[k] < curr){
            temp = max(temp, dp[k]);
            k += 1;
        }
        temp += 1;
        dp[j] = temp;
        ans = max(ans, temp);
    }
    cout << ans << endl;
}

signed main(){
    fast_io;   
    // mint::set_mod(M);
    // int test;
    // cin >> test;

    // while(test--){
        solve();
    // }

    return 0;
}