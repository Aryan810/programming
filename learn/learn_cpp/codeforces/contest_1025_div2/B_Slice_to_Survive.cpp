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

    int n, m, a, b;
    cin >> n >> m >> a >> b;

    // first cut
    // case 1 - vertical cut
    int n1 = n;
    int m1 = min(b, m-b+1);
    int ans = 1;
    while (n1 != 1 || m1 != 1){
        if (n1 != 1){
            n1 = (n1 + 1)/2;ans += 1;
        }
        if (m1 != 1){
            m1 = (m1 + 1)/2;ans += 1;
        }
    }


    // case 2 - horizontal

    n1 = min(a, n-a+1);
    m1 = m;
    int ans1 = 1;
    while (n1 != 1 || m1 != 1){
        if (n1 != 1){
            n1 = (n1 + 1)/2;ans1 += 1;
        }
        if (m1 != 1){
            m1 = (m1 + 1)/2;ans1 += 1;
        }
    }

    cout << min(ans, ans1) << endl;


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