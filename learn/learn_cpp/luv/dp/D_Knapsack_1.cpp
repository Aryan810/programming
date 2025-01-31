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

int logic(int ind, int wt_left, vector<int> & wt, vector<int> & val, vector<vector<int> > & dp){
    // cout << ind << " " << wt_left << endl;
    if (wt_left == 0){
        return 0;
    }
    if (ind == 0){
        if (wt_left >= wt[ind]){
            return val[ind];
        }else{
            return 0;
        }
    }
    if (ind < 0){
        return 0;
    }
    if (dp[ind][wt_left] != -1){
        return dp[ind][wt_left];
    }
    int ans = 0;
    // not taking.
    ans = max(ans, logic(ind-1, wt_left, wt, val, dp));

    // taking
    if (wt_left >= wt[ind]){ans = max(ans, logic(ind-1, wt_left-wt[ind], wt, val, dp) + val[ind]);}
    return dp[ind][wt_left] = ans;
}

void solve(){
    int n, w;
    cin >> n >> w;
    vector<int> wt(n);
    vector<int> val(n);
    rep(i, n){
        cin >> wt[i] >> val[i];
    }
    vector<vector<int> > dp(110, vector<int>(100010, -1));
    cout << logic(n-1, w, wt, val, dp);
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        solve();

    return 0;
}