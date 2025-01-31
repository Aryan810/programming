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

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

void solve(){

    int n, k;cin >> n >> k;
    vi a(n);
    rep(i, n){
        cin >> a[i];
    }
    int dp[n];
    dp[0] = 0;
    dp[1] = abs(a[0]-a[1]);
    for (int i=2;i<n;i++){
        int mi = 1e18;
        for (int j=1;j<=k && (i-j >= 0);j++){
            mi = min(mi, dp[i-j] + abs(a[i]-a[i-j]));
        }
        dp[i] = mi;
    }
    cout << dp[n-1] << endl;
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


        solve();

    return 0;
}