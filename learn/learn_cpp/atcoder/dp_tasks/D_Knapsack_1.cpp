// recursive approach

// #include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

// // #pragma GCC optimize("Ofast,unroll-loops")

// using namespace std;
// using namespace __gnu_pbds;

// #define int long long
// #define rep(i, n) for(int i=0;i<n;i++)
// #define all(v) v.begin(), v.end()
// #define rall(v) v.rbegin(), v.rend()
// #define vi vector<int>
// #define vii vector<int>::iterator

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key
// // Bottom-up approach.
// int helper(vector< vector<int> > & dp, int w, int i, vector<pair<int, int> > & a, int W){
//     if (w > W || i >= a.size()){
//         return 0;
//     }
//     if (dp[i][w] != -1){
//         return dp[i][w];
//     }

//     int ret = 0;
//     ret = max(ret, helper(dp, w, i+1, a, W));
//     if (w+a[i].second <= W) ret = max(ret, helper(dp, w+a[i].second, i+1, a, W) + a[i].first);
//     return dp[i][w] = ret;
// }   

// void solve(){
//     int n, w;
//     cin >> n >> w;
//     vector<pair<int, int> > a(n);
//     rep(i, n){
//         cin >> a[i].second >> a[i].first;
//     }
//     vector<vector<int> > dp(n, vector<int>(1e5+1, -1));
//     cout << helper(dp, 0, 0, a, w) << endl;

    

// }

// signed main(){

//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int test = 1;

//     while(test--){
//         solve();
//     }

//     return 0;
// }


// Iterative approach

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace __gnu_pbds;
using namespace std;
#define int long long
#define vi vector<int>
#define vii vector<int>::iterator
#define rep(i, n) for(int i=0;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void helper(vector< vector<int> > & dp, int i, int w, vector<pair<int, int> > & a, int W){
    if (i >= a.size() || w > W){
        return;
    }
    dp[i][w] = dp[i-1][w];
    if (dp[i+1][w] == -1){helper(dp, i+1, w, a, W);}
    if (w+a[i].second <= W){
        dp[i][w+a[i].second] = dp[i-1][w] + a[i].first;
        if (dp[i+1][w+a[i].second] == -1){helper(dp, i+1, w+a[i].second, a, W);}
    }
}   

void solve(){

    int n, w;
    cin >> n >> w;
    vector<pair<int, int> > a(n);
    rep(i, n){
        cin >> a[i].second >> a[i].first;
    }
    vector<vector<int> > dp(n+1, vector<int>(1e5+1, -1));
    dp[0][0] = 0;
    if (a[0].second <= w){dp[0][a[0].second] = a[0].first;}
    helper(dp, 1, 0, a, w);
    if (a[0].second <= w){helper(dp, 1, a[0].second, a, w);}
    cout << endl;
    for (int i=0;i<n;i++){
        cout << *max_element(all(dp[i])) << " ";
    }cout << endl;
    int ans = *max_element(all(dp[n-1]));
    cout << ans << endl;

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // while(t--){

        solve();

    // }

    return 0;
}