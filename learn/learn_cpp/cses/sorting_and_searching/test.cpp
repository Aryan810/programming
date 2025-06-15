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
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

void solve(){
    ordered_multiset<int> ms;
    for (int i=0;i<10;i++){
        ms.insert(2);
    }  
    for (int i=0;i<1;i++){
        ms.insert(19);
    }   
    for (int i=0;i<8;i++){
        ms.insert(32);
    }

   
    // ms.erase(19);
    // ms.erase(ms.find(19));
    // ms.erase(ms.find(19));
    // ms.erase(ms.find(19));
    cout << (ms.lower_bound(32)==ms.end()) << endl;

 for (auto ele: ms){
        cout << ele << " ";
    }cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // mint::set_mod(M);
    solve();

    return 0;
}