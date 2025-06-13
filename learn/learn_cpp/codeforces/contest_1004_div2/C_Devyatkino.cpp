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
int p = 1;
void solve(){

    int n;
    cin >> n;
    // cout << p << " " << n << endl;
    p += 1;
    for (int i=0;i<=7;i++){
        int x = n-i;
        int min_diff = 1e18;
        while (x > 0){
            if (7 - x%10 >= 0){
                min_diff = min(min_diff, 7-x%10);
            }
            x /= 10;
        }
        // cout << "MIN DIff: " << min_diff << endl;
        if (min_diff <= i){
            cout << i << endl;return;
        }
    }
    cout << 7 << endl;

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