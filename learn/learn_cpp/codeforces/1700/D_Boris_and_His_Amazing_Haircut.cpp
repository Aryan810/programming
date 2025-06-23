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
    vi b(n);
    map<int, vector<int> > ind;
    bool poss = 1;
    rep(i, n){
        int x;
        cin >> x;
        if (x <= a[i]){
            ind[x].push_back(i);
        }else{
            poss = 0;
        }
        b[i] = x;
    }
    map<int, int> mp;
    int m;
    cin >> m;
    for (int i=0;i<m;i++){
        int x;
        cin >> x;
        mp[x] += 1;
    }
    if (!poss){
        cout << "NO" << endl;return;
    }
    ordered_set<int> st;
    auto iter = ind.end();
    while (1){
        auto ele = *(--iter);
        int last = -1;
        for (auto & e: ele.second){
            auto it = st.lower_bound(e);
            int pos = 0;
            if (it == st.end()){
                pos = st.size();
            }else{
                pos = st.order_of_key(*it);
            }
            // cout << ele.first << " " << pos << endl;
            if (pos != last && b[e] != a[e]){
                mp[b[e]] -= 1;
                // if (mp[b[e]] < 0){
                //     cout << "NO" << endl;return;
                // }
                last = pos;
            }
            
        }
        for (auto & e: ele.second){
            st.insert(e);
        }
        if (iter == ind.begin()){
            break;
        }
    }
    for (auto & ele: mp){
        if (ele.second < 0){
            cout << "NO" << endl;return;
        }
    }
    cout << "YES" << endl;

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