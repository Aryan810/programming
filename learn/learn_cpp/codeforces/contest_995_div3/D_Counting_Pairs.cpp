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
    int n, x, y;
    cin >> n >> x >> y;
    vi a(n);
    int sum = 0;
    rep(i, n){
        int x;
        cin >> x;
        a[i] = x;   
        sum += x;
    }
    sort(all(a));
    int ans = 0;
    for (int i=0;i<n;i++){
        int l = sum-y-a[i], r = sum-x-a[i];
        auto low = lower_bound(all(a), l);
        auto high = upper_bound(all(a), r);
        if (i >= (low-a.begin()) && i < (high-a.begin())){
            ans += high-low-1;
        }else{
            ans += high-low;
        }
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