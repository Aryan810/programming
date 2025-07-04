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
    vi b(n);
    int sm = 0;
    rep(i, n){
        int x;
        cin >> x;
        b[i] = x;
        sm += x;
    }

    if (sm%((n*(n+1))/2) != 0){
        cout << "NO" << endl;return;
    }
    int s = sm / ((n*(n+1))/2);
    vector<int> a(n);
    sm = 0;
    for (int i=1;i<n;i++){
        int y = (s - b[i] + b[i-1]);
        if (y%n != 0 || y <= 0){
            cout << "NO" << endl;return;
        }
        a[i] = y/n;
        sm += a[i];
    }

    a[0] = s - sm;
    if (a[0] <= 0){
        cout << "NO" << endl;return;
    }

    cout << "YES" << endl;
    rep(i, n){
        cout << a[i] << " ";
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