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
bool comp(array<int, 3> & a, array<int, 3> & b){
    if (a[0] < b[0]){
        return 1;
    }else if (a[0] > b[0]){
        return 0;
    }else{
        return a[1] > b[1];
    }
}
void solve(){
    
    int n;
    cin >> n;
    vector<int> contains(n);
    vector<int> containedIn(n);
    vector<array<int, 3> > l;
    ordered_multiset<int> ms;
    for (int i=0;i<n;i++){
        int u, v;
        cin >> u >> v;
        l.push_back({u, v, i});
        ms.insert(v);
    }
    sort(all(l), comp);
    for (int i=0;i<n;i++){
        int ord = ms.order_of_key(l[i][1]);
        ms.erase(ms.find_by_order(ord));
        auto it = ms.lower_bound(l[i][1]);
        int x;
        if (it == ms.end()){
            x = ms.size();
        }else{
            x = ms.order_of_key(*it);
        }
        
        contains[l[i][2]] = x;
    }
    ms.clear();
    for (int i=0;i<n;i++){
        ms.insert(l[i][1]);
    }
    for (int i=n-1;i>=0;i--){
        int ord = ms.order_of_key(l[i][1]);
        ms.erase(ms.find_by_order(ord));
        auto it = ms.lower_bound(l[i][1]-1);
        int x;
        if (it == ms.end()){
            x = 0;
        }else{
            x = ms.size() - ms.order_of_key(*it);
        }
        containedIn[l[i][2]] = x;
    }

    for (auto & ele: contains){
        cout << ele << " ";
    }cout << endl;
    for (auto & ele: containedIn){
        cout << ele << " ";
    }cout << endl;


}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // // mint::set_mod(M);
    // int test;
    // cin >> test;

    // while(test--){
        solve();
    // }

    return 0;
}