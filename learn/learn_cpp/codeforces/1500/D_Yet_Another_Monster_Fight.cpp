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

bool check(int x, vi & a, int & n){
    vi b(n);
    vector<int> wl, wr;
    rep(i, n){
        b[i] = a[i] - x;
        if (b[i] > 0){
            return 0;
        }
        int rm = n - i - 1;
        if (rm+b[i] > 0){
            if (i < n-1){
                wr.push_back(n-1);
                wl.push_back(i+1);
            }
        }
        int lm = i;
        if (lm+b[i] > 0){
            if (i > 0){
                wr.push_back(i-1);
                wl.push_back(0);
            }
        }
    }
    sort(all(wl));
    sort(all(wr));
    for (int i=0;i<n;i++){
        auto it1 = upper_bound(all(wl), i);
        auto it2 = lower_bound(all(wr), i);
        int r = wl.size() - (int)(it1 - wl.begin());
        int l = it2 - wr.begin();
        if (wl.size()-r-l <= 0){
            return 1;
        }        
    }
    return 0;
}

void solve(){
    
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    int l = 1;
    int h = accumulate(all(a), 0ll);
    while (h - l > 1){
        int mid = (h + l)/2;
        if (check(mid, a, n)){
            h = mid;
        }else{
            l = mid + 1;
        }
    }
    if (check(l, a, n)){
        cout << l << endl;
    }else{
        cout << h << endl;
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // mint::set_mod(M);
        solve();

    return 0;
}