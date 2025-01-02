#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace __gnu_pbds;
using namespace std;
#define int long long
#define vi vector<int>
#define vii vector<int>::iterator
#define rep(i, n) for(int i=0;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){

    int n, k;cin >> n >> k;
    vi a(n), b(n);
    vi apb;
    rep(i, n){
        int x;cin >> x;
        a[i] = x;
        apb.push_back(x);
    }
    rep(i, n){
        int x;cin >> x;
        b[i] = x;
        apb.push_back(x);
    }
    sort(all(apb));
    sort(all(a));
    sort(all(b));
    int profit = 0;
    for (int i=0;i<apb.size();i++){
        auto x = lower_bound(all(a), apb[i]);
        auto y = lower_bound(all(b), apb[i]);
        int neg = (x-a.begin()) - (y-b.begin());
        if (neg <= k){
            int p = apb[i] * (n-(y-b.begin()));
            profit = max(p, profit);
        }
    }
    cout << profit << endl;


}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        solve();

    }

    return 0;
}