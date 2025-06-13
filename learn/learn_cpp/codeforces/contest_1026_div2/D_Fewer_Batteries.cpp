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
vector<vector<pair<int, int> > > graph;
vi b;
int n;
bool check(int mid){
    vector<int> dp(n+1, -1e9);
    dp[1] = min(mid, b[0]);
    for (int i=2;i<=n;i++){
        for (auto &[j, w] : graph[i]){
            if (w <= dp[j]){
                dp[i] = max(dp[i], min(b[i-1] + dp[j], mid));
            }
        }
    }
    return dp[n] >= 0;
}

void solve(){

    int m;
    cin >> n >> m;
    b.clear();
    b.resize(n);
    rep(i, n) cin >> b[i];
    graph.clear();
    graph.resize(n+1);
    for (int i=0;i<m;i++){
        int s, t, w;
        cin >> s >> t >> w;
        graph[t].push_back({s, w});
    }

    int l = 0, h=1e9+1;

    while (h-l > 1){
        int mid = (l+h)/2;

        if (check(mid)){
            h = mid;
        }else{
            l = mid + 1;
        }
    }

    if (check(l)){
        cout << l << endl;
    }else if (check(h)){
        cout << h << endl;
    }else{
        cout << -1 << endl;
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