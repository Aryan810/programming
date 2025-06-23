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
    
    int a, b, c;
    cin >> a >> b >> c;
    if (c != a+1){
        cout << -1 << endl;return;
    }

    int sm = 0;
    int i;
    for (i=0;i<=16;i++){
        if (sm+(1ll<<i) > a){
            break;
        }
        sm += (1ll << i);
    }
    int left = a - sm;
    int tot = c;
    int bk = tot - left * 2;
    // cout << i << endl;
    if (left == 0){
        cout << (i + (b + tot - 1)/(tot)) << endl; 
    }else{
        b -= bk;
        cout << (i + 1 + (b+tot-1)/(tot)) << endl;
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