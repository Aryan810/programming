// #include<atcoder/modint>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;
// using mint = modint;
#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator
#define umap(x, y) unordered_map<x, y, custom_hash>
const int M = 1e9 + 7;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

void solve(){
    
    int n, m;
    cin >> n >> m;
    cout << "? 1 1" << endl;cout.flush();
    int res;
    cin >> res;
    if (res == 0){
        cout << "! 1 1" << endl;cout.flush();return;
    }
    int x1 = 1;
    int y1 = 1 + res;

    if (y1 > m){
        int p = y1 - m;
        y1 -= p;
        x1 += p;
    }
    int x2 = 1 + res;
    int y2 = 1;
    if (x2 > n){
        int p = x2 - n;
        y2 += p;
        x2 -= p;
    }
    cout << "? " << x1 << " " << y1 << endl;cout.flush();
    int d1, d2;
    cin >> d1;
    if (d1 == 0){
        cout << "! " << x1 << " " << y1 << endl;cout.flush();return;
    }
    cout << "? " << x2 << " " << y2 << endl;cout.flush();
    cin >> d2;
    if (d2 == 0){
        cout << "! " << x2 << " " << y2 << endl;cout.flush();return;
    }   
    
    int x = x1 + d1/2;
    int y = y1 - d1/2;
    cout << "? " << x << " " << y << endl;cout.flush();   
    cin >> res;

    if (res == 0){
        cout << "! " << x << " " << y << endl;cout.flush();return;
    }else{
        cout << "! " << x2 - d2/2 << " " << y2 + d2/2 << endl;cout.flush();return;
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // mint::set_mod(M);
    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}