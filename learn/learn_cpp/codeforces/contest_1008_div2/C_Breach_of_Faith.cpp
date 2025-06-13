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
    vi b(2*n);
    int sm = 0;
    rep(i, 2*n){
        int x;cin >> x;
        b[i] = x;
    }
    sort(all(b));

    vi b1, b2;
    sm = 0;
    for (int i=1;i<n;i++){
        b1.push_back(b[i]);
        sm -= b[i];
    }
    b2.push_back(b[0]);
    sm += b[0];
    for (int i=n;i<(2*n);i++){
        b2.push_back(b[i]);
        sm += b[i];
    }
    // cout << "SM: " << sm + b[0] + b[2*n - 1] << endl;
    // for (auto ele: b1){
    //     cout << ele << " ";
    // }cout << endl;
    // for (auto ele: b2){
    //     cout << ele << " ";
    // }cout << endl;
    
    b1.push_back(sm);
    int j = 0;
    int k = 0;
    for (int i=0;i<(2*n+1);i++){
        if (i&1){
            cout << b1[j] << " ";
            j += 1;
        }else{
            cout << b2[k] << " ";
            k += 1;
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