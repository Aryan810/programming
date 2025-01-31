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

    int n, x;cin >> n >> x;
    if (x == n){
        cout << x << " ";
        for (int i=2;i<n;i++){
            cout << i << " ";
        }cout << "1 " << endl;
        return;
    }

    if (n%x != 0){cout << -1 << endl;return;}
    vector<int> out(n);
    out[0] = x;
    out[n-1] = 1;
    int dikkat = x;
    for (int i=2;i<x;i++){
        out[i-1] = i;
    }
    while (dikkat != n){
        int j = 2;
        while (n%(j*dikkat) != 0){
            j += 1;
        }
        out[dikkat - 1] = dikkat * j;
        dikkat *= j;
    }
    
    for (int i=0;i<n;i++){
        if (out[i] != 0){
            cout << out[i] << " ";
        }else{
            cout << i+1 << " ";
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