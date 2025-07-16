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

int check(pi & f, pi & s, int sm, int & m){
    int a = f.first;
    int mn = sm * a;
    if (mn > m){return mn;}

    int h, l;
    if (sm <= s.second){
        h = (a+1)*sm;
        if (sm <= f.second){
            l = a*sm;
        }else{
            l = a*sm + (sm - f.second);
        }
    }else{
        h = a*sm + s.second;
        if (sm <= f.second){
            l = a*sm;
        }else{
            l = a*sm + (sm - f.second);
        }
    }
    if (l > m){
        return l;
    }else if (h > m){
        return m;
    }else{
        return h;
    }
}

void solve(){
    
    int n, m;
    cin >> n >> m;

    vi a(n);
    rep(i, n) cin >> a[i];

    vi c(n);
    rep(i, n) cin >> c[i];
    vector<pi> v(n);
    rep(i, n){
        v[i] = {a[i], c[i]};
    }
    sort(all(v));
    int ans = 0;
    // considering only individuals
    for (int i=0;i<n;i++){
        int req = m/v[i].first;
        ans = max(ans, min(req, v[i].second)*v[i].first);
    }
    for (int i=0;i<(n-1);i++){
        if (v[i+1].first - v[i].first != 1){
            continue;
        }
        int l = 1;
        int h = v[i].second + v[i+1].second;
        // cout << l << " " << h << endl;
        while (h - l > 1){
            int mid = (h + l)/2;
            if (check(v[i], v[i+1], mid, m) <= m){
                l = mid;
            }else{
                h = mid - 1;
            }
        }
        // cout << i << " " << l << " " << h << endl;
        int res1 = check(v[i], v[i+1], h, m);
        int res2 = check(v[i], v[i+1], l, m);
        // cout << res << endl;
        if (res1 <= m){
            ans = max(ans, res1);
        }else if (res2 <= m){
            ans = max(ans, res2);
        }
    }
    cout << min(ans, m) << endl;
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