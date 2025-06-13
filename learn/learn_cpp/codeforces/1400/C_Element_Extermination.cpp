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
    vector<pair<int, int> >  cum(n);
    pair<int, int> mx = {0, -1};
    for (int i=n-1;i>=0;i--){
        if (mx.first < a[i]){
            mx = {a[i], i};
        }
        cum[i] = mx;
    }
    int x = a[0];
    int i = 0;
    while (i < n){
        pair<int,int> y = cum[i];
        if (y.first <= x){cout << "NO" << endl;return;}
        i = y.second+1;
    }
    cout << "YES" << endl;

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