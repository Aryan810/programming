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
    
    int n, k;
    cin >> n >> k;

    vi a(n);
    vector<pi> b(n);
    rep(i, n){
        int x;
        cin >> x;
        b[i] = {x + i, i};
        a[i] = x;
    }

    sort(rall(b));

    vector<pi> c;

    for (int i=0;i<n && i<k;i++){
        c.push_back({b[i].second, b[i].first});
    }

    sort(all(c));

    // int curr = n-1;
    vector<int> jumped(n, 0);
    for (int i=0;i<c.size();i++){
        // if (c[i].second >= curr){
            jumped[c[i].first] = 1;
            // curr -= 1;
        // }
    }
    // for (int i=0;i<n;i++){
    //     cout << jumped[i];
    // }cout << endl;
    int add = 0;
    int ans = 0;
    for (int i=0;i<n;i++){
        if (jumped[i]){
            add += 1;
        }else{
            ans += a[i] + add;
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