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

    vector<vector<int> > graph(n, vector<int>(n));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin >> graph[i][j];
        }
    }
    vector<int> x(n);
    rep(i, n) cin >> x[i];
    const int INF = 1e9+7;
    vector<vector<int> > dp(n, vector<int>(n, INF));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (i == j){
                dp[i][j] = 0;
            }
            dp[i][j] = graph[i][j];
        }
    }
    
    vector<int> out;
    vector<int> avail(n+1, 0);
    for (int k=0;k<n;k++){
        avail[x[n-1-k]] = 1;
        int temp = 0;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                // if (avail[i+1] && avail[j+1]){
                    dp[i][j] = min(dp[i][j], dp[i][x[n-1-k]-1] + dp[x[n-1-k]-1][j]);
                // }
            }
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (avail[i+1] && avail[j+1]){
                    temp += dp[i][j];
                }
                // cout << dp[i][j] << " ";
            }
            // cout << endl;
        }
        // cout << endl;
        out.push_back(temp);
    }

    for (int i=out.size()-1;i>=0;i--){
        cout << out[i] << " ";
    }cout << endl;
    
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    
    return 0;
}