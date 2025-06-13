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

    int n;cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    int low = 0;
    int high = 1e9;
    for (int i=0;i<n-1;i++){
        if (a[i+1] < a[i]){
            int l, h;
            l = ceil((a[i+1] + a[i])/(double)2);
            h = 1e9;
            low = max(low, l);
            high = min(high, h);
            if (low > high){
                cout << -1 << endl;
                return;
            }
        }else if (a[i+1] > a[i]){
            int l, h;
            h = (a[i+1]+a[i])/2;
            l = 0;
            low = max(low, l);
            high = min(high, h);
            if (low > high){
                cout << -1 << endl;
                return;
            }
        }
    }
    if (low <= high){
        cout << low << endl;
    }else{
        cout << -1 << endl;

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