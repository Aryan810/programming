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
    
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int sm = x1*y2 + x2*y2 + x3*y3;
    int a = sqrt(sm);

    // case 1
    if ((y1+y3) == (x2+x3) && ((y2+y1)==(x1) && (y2 == y3))){
        cout << "YES" << endl;
    }else if ((y1)==(y2+y3) && ((x1 + x3)==(x2 + x1) && (y1) == (x1+x3))){
        cout << "YES" << endl;
    }else if ((y1+y2+y3) == (x1) && ((x2 == x3) && (x1 == x2))){
        cout << "YES" << endl;
    }else if ((x1 + x2 + x3) == (y1) && ((y1 == y2) && (y2 == y3))){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
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