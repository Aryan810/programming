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
   
    int n, m;
    cin >> n >> m;
    vi a(n);
    rep(i, n) cin >> a[i];

    vi b;
    rep(i, m){
        int x;
        cin >> x;
        b.push_back(x);
    }
    sort(rall(b));
    int i = 0;
    int j = 0;
    while (i < n && j < m){
        if (a[i] > b[j]){
            cout << a[i] << " ";
            i += 1;
        }else{
            cout << b[j] << " ";
            j += 1;
        }
    }
    while (i < n){
        cout << a[i] << " ";
        i += 1;
    }
    while (j < m){
        cout << b[j] << " ";
        j += 1;
    }
    
  cout << endl;

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