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
    vi b(n);
    rep(i, n){
        int x;
        cin >> x;
        if (x <= k){
            b[i] = 1;
        }else{
            b[i] = 0;
        }
        a[i] = x;
    }

    // case 1 -> l, l, h
    int l = -1;
    int sm = 0;
    for (int i=0;i<n;i++){
        sm += b[i];
        if (b[i] == 1 && l != -1){
            break;
        }
        if (sm >= (i+2)/2){
            l = i;
        }
    }

    int r;
    sm = 0;
    for (r=l+1;r<n;r++){
        sm += b[r];
        if (sm >= (r-l+1)/2){
            break;
        }
    }
    if (r < n-1){
        cout << "YES" << endl;return;
    }
    reverse(all(b));

    l = -1;
    sm = 0;
    for (int i=0;i<n;i++){
        sm += b[i];
        if (b[i] == 1 && l != -1){
            break;
        }
        if (sm >= (i+2)/2){
            l = i;
        }
    }

    r;
    sm = 0;
    for (r=l+1;r<n;r++){
        sm += b[r];
        if (sm >= (r-l+1)/2){
            break;
        }
    }

    if (r < n-1){
        cout << "YES" << endl;return;
    }

    // case - 3

    l = -1;
    sm = 0;
    for (l=0;l<n;l++){
        sm += b[l];
        if (sm >= (l+2)/2){
            break;
        }
    }
    sm = 0;
    for (r=(n-1);r>=0;r--){
        sm += b[r];
        if (sm >= (n-r+1)/2){
            break;
        }
    }

    if (r-l > 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }




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