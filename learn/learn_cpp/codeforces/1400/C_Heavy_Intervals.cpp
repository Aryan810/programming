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
    set<int> r;
    vector<int> l(n);
    rep(i, n)cin >> l[i];
    rep(i, n){
        int b;
        cin >> b;
        r.insert(b);
    }

    vector<int> weights(n);
    rep(i, n) cin >> weights[i];
    sort(all(l));sort(all(weights));
    int ans = 0;
    multiset<int> diff;
    rep(i, n){
        auto justLarge = r.lower_bound(l[n-1-i]);
        diff.insert(*justLarge - l[n-1-i]);
        r.erase(justLarge);
    }
    int i = 0;
    for (auto ele: diff){
        ans += ele*weights[n-1-i];
        i++;
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