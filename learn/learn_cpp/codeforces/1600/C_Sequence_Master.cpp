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
    vector<int> a(2*n);
    rep(i, 2*n) cin >> a[i];
    int sm = 0;
    for (int i=0;i<2*n;i++){
        sm += abs(a[i]+1);
    }
    if (n == 1){
        cout << abs(a[0]-a[1]) << endl;return;
    }
    if (n == 2){
        // cout << "ERHER" << endl;
        int ans = 1e18;
        // all zero
        int temp = 0;
        for (int i=0;i<2*n;i++){
            temp += abs(a[i]);
        }
        ans = min(ans, temp);


        // all 2
        temp = 0;
        for (int i=0;i<2*n;i++){
            temp += abs(a[i]-2);
        }
        // cout << "TEMP: " << temp << endl;
        ans = min(ans, temp);

        // one 2
        for (int i=0;i<2*n;i++){
            int t = 0;
            int x = abs(a[i]+1);
            t = sm - x + abs(a[i]-2);
            ans = min(ans, t);
        }
        cout << ans << endl;
    }else if (!(n&1)){
        int ans = 1e18;

        // all zero
        int temp = 0;
        for (int i=0;i<2*n;i++){
            temp += abs(a[i]);
        }
        ans = min(ans, temp);

        int p = n;
        for (int i=0;i<2*n;i++){
            int t = 0;
            int x = abs(a[i]+1);
            t = sm - x + abs(a[i]-p);
            ans = min(ans, t);
        }
        cout << ans << endl;
    }else{
        int ans = 1e18;
        // all zero
        int temp = 0;
        for (int i=0;i<2*n;i++){
            temp += abs(a[i]);
        }
        ans = min(ans, temp);
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