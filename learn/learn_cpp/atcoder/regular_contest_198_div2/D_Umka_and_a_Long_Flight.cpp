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
int dp[46][46][46][46][2];
vector<int> fib(46);
vector<int> cum(47);

bool helper(int a, int b, int c, int n, int i, int orient){
    cout << a << " " << b << " " << c << " I: " << i << " " << orient << endl;
    if ((a < 0 || (b < 0 || c < 0))){
        return 0;
    }
    if (dp[a][b][c][i][orient] != -1){
        return dp[a][b][c][i][orient];
    }
    if (a == 0 && (b == 0 && (c == 0 && i > n) )){
        return 1;
    }
    if (i > n || (a < 0 || (b < 0 || c < 0))){
        return 0;
    }
    int d = cum[n+1]-cum[i]-(a+b+c);
    cout << "D: " << d << endl;

    int ret = 0;
    if (orient){
    // cout << "HERE" << endl;
        // cout << b << " " << fib[i] << endl;
        if (d > 0 && d >= fib[i]){
            ret = ret | helper(a, b, c, n, i+1, 1-orient);
        }
        if (b > 0 && b >= fib[i]){
            // cout << "THERE" << endl;
            ret = ret | helper(a, b-fib[i], c, n, i+1, 1-orient);
        }
    }else{
        if (a > 0 && a >= fib[i]){
            ret = ret | helper(a-fib[i], b, c, n, i+1, 1-orient);
        }
        if (c > 0 && c >= fib[i]){
            ret = ret | helper(a, b, c-fib[i], n, i+1, 1-orient);
        }
    }
    return dp[a][b][c][i][orient] = ret;
}

void solve(){

    int n, x, y;
    cin >> n >> x >> y;
    int h = fib[n];
    int w = fib[n+1];
    cout << "W: " << w << endl;
    int a = x-1;
    int b = w-y;
    int c = h-x;
    int d = y-1;
    cout << a << " " << b << " " << c << endl;

    bool ans = 0;
    ans = ans | helper(a-1, b, c, n, 2, 1);
    ans = ans | helper(a, b, c-1, n, 2, 1);
    ans = ans | helper(a, b-1, c, n, 2, 0);
    ans = ans | helper(a, b, c, n, 2, 0);
    
    cout << (ans?"YES":"NO") << endl;

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fib[0] = 1;
    fib[1] = 1;
    cum[0] = 0;
    cum[1] = 1;
    cum[2] = 2;
    memset(dp, -1, sizeof(dp));
    int sm = 2;
    for (int i=2;i<=45;i++){
        fib[i] = fib[i-1] + fib[i-2];
        sm += fib[i];
        cum[i+1] = sm;
    }
    for (auto ele: fib){
        cout << ele << " ";
    }cout << endl;
    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}