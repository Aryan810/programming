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

    int n, a, b;
    cin >> n >> a >> b;
    int hcf = gcd(a, b);
    vi arr(n);
    rep(i, n){
        int x;
        cin >> x;
        arr[i] = x%hcf;
    }
    sort(all(arr));
    int ans = arr[n-1]-arr[0];
    for (int i=0;i<n-1;i++){
        ans = min(ans, arr[i]+hcf - arr[i+1]);
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