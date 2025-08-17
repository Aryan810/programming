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

#ifdef LOCAL
#include "/Users/aryangupta/Documents/programming/templets/algo/debug.h"
#else
#define debug(...) 42
#endif

// struct node{
//     char val;
//     struct node * nxt;
//     struct node * prev;
// };
// typedef struct node node;

void solve(){
    
    int n, m;
    cin >> n >> m;

    string a, b;
    cin >> a >> b;

    vector<bool> v(n+1, 0);
    
    for (int i=0;i<m;i++){
        int l, r;
        cin >> l >> r;
        v[l-1] = 1 - v[l-1];
        if (r != n) v[r] = 1 - v[r];
    }
 
    bool curr = 0;
    for (int i=0;i<n;i++){
        curr ^= v[i];
        if (curr){
            cout << b[i];
        }else{
            cout << a[i];
        }
    }

   
    // node a[n];
    // node b[n];
    // a[0].prev = NULL;
    // a[n-1].nxt = NULL;
    // b[0].prev = NULL;
    // b[n-1].nxt = NULL;

    // for (int i=0;i<n;i++){
    //     char c;
    //     cin >> c;
    //     a[i].val = c;
    //     if (i > 0){
    //         a[i].prev = &a[i-1];
    //     }
    //     if (i < n-1){
    //         a[i].nxt = &a[i+1];
    //     }
    // }
    // for (int i=0;i<n;i++){
    //     char c;
    //     cin >> c;
    //     b[i].val = c;
    //     if (i > 0){
    //         b[i].prev = &b[i-1];
    //     }
    //     if (i < n-1){
    //         b[i].nxt = &b[i+1];
    //     }
    // }

    // for (int i=0;i<m;i++){

    // }
    


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