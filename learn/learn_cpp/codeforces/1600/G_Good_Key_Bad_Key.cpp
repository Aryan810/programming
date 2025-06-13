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

int binexpiter(int a, int b){
    int ans = 1;
    while (b){
        if (b&1){
            ans = ans * a;
        }
        a = a * a;
        b >>= 1;
    }
    return ans;
}

int helper(int i, int bad, vector<vector<int> > & dp, int n, int k, vector<int> & c, int mx){
    // cout << i << " " << bad << " " <<  mx << endl;
    if (i >= n || binexpiter(2, bad) > mx){
        return 0;
    }
    if (dp[i][bad] != -1){
        return dp[i][bad];
    }

    int ret = 0; 
    int curr = c[i];
    for (int i=0;i<bad;i++){
        curr /= 2;
    }
    ret = max(ret, helper(i+1, bad, dp, n, k, c, mx) - k + curr);
    if (binexpiter(2, bad+1) <= mx){
        ret = max(ret, helper(i+1, bad+1, dp, n, k, c, mx) + curr/2);
    }
    return dp[i][bad] = ret;    
}

void solve(){

    int n, k;cin >> n >> k;

    vi a(n);
    int mx = 0;
    rep(i, n){
        int x;
        cin >> x;
        mx = max(mx, x);
        a[i] = x;
    }

    vector<vector<int> > dp(n+1, vector<int>(33, -1));

    cout << helper(0, 0, dp, n, k, a, mx) << endl;
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