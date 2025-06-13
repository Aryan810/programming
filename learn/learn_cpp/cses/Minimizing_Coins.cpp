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
int dp[(int)(1e6+2)];
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

int helper(int x, vi & a, int & poss){
    // cout << x << endl;
    if (dp[x] != -1){
        return dp[x];
    }

    if (x <= 0){if (x==0){poss = 1;}return 0;}
    int ret = 1e18;
    for (int i=0;i<a.size();i++){
        if (x-a[i] >= 0){ret = min(ret, helper(x-a[i], a, poss) + 1);}
    }
    return dp[x] = ret;
}

void solve(){

    int n, x;
    cin >> n >> x;

    vi a(n);
    rep(i, n) cin >> a[i];
    memset(dp, -1, sizeof(dp));
    // sort(rall(a));
    int poss = 0;
    int y = helper(x, a, poss);
    if (poss){
        cout << y << endl;
    }else{
        cout << -1 << endl;
    }
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int test;
    // cin >> test;

    // while(test--){
        solve();
    // }

    return 0;
}