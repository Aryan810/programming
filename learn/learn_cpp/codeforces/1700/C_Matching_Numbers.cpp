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
    if (n%2 == 0){
        cout << "No" << endl;return;
    }
    if (n&1){
        cout << "Yes" << endl;
        int l = 1;
        int h = 2*n;
        int mn = (3*(n+1))/2;
        int left = n;
        while (l < h && l+h >= mn){
            cout << l << " " << h << endl;
            left -= 1;
            l += 1;
            h -= 2;
        }
        h = 2*n - 1;
        while (left > 0){
            cout << l << " " << h << endl;
            left -= 1;
            l += 1;
            h -= 2;
        }
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