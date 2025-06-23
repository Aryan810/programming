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
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i=0;i<n;i++){
        a[i] = i+1;
    }
    int st = 0;
    for (int i=0;i<q;i++){
        int t;cin >> t;
        if (t == 1){
            int p, x;
            cin >> p >> x;
            a[(st+p-1)%n] = x;
        }else if (t == 2){
            int p;
            cin >> p;
            cout << a[(st+p-1)%n] << endl;
        }else{
            int k;
            cin >> k;
            st += k;
        }
    }


}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // mint::set_mod(M);
    // int test;
    // cin >> test;

    // while(test--){
        solve();
    // }

    return 0;
}