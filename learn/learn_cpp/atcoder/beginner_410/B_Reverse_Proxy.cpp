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
    
    int n, q;
    cin >> n >> q;
    vi x(q);
    rep(i, q) cin >> x[i];

    set<array<int, 2> > s;
    vector<int> cnt(n+1, 0);
    for (int i=0;i<n;i++){
        s.insert({0, i+1});
    }

    for (int i=0;i<q;i++){
        if (x[i] != 0){
            s.erase({cnt[x[i]], x[i]});
            cnt[x[i]] += 1;
            s.insert({cnt[x[i]], x[i]});
            cout << x[i] << " ";
        }else{
            auto it = *s.begin();
            cnt[it[1]] += 1;
            s.erase(s.begin());
            s.insert({cnt[it[1]], it[1]});
            cout << it[1] << " ";
        }
    }cout << endl;
    

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