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

    int n, d;
    cin >> n >> d;
    vector<int> v(10, 0);
    if (d&1){
        v[d] = 1;
    }
    if (d == 6 || d == 9){
        v[3] = 1;
    }
    v[1] = 1;
    if (n >= 3){
        v[3] = 1;
        if (d%3 == 0){
            v[9] = 1;
        }
        v[7] = 1;
    }
    if (n >= 6){
        v[9] = 1;
    }
    for (int i=1;i<=9;i++){
        if (v[i] == 1){
            cout << i << " ";
        }
    }cout << endl;

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