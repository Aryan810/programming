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

    int n, m;
    cin >> n >> m;

    vi a(n);
    rep(i, n) cin >> a[i];
    int sm = accumulate(all(a), 0ll);
    set<int> b;
    rep(i, n){
        int x;
        cin >> x;
        b.insert(x);
        sm += x;
    }

    sort(rall(a));
    int ans = 0;
    for (int i=0;i<n;i++){
        auto it = b.lower_bound(m-a[i]);
        if (it == b.end()){
            ans += sm;break;
        }
        ans += (a[i] + *it)%m;
        sm -= a[i] + *it;
        b.erase(it);
    }
    cout << ans << endl;
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