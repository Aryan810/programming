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

    int n, m;
    cin >> n >> m;
    
    vi a(m);
    rep(i, m){
        cin >> a[i];
    }
    sort(all(a));

    int ans = 0;
    for (int i=1;i<=a[m-1];i++){
        int x = i;
        int y = n-i;
        if (x >= n || y >= n){
            break;
        }
        int p = m-(lower_bound(all(a), max(x, y))-a.begin());
        int q = m-(lower_bound(all(a), min(x, y))-a.begin());
        if (p > 0 && q > 1){
            ans += p*(q-1);
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