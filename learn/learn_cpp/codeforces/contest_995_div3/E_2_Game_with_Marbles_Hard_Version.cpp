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

bool comp(pair< pair<int, int>, pair<int, int> > a, pair< pair<int, int>, pair<int, int> > b){
    return (a.first.second + a.first.first) > (b.first.second + b.first.first);

}

void solve(){

    int n;
    cin >> n;
    vector< pair< pair<int, int>, pair<int, int> > > a(n);
    rep(i, n){
        cin >> a[i].first.first;
    }
    rep(i, n){
        cin >> a[i].first.second;
        a[i].second.first = a[i].first.second - 1;
        a[i].second.second = a[i].first.first - 1;
    }
    sort(all(a), comp);
    int ans = 0;
    for (int i=0;i<n;i+=2){
        ans += a[i].first.first - 1;
    }
    for (int i=1;i<n;i+=2){
        ans -= a[i].first.second - 1;
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