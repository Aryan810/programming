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
    rep(i ,n) cin >> a[i];

    vi fac;
    for (int i=1;i<=n;i++){
        if (n%i == 0){
            fac.push_back(i);
        }
    }
    int ans = 0;
    for (auto ele: fac){
        int k = ele;
        int m = 0;
        // cout << "K: " << k << endl;
        for (int i=0;i<n/k;i++){
            int last = a[i];
            for (int j=i+(n/k);j<n;j+=(n/k)){
                int diff = abs(a[j]-last);
                // cout << diff << " " << m << endl;
                m = gcd(m, diff);
                last = a[j];
            }
        }
        // cout << "M: " << m << endl;
        if (m == 0 || m >= 2){
            ans += 1;
        }
    }
    cout << ans << endl;

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