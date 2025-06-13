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

    int n;
    cin >> n;
    vi a(n);
    rep(i, n)cin >> a[i];

    sort(all(a));

    int k = a[n-1]-a[0];

    vi b(n);
    bool m = 1;
    int f = 0;
    int l = n-1;
    int addi = 0;
    for (int i=0;i<n;i++){
        // cout << addi + a[l] << endl;
        if ((addi + a[l]) >= k){
            b[i] = a[f];
            addi += a[f];
            f += 1;
        }else{
            b[i] = a[l];
            addi += a[l];
            l -= 1;
        }
    }
    vi cum(n+1);
    cum[0] = 0;
    int sm = 0;
    for (int i=0;i<n;i++){
        sm += b[i];
        cum[i+1] = sm;
    }

    int mn = -1e18;
    int temp = 0;
    for (int i=0;i<n;i++){
        temp += b[i];
        mn = max(mn, abs(temp));
    }
    temp = 0;
    for (int i=n-1;i>=0;i--){
        temp += b[i];
        mn = max(mn, abs(temp));
    }
 
    if (mn < k){
        cout << "Yes" << endl;
           for (auto ele: b){
            cout << ele << " ";
        }cout << endl;
    }else{
        cout << "No" << endl;
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