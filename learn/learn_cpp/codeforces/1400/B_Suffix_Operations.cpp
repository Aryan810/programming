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

    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    int ans = 0;
    for (int i=n-1;i>0;i--){
        ans += abs(a[i-1] - a[i]);
    }
    // cout << "AMS: " << ans << endl;
    int maxFayda = 0;
    for (int i=n-1;i>=0;i--){
        int x;
        if (i == 0){
            x = abs(a[i] - a[i+1]);
        }
        else if (i == n-1){
            x = abs(a[i-1] - a[i]);
        }else{
            x = abs(a[i-1]-a[i]) - abs(a[i-1]-a[i+1]) + abs(a[i]-a[i+1]);
        }
       
        maxFayda = max(maxFayda, x);
    }
    cout << ans - maxFayda << endl;

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