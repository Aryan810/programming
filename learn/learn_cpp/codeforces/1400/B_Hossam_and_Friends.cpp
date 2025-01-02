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
    int n, m;cin >> n >> m;
    vector<pair<int, int> > v(m);
    rep(i, m){
        int a, b;cin >> a >> b;
        v[i] = {min(a, b), max(a, b)};
    }
    sort(all(v));

    vector<int> mintill(m);
    int low = 1e18;
    for (int i=m-1;i>=0;i--){
        low = min(v[i].second, low);
        mintill[i] = low;
    }
    int ans = 0;
    for (int i=1;i<=n;i++){
        auto it = lower_bound(all(v), make_pair(i, 0ll));
        if (it != v.end()){
            int m = mintill[it-v.begin()] - 1;
            if (m >= i){
                ans += m-i+1;
            }
        }else{
            ans += n-i+1;
        }
        // cout << i << " : " << ans << endl;
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