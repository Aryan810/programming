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
    int m = 1e18, M = 0;
    rep(i, n){
        int x;
        cin >> x;
        m = min(m, x);
        M = max(M, x);
    }
    int ans = 0;
    while (M != m){
        M = (M+m)/2;
        ans += 1;
    }

    if (ans > n){
        cout << ans << endl;
        return;
    }else{
        cout << ans << endl;
        rep(i, ans){
            cout << m << " ";
        }cout << endl;
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