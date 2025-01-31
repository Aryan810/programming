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
int dp[100000+10];

int logic(int i, vi & num){
    while (i < num.size() && num[i] == 0){
        i += 1;
    }
    if (i >= num.size()){
        return 0;
    }else if (i == num.size() - 1){
        return i*(num[i]);
    }

    if (dp[i] != -1){
        return dp[i];
    }

    int ans = 0;

    if (num[i+1] > 0){
        ans = max(ans, num[i]*i + logic(i+2, num));
        //or
        ans = max(ans, num[i+1]*(i+1) + logic(i+3, num));
    }else{
        ans = max(ans, num[i]*i + logic(i+1, num));
    }
    return dp[i] = ans;
}

void solve(){
    int n;cin >> n;
    vi a(n);
    vi num(1e5 + 10, 0);
    rep(i, n){
        cin >> a[i];
        num[a[i]] += 1;
    }
    memset(dp, -1, sizeof(dp));

    cout << logic(0, num);
    return;

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        solve();

    return 0;
}