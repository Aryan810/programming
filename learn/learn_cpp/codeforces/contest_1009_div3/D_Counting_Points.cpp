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
    int m;
    cin >> m;
    unordered_map<int, int> my;

    vi c(n), r(n);
    for (int i=0;i<n;i++){
        cin >> c[i];
    }
    rep(i, n) cin >> r[i];

    for (int i=0;i<n;i++){
        int x = c[i];
        int rr = r[i];
        for (int j=(x-rr);j<=(x+rr);j++){
            my[j] = max(my[j], (int)sqrt(rr*rr - (x-j)*(x-j)));
        }
    }

    int ans = 0;
    for (auto ele: my){
        ans += 2*(ele.second) + 1;
        // cout << ele.first << " " << ele.second << endl;
    }
    // cout << endl;
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