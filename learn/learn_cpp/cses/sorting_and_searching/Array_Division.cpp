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

int check(int mid, vi & a, int & k){
    int i = 0;
    int j = 0;
    int left = k;
    int ans = 0;
    int n = a.size();
    while (i < a.size() && j < a.size()){
        int temp = a[i];
        j += 1;
        // if (left > 1){
            while (j < n && temp + a[j] <= mid){
                temp += a[j];
                j += 1;
            }
        // }
        // cout << i << " " << j << endl;
        ans = max(ans, temp);
        left -= 1;
        i = j;
    }
    // cout << left << endl;
    // cout << ans << endl;
    if (left > 0){
        return -1;
    }else if (left < 0){
        return 1;
    }else{
        return 0;
    }
}

void solve(){
    
    int n, k;
    cin >> n >> k;

    vi a(n);
    rep(i, n) cin >> a[i];

    int sm = accumulate(all(a), 0ll);
    int l = *max_element(all(a));
    int h = sm;

    while (h - l > 1){
        int mid = (h + l)/2;
        int c = check(mid, a, k);
        if (c == -1){
            h = mid;
        }else if (c == 1){
            l = mid+1;
        }else{
            h = mid;
        }
    }
    int ch = check(l, a, k);
    // cout << check(39141, a, k) << endl;
    // cout << l << " " << h << endl;
    if (ch == 1){
        cout << h << endl;
    }else{
        cout << l << endl;
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