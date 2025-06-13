#include<atcoder/modint>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;
using namespace atcoder;
using mint = modint;
#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator
#define umap(x, y) unordered_map<x, y, custom_hash>
const int M = 1e9 + 7;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

// mint ncr(mint & a, mint & x){
//     mint ret = 0;
//     if (a.val() < x){
//         return ret;
//     }

//     return ()

    
    
// }

void solve(){
    
    int n, k;
    cin >> n >> k;

    vi a(n);
    rep(i, n) cin >> a[i];
    int one = accumulate(all(a), 0ll);
    int zero = n - one;
    mint ans = 0;
    mint zm = 1;
    mint om = 1;
    mint of = 1;
    mint zf = 1;
    mint ifac = 1;
    mint nmifac = 1;
    int x =  (k+1)/2;
    for (int i=1;i<=one;i++){
        of *= i;
    }
    for (int i=1;i<=zero;i++){
        zf *= i;
    }
    for (int i=1;i<x;i++){
        ifac *= i;
    }
    
    for (int i=1;i<=(one-x);i++){
        om *= i;
    }
    for (int i=1;i<(zero-k+x);i++){
        if (zero-k+x > 0){zm *= i;}
    }
    for (int i=1;i<=(k-x);i++){
        nmifac *= i;
    }
    // cout << nmifac.val() << " " << ifac.val() << endl;
    for (int i=x;i<=k;i++){
        // cout << i << " ";
        if (one < i){
            break;
        }
        // cout << "HER" << endl;
        if (zero-k+i > 0){zm *= zero-k+i;}
        ifac *= i;
        // cout << of.val() << " " << ifac.val() << " " << om.val() << " " << zf.val() << " " << nmifac.val() << " " << zm.val() << endl;
        if (zero >= k-i){ans += (of/(om * ifac)) * (zf/(zm*nmifac));}
        // cout << ans.val() << endl;
        // cout << ans.val() << endl;
        if (k-i > 0){nmifac /= (k-i);}
        if (one - i > 0){om /= (one-i);}
    }




    cout << ans.val() << endl;


}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mint::set_mod(M);
    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}