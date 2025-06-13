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
    vi a(n);
    rep(i, n) cin >> a[i];
    // vector<vector<int> > dp(n+1, vector<int>(n+1, -1));
    // cout << logic(n, 0, 0, dp, a, 0) << endl;
    multiset<int> drunk;
    // smallest.insert(a[0]);
    int sm = 0;
    for (int i=0;i<n;i++){
        // cout << sm << endl;
        sm += a[i];
        drunk.insert(a[i]);
        while (sm < 0){
            sm -= *drunk.begin();
            drunk.erase(drunk.begin());
        }
    }
        // sm += a[i];
        // ans += 1;
        // if (a[i] < 0){
        //     smallest.insert(a[i]);
        // }
        // if (sm < 0){
        //     while (!smallest.empty() && sm < 0){
        //         sm -= *smallest.begin();
        //         smallest.erase(smallest.begin());
        //         ans -= 1;
        //     }
        // }
    cout << drunk.size() << endl;

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


        solve();

    return 0;
}