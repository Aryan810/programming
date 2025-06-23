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
    
    int n, s, x;
    cin >> n >> s >> x;
    vi a(n);
    map<int, ordered_set<int> > ind;
    set<int> indx;
    vector<int> pos;
    int sm = 0;
    vi cum(n+1);
    cum[0] = 0;
    rep(i, n){
        int y;
        cin >> y;
        a[i] = y;
        sm += y;
        cum[i+1] = sm;
        ind[sm].insert(i);
        if (y > x){
            pos.push_back(i);
        }else if (y == x){
            indx.insert(i);
        }
    }
    int ans = 0;
    for (int l=0;l<n;l++){
        int req = cum[l] + s;
        int fx;
        if (indx.size() == 0){
            continue;
        }else{
            fx = *indx.begin();
        }
        auto mxposs = lower_bound(all(pos), l);
        int p = n;
        if (mxposs != pos.end()){
            p = *mxposs;
        }
        // cout << "P: " << p << endl;
        auto ls = ind[req].lower_bound(p);
        auto mit = ind[req].lower_bound(fx);
        if (ls == ind[req].begin() || mit == ind[req].end()){
            ans += 0;
        }else if (ls == ind[req].end()){
            ans += max((int)(ind[req].size() - ind[req].order_of_key(*mit)), 0ll);
        }else{
            ans += max((int)(ind[req].order_of_key(*ls) - ind[req].order_of_key(*mit)), 0ll);
        }
        ind[cum[l+1]].erase(l);
        if (indx.find(l) != indx.end()){
            indx.erase(l);
        }
    }
    cout << max(ans, 0ll) << endl;

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