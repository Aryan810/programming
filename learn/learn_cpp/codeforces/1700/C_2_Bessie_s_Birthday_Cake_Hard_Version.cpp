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
int nm = 0;
void solve(){
    
    int n, x, y;
    cin >> n >> x >> y;
    
    vi a(x);
    int odd = 0;
    rep(i, x) cin >> a[i];
    // if (nm == 143){
    //     cout << n << "." << x << "." << y << "." << a[0] << "." << a[1] << endl;return;
    // }
    sort(all(a));
    int req = 0;
    vector<int> oddgapes;

    for (int i=0;i<(x-1);i++){
        req += (a[i+1]-a[i]-1)/2;
        if ((a[i+1]-a[i]-1)&1){
            odd += (a[i+1]-a[i]-1)/2;
            oddgapes.push_back((a[i+1]-a[i]-1)/2);
        }
    }
    req += (n - (a[x-1] - a[0] + 1))/2;
    if ((n - (a[x-1] - a[0] + 1))&1){
        odd += (n - (a[x-1] - a[0] + 1))/2;
        oddgapes.push_back((n - (a[x-1] - a[0] + 1))/2);

    }
    // cout << req << endl;
    int left = req - y - (req - odd);
    sort(rall(oddgapes));
    int ex = 0;
    int f = 0;
    while (f < oddgapes.size() && left > 0){
        left -= oddgapes[f];
        ex += 1;
        f += 1;
    }
    if (y >= req){
        cout << n-2 << endl;
    }else{
        cout << (n - 2 - 2*(req - y) - (max(ex, 0ll))) << endl;
    }

}

signed main(){
    fast_io;   
    // mint::set_mod(M);
    int test;
    cin >> test;

    while(test--){
        nm += 1;
        solve();
    }

    return 0;
}