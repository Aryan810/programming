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
    vi t(n);
    int mi = 1e18;
    rep(i, n){
        int x;
        cin >> x;
        t[i] = x;
        mi = min(mi, x);
    }
    sort(all(t));
    vi b(m);
    rep(i, m){
        int x;
        cin >> x;
        b[i] = x;
        mi = min(mi, x);
    }
    sort(all(b));
    for (int i=0;i<n;i++){
        t[i] -= mi;
    }
    for (int i=0;i<m;i++){
        b[i] -= mi;
    }
    int ans = 0;
    for (int i=0;i<n;i++){
        auto it = lower_bound(all(b), t[i]);
        if (it == b.begin()){
            ans = max(ans, abs(*it - t[i]));
        }else if (it == b.end()){
            ans = max(ans, abs(*(it - 1) - t[i]));
        }else{
            ans = max(ans, min(abs(*it - t[i]), abs(*(it-1) - t[i])));
        }
    }
    cout << ans << endl;
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


        solve();

    return 0;
}