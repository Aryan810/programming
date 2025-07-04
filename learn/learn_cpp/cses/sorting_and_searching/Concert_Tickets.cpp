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

    set<int> s;
    map<int, int> num;
    rep(i, n){
        int x;
        cin >> x;
        num[x] += 1;
        s.insert(x);
    }
    
    vi t(m);
    rep(i, m) cin >> t[i];
    for (int i=0;i<m;i++){
        auto it = s.lower_bound(t[i]);
        if (*it == t[i]){
            cout << t[i] << endl;
            num[t[i]] -= 1;
            if (num[t[i]] == 0){
                s.erase(t[i]);
            }
            continue;
        }
        if (it == s.begin()){
            cout << -1 << endl;
        }else{
            it--;
            cout << *it << endl;
            num[*it] -= 1;
            if (num[*it] == 0){
                s.erase(*it);
            }
        }
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