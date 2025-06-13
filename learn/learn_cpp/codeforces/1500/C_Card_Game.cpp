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
    int sm = 0;
    for (auto ele: a){
        if (ele > 0){
            sm += ele;
        }
    }
    if (a.size() == 1){
        if (a[0] > 0){
            cout << a[0] << endl;
        }else{
            cout << 0 << endl;
        }
        return;
    }
    if (a[0] >= 0){
        cout << sm << endl;
    }else if (a[0] <= 0 && a[1] <= 0){
        cout << sm << endl;
    }else if (a[0] <= 0 && a[1] >= 0){
        if (a[0]+a[1] > 0){
            cout << sm + a[0] << endl;
        }else{
            cout << sm-a[1] << endl;
        }
    }

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