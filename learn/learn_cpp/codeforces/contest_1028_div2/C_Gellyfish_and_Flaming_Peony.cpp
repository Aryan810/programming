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
const int INF = INT32_MAX;

int bfs(int g, vi & a){
    vector<int> dp(5001, INF);
    queue<int> q;
    for (int i=0;i<a.size();i++){
        dp[a[i]] = 0;
        q.push(a[i]);
    }
    while (q.size() > 0){
        int curr = q.front();
        q.pop();
        for (int i=0;i<a.size();i++){
            if (dp[gcd(curr, a[i])] == INF){
                q.push(gcd(curr, a[i]));
                dp[gcd(curr, a[i])] = min(dp[gcd(curr, a[i])], dp[curr] + dp[a[i]] + 1);
            }
        }
    }
    return dp[g];
}

void solve(){

    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    int x = 0;
    for (int i=0;i<n;i++){
        x = gcd(x, a[i]);
    }
    int num = 0;
    for (int i=0;i<n;i++){
        if (a[i] == x){
            num += 1;
        }
    }
    if (num >= 1){
        cout << n-num << endl;return;
    }
    cout << bfs(x, a) + n - 1 << endl;
    

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