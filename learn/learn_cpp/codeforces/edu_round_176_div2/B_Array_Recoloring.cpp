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
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, n){
        cin >> a[i];
    }
    if (k == 1){
        int i = 0;
        int mx = 0;
        for (int j=0;j<n;j++){
            if (a[j] > mx){
                mx = a[j];
                i = j;
            }
        }
        if (i == 0 || i == n-1){
            int m1 = 0;
            if (i == 0){
                for (int j=1;j<n;j++){
                    m1 = max(m1, a[j]);
                }
                cout << mx + m1 << endl;
            }else{
                for (int j=n-2;j>=0;j--){
                    m1 = max(m1, a[j]);
                }
                cout << mx + m1 << endl;
            }
            return;
        }else{
            cout << max(a[0], a[n-1]) + mx << endl;return;
        }
    }
    sort(rall(a));
    int ans = 0;
    for (int i=0;i<(k+1);i++){
        ans += a[i];
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