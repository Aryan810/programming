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
    ordered_set<int> bef, aft;
    vector<pair<int, int> > a(n);
    rep(i, n){
        int x, y;cin >> x >> y;
        a[i] = {x, y};
        bef.insert(y);
    }
    int ans = 0;
    sort(all(a));
    for (int i=n-1;i>=0;i--){
        bef.erase(a[i].second);
        ans += aft.order_of_key(a[i].second);
        aft.insert(a[i].second);
        ans += bef.size() - bef.order_of_key(a[i].second);
    }
    cout << ans/2 << endl;


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