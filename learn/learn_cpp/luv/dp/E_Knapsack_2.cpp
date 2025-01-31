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

int logic(int ind, int val_left, vector<int> & wt, vector<int> & val, vector<vector<int> > & dp){
    if (val_left == 0){return 0;}
    if (ind < 0){
        return 1e18;
    }
    if (dp[ind][val_left] != -1){
        return dp[ind][val_left];
    }
    int ans = 1e18;
    // taken
    if (val_left >= val[ind]){ans = min(ans, logic(ind-1, val_left-val[ind], wt, val, dp) + wt[ind]);}
    
    // not taken
    ans = min(ans, logic(ind-1, val_left, wt, val, dp));
    return dp[ind][val_left] = ans;
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
    int max_val = 1e5;
    for (int i=max_val;i>=0;i--){
        if (logic(n-1, i, wt, val, dp) <= w){
            cout << i << endl;
            return;
        }
    }
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        solve();

    return 0;
}