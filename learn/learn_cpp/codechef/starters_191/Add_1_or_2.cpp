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

bool check(int mid, vi & a, vi & b){
    int oper = 0;
    int avail = 0;
    int n = a.size();
    for (int i=0;i<n;i++){
        if (a[i]+b[i] > mid){
            oper += a[i] + b[i] - mid;
        }else{
            avail += (mid - a[i]-b[i])/2;
        }
    }

    return (avail >= oper);
}

void solve(){
    
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    vi b(n);
    int mx = 0;
    rep(i, n){
        int x;
        cin >> x;
        mx = max(mx, a[i]+x);
        b[i] = x;
    }

    int l = *max_element(all(a));
    int h = mx;
    while (h - l > 1){
        int mid = (h + l)/2;
        if (check(mid, a, b)){
            h = mid;
        }else{
            l = mid + 1;
        }
    }
    if (check(l, a, b)){
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