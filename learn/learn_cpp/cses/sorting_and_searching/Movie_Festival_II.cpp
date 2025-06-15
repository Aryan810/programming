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
    
    int n, k;
    cin >> n >> k;

    vector<pair<int, int> > v;
    for (int i=0;i<n;i++){
        int x, y;
        cin >> x >> y;
        v.push_back({y, x});
    }

    sort(all(v));

    set<int> avail;
    for (int i=0;i<k;i++){
        avail.insert(i);
    }
    set<pair<int, int> > st;
    int ans = 0;
    for (int i=0;i<n;i++){
        if (st.size() > 0 && st.begin()->first <= v[i].second){
            auto it = (--st.upper_bound({v[i].second, -1}));
            auto top = *it;
            if (it != st.end()){st.erase(it);}
            st.insert({v[i].first, top.second});
            ans += 1;
        }else if (avail.size() > 0){
            st.insert({v[i].first, *avail.begin()});
            avail.erase(avail.begin());
            ans += 1;
        }
    }
    cout << ans << endl;




}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // mint::set_mod(M);
    int test = 1;

    while(test--){
        solve();
    }

    return 0;
} 