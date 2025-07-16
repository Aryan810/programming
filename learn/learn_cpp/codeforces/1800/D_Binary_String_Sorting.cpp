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
    
    string s;
    cin >> s;
    int n;
    n = s.size();
    vi cum(n+1);
    cum[0] = 0;
    int sm = 0;
    for (int i=0;i<n;i++){
        int x = s[i]-'0';
        sm += x;
        cum[i+1] = sm;
    }

    // case 1 - all by deleting.
    int ans = 1e18;
    for (int i=0;i<n;i++){
        int sr = cum[n] - cum[i+1];
        int sl = cum[i] - cum[0];
        int zr = n - i - 1 - sr;
        int ol = sl;
        ans = min(ans, (int)(1e12 + 1)*(zr + ol));
    }

    // case 2 - deleting all except one pair "1 0" which will be swapped.
    for (int i=0;i<n-1;i++){
        if (s[i] == '1' && s[i+1] == '0'){
            int sr = cum[n] - cum[i+2];
            int sl = cum[i] - cum[0];
            int zr = n - i - 2 - sr;
            int ol = sl;
            ans = min(ans, (int)(1e12)*(zr + ol + 1) + zr + ol);
        }
    }

    cout << ans << endl;
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