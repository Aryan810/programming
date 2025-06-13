#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator
#define umap(x, y) unordered_map<x, y, custom_hash>

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve(){

    int n, m;
    cin >> n >> m;
    vi a(n);
    vi b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    vi d(m, n);
    // if already done
    int i = 0, j = 0;
    while (i < n && j < m){
        if (a[i] >= b[j]){
            d[j] = i;
            i += 1;
            j += 1;
        }else{
            i += 1;
        }
    }

    if (j >= m){
        cout << 0 << endl;return;
    }
    if (m == 1){
        cout << b[0] << endl;return;
    }
    vector<int> c(m, -1);
    // c[m-1] = n;
    i = n-1;j=m-1;
    while (i >= 0 && j >= 0){
        if (a[i] >= b[j]){
            c[j] = i;
            // cout << j << " " << i << endl;
            i -= 1; 
            j -= 1;
        }else{
            i -= 1;
        }
    }
    // for (auto ele: d){
    //     cout << ele << " ";
    // }cout << endl;
    // for (auto ele: c){
    //     cout << ele << " ";
    // }cout << endl;
    int ans = 1e18;
    bool found = 0;
    for (int i=0;i<m;i++){
        int x, y;
        if (i == 0){
            x = -1;
            y = c[i+1];
        }else if (i == m-1){
            x = d[i-1];
            y = n;
        }else{
            x = d[i-1];
            y = c[i+1];
        }
        if (x < y){
            ans = min(ans, b[i]);
            found = 1;
        }
        if (d[i] == n){break;}
        
    }
    if (!found){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}