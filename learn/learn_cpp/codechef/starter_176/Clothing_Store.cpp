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

    vi x(3);
    vi a(3);    
    rep(i, 3) cin >> a[i];

    rep(i, 3) cin >> x[i];

    int ans = 0;
    for (int i=0;i<3;i++){
        int y = x[i]; // persons
        for (int j=i;j<3;j++){
            if (y > 0 && a[j] > y){
                ans += y;
                a[j] -= y;
                y = 0;
            }else if (y > 0 && y >= a[j]){
                y -= a[j];
                ans += a[j];
                a[j] = 0;
            }
        }
    }
    cout << ans << endl;

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