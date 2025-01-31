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

    int n;cin >> n;
    vi a(n);
    vi b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    vi c(n);
    rep(i, n){
        c[i] = a[i] - b[i];
    }

    sort(all(c));
    int ans = 0;
    for (int i=n-1;i>0;i--){
        auto it = upper_bound(c.begin(), c.begin()+i+1, (-1)*c[i]);
        ans += ((i - (int)(it-c.begin())) >= 0)?((i - (int)(it-c.begin()))):0;
    }
    cout << ans << endl;

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        solve();
    return 0;
}