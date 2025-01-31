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
vector<vector<int> > dp;
int logic(vi & a, int i, int cond, vector<vector<int> > & pos){
    if (i == a.size()){
        return 0;
    }
    if (dp[i][cond] != -1){
        return dp[i][cond];
    }
    
    int ans = cond + logic(a, i+1, 1, pos);
    auto it = upper_bound(all(pos[a[i]]), i);
    if (it != pos[a[i]].end()){
        ans = min(ans, logic(a, *it, 0, pos));
    }
    return dp[i][cond] = ans;
}

void solve(){

    int n;
    cin >> n;
    vi a(n);
    vector<vector<int> > pos(n+1);

    rep(i, n){
        int x;
        cin >> x;
        pos[x].push_back(i);
        a[i] = x;
    }
    dp.assign(n+1, vector<int>(2, -1));
    cout << n-logic(a, 0, 1, pos) << endl;
    // for (auto ele: dp){
    //     cout << ele[0] << " " << ele[1] << endl;
    // }cout << endl;
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