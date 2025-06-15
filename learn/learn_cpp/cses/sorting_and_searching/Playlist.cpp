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
    
    int n;
    cin >> n;

    vi a(n);
    rep(i, n) cin >> a[i];
    map<int, vector<int> > ind;
    set<pair<int, int> > m;
    for (int i=0;i<n;i++){
        ind[a[i]].push_back(i);
        if (ind[a[i]].size() > 1){
            m.insert({i, a[i]});
        }
    }
    int ans = 0;
    for (int i=0;i<n;i++){
        // for (auto ele: m){
        //     cout << ele.second << " ";
        // }cout << endl;
        m.erase({i, a[i]});
        auto firstdupli = m.begin();
        if (firstdupli == m.end()){
            ans = max(ans, n-i);
            break;
        }
        ans = max(ans, (firstdupli->first - i));
        auto it = upper_bound(all(ind[a[i]]), i);
        auto it1 = m.find({*it, a[i]});
        if (it1 != m.end()){
            m.erase(it1);
        }
        // cout << ans << endl;
    }
    cout << ans << endl;
    // set<int> prev;
    // int ans = 0;
    // int mx = 0;
    // for (int i=0;i<n;i++){
    //     int curr = a[i];
    //     if (prev.find(curr) == prev.end()){
    //         mx += 1;
    //         prev.insert(curr);
    //     }else{
    //         ans = max(mx, ans);
    //         prev.clear();
    //         prev.insert(curr);
    //         mx = 1;
    //     }
    // }
    // ans = max(mx, ans);
    // cout << ans << endl;

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