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
    vi a(n);
    vector<int> ind(n+1);
    rep(i, n){
        int x;
        cin >> x;
        a[i] = x;
        ind[x] = i;
    }

    int curr = 1;
    int start = 0;
    while (curr <= n){
        int last = -1;
        while (last < ind[curr]){
            last = ind[curr];
            curr += 1;
        }
        start += 1;
    }
    
    for (int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        set<pair<int, int> > s;
        int f = a[u-1], l = a[v-1];
        int fb = f-1;
        int fa = f+1;
        int lb = l-1;
        int la = l+1;
        // if (f < n && f+1 == l){
        //     s.insert({f, l});
        //     ans += 1;
        //     if (f > 1 && !(ind[fb] > v-1 || ind[fb] < u-1)){
        //         if (s.find({fb, f}) == s.end()){
        //             s.insert({fb, f});
        //             ans -= 1;
        //         }
        //     }
        //     if (l < n && !(ind[la] > v-1 || ind[la] < u-1)){
        //     if (s.find({l, la}) == s.end()){
        //         s.insert({l, la});
        //         ans -= 1;
        //     }
        // }
        // }else if (f > 1 && f-1 == l){
        //     if (s.find({l, f}) == s.end()){
        //         s.insert({l, f});
        //         ans -= 1;
        //     }
        //      if (f < n && !(ind[fa] > v-1 || ind[fa] < u-1)){
        //     if (s.find({f, fa}) == s.end()){
        //         s.insert({f, fa});
        //         ans += 1;
        //     }
        // }
        // if (l > 1 && !(ind[lb] > v-1 || ind[lb] < u-1)){
        //     if (s.find({lb, l}) == s.end()){
        //         s.insert({lb, l});
        //         ans += 1;
        //     }
        // }
        // }else{
        if (f < n){
            s.insert({f, fa});
        }
        if (f > 1){
            s.insert({fb, f});
        }
        if (l < n){
            s.insert({l, la});
        }
        if (l > 1){
            s.insert({lb, l});
        }
        
        for (auto ele: s){
            start -= ind[ele.first] > ind[ele.second];
        }
        ind[a[u-1]] = v-1;
        ind[a[v-1]] = u-1;
        swap(a[v-1], a[u-1]);
        for (auto ele: s){
            start += ind[ele.first] > ind[ele.second];
        }
        cout << start << endl;
        
    }

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