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
    
    int n, x;
    cin >> n >> x;
    vector<pair<int, int> > a(n);
    rep(i, n){
        int x;
        cin >> x;
        a[i] = {x, i};
    }
    sort(all(a));
    // cout << "HERE" << endl;
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            int t = x - a[i].first - a[j].first;
            if (t < 1){
                continue;
            }
            // cout << a[i].first << " " << a[j].first << " " << t << endl;
            auto it = lower_bound(a.begin()+j+1, a.end(), make_pair(t, 0ll));
            if (it != a.end()){
                if (it->first == t){
                    cout << a[i].second + 1 << " " << a[j].second + 1 << " " << it->second + 1 << endl;return;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
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