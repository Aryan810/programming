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

    int k, x, a;cin >> k >> x >> a;
    if (a == 1){cout << "NO" << endl;return;}
    // vector<int> x;
    int curTotal = 0;
    for (int i=0;i<x;i++){
        int req = (curTotal/(k-1)) + 1;
        curTotal += req;
        if (curTotal >= a){
            cout << "NO" << endl;
            return;
        }
    }
    if ((k)*(a-curTotal) > a){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
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