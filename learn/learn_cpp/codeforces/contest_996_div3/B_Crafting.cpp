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
    rep(i, n){
        cin >> a[i];
    }

    vi b(n);
    rep(i, n){
        cin >> b[i];
    }
    int culp = -1;
    for (int i=0;i<n;i++){
        if (b[i] > a[i]){
            if (culp == -1){
                culp = i;
            }else{
                cout << "NO" << endl;
                return;
            }
        }
    }
    if (culp == -1){cout << "YES" << endl;return;}
    int mininc = b[culp]-a[culp];
    rep(i, n){
        if (i != culp){
            a[i] -= mininc;
            if (b[i] > a[i]){
                cout << "NO" << endl;return;
            }
        }
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