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
    vi pos;
    vi neg;
    rep(i, n){
        cin >> a[i];
        if (a[i] < 0){
            neg.push_back(a[i]);
        }else{
            pos.push_back(a[i]);
        }
    }
    sort(rall(neg));
    sort(rall(pos));
    sort(rall(a));
    int i=0, j=n-1;
    int ans = -1e18;

    // // case 1 -> all from pos.
    // if (pos.size() >= 4){
    //     int temp = 1;
    //     for (int i=0;i<5;i++){
    //         temp *= a[i];
    //     }
    //     ans = max(ans, temp);
    // }

    // // case 2 -> 2/3 from neg
    // if (neg.size() >= 2){
    //     int temp = 1;
    //     temp *= a[n-1];
    //     temp *= a[n-2];
    //     for (int i=0;i<3;i++){
    //         temp *= a[i];
    //     }
    //     ans = max(ans, temp);
    // }

    // // case 3 -> 4/5 from neg
    // if (neg.size() >= 4){
    //     int temp = 1;
    //     temp *= a[n-1];
    //     temp *= a[n-2];
    //     temp *= a[n-3];
    //     temp *= a[n-4];
    //     for (int i=0;i<1;i++){
    //         temp *= a[i];
    //     }
    //     ans = max(ans, temp);
    // }

    for (int i=0;i<=5;i++){
        if (neg.size() >= i && pos.size() >= (5-i)){
            int temp = 1;
            if (i&1){
                for (int j=0;j<i;j++){
                    temp *= neg[j];
                }
            }else{
                for (int j=0;j<i;j++){
                    temp *= neg[neg.size()-1-j];
                }
            }
            for (int j=0;j<(5-i);j++){
                temp *= pos[j];
            }
            ans = max(ans, temp);
        }
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