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
    rep(i, n-2){
        cout << "? " << i+1 << " " << n-1 << " " << n << endl;
        cout.flush(); 
        cin >> a[i];
    }
    cout << "? " << n-2 << " " << n-3 << " " << n << endl;
    cout.flush(); 
    cin >> a[n-1];
    cout << "? " << n-2 << " " << n-3 << " " << n-1 << endl;
    cout.flush(); 
    cin >> a[n-2];

    int x = a[n-3] + a[n-4];
    int p = x-(a[n-2]);
    int q = x-(a[n-1]);
    int d = (2*q - p)/3;
    int e = (2*p - q)/3;

    cout << "! ";
    for (int i=0;i<n-2;i++){
        cout << a[i]-(d+e) << " ";
    }
    cout << d << " " << e << endl;
    cout.flush();

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