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

bool check(int mid, int & t, vector<int> & k){
    int n = k.size();
    int prod = 0;
    for (int i=0;i<n;i++){
        prod += (mid / k[i]);
        if (prod > t){
            prod = t+1;
        }
    }
    return (prod >= t);
}

void solve(){
    
    int n, t;
    cin >> n >> t;
    vi k(n);

    rep(i, n) cin >> k[i];
    int mx = *max_element(all(k));

    int l = 1;
    int h = t * mx + 1;
    while (h-l > 1){
        int mid = (h+l)/2;
        if (check(mid, t, k)){
            h = mid;
        }else{
            l = mid + 1;
        }
    }
    if (check(l, t, k)){
        cout << l << endl;
    }else{
        cout << h << endl;
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