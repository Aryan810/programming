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
    
    int x, n;
    cin >> x >> n;
    vi p(n);
    rep(i, n) cin >> p[i];
    multiset<int> gapes;
    gapes.insert(x);
    set<int> lt;
    lt.insert(0);
    lt.insert(x);

    for (int i=0;i<n;i++){
        int curr = p[i];
        auto bef = --lt.lower_bound(curr);
        auto aft = lt.upper_bound(curr);
        int prevgape = *aft - *bef;
        int g1 = curr - *bef;
        int g2 = *aft - curr;
        if (gapes.find(prevgape) != gapes.end()){gapes.erase(gapes.find(prevgape));}
        gapes.insert(g2);
        gapes.insert(g1);
        lt.insert(curr);
        cout << *(--gapes.end()) << " ";
        // for (auto ele: gapes){
        //     cout << ele << " ";
        // }cout << endl;
    }
    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // mint::set_mod(M);
    // int test;
    // cin >> test;

    // while(test--){
        solve();
    // }

    return 0;
}