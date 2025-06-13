// #include<atcoder/modint>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;
// using mint = modint;
#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator
#define umap(x, y) unordered_map<x, y, custom_hash>
const int M = 1e9 + 7;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

bool check(int mid, vi & a, vi & c, int & k){
    int n = a.size();
    int ans = 0;
    for (int i=0;i<n;i++){
        int terms = (mid + c[i] - 1) / (c[i]);
        // cout << "Terms: " << terms << " " << c[i] << endl;
        ans += terms * a[i];
        if (ans >= k){ // doing this because it might get overflowed at end of iterations ! (this is imp.!)
            return 1;
        }
    }
    // cout << 
    return (k <= ans);
}

void solve(){
    
    int k, n;
    cin >> k >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    vi c(n);
    rep(i, n) cin >> c[i];

    int l = 1;
    int h = 1e11;
    while (h - l > 1ll){
        int mid = (h+l)/2ll;
        // cout << l << " " << mid << " " << h << endl;
        if (check(mid, a, c, k)){
            h = mid;
        }else{
            l = mid + 1;
        }
    }
    // cout << h << " " << l << " " << check(125000000000000000, a, c, k) <<  endl;
    if (check(l, a, c, k)){
        cout << l << endl;
    }else{
        cout << h << endl;
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // mint::set_mod(M);
    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}