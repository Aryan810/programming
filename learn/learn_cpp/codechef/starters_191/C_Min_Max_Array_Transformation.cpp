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

void solve(){
    
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    vi b(n);
    rep(i, n) cin >> b[i];

    vector<int> v;
    for (int i=0;i<(n-1);i++){
        if (b[i] < a[i+1]){
            v.push_back(i);
        }
    }

    for (int i=0;i<n;i++){
        // for min.
        cout << *(lower_bound(all(b), a[i])) - a[i] << " ";
    }cout << endl;
    
    // for maximum.
    for (int i=0;i<n;i++){
        auto it = lower_bound(all(v), i);
        if (it == v.end()){
            cout << b[n-1]-a[i] << " ";
        }else{
            cout << b[*it] - a[i] << " ";
        }
    }cout << endl;

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