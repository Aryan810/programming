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

struct Node {
    int val;
    struct Node * nxt;
    struct Node * prev;
};
typedef struct Node node;

void solve(){
    
    int n, k;
    cin >> n >> k;
    ordered_set<int> s;
    for (int i=1;i<=n;i++){
        s.insert(i);
    }

    auto it = s.begin();
    while (s.size() > 0){
        // cout << "st: " << *it << endl;
        // not removing this.
        int p = k%s.size();
        int order = s.order_of_key(*it);
        it = s.find_by_order((order+p)%s.size());
        auto temp = it++;
        if (it == s.end()){
            it = s.begin();
        }
        cout << *temp << " ";
        s.erase(*temp);
        // cout << *it << endl;
        // for (auto ele: s){
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