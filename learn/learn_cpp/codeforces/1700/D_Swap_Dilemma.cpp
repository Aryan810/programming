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
    set<int> s;
    rep(i, n){
        int x;
        cin >> x;
        s.insert(x);
        a[i] = x;
    }
    vi b(n);
    rep(i, n) cin >> b[i];
    for (int i=0;i<n;i++){
        if (s.find(b[i]) == s.end()){
            cout << "NO" << endl;return;
        }
    }
    int oper = 0;
    map<int, int> ind;
    for (int i=0;i<n;i++){
        ind[b[i]] = i;
    }

    for (int i=0;i<n;i++){
        if (a[i] != b[i]){
            // cout << a[i] << " " << b[i] << endl;
            int x = ind[a[i]];
            int y = b[i];
            swap(b[x], b[i]);
            ind[a[i]] = i;
            ind[y] = x;
            oper += 1;
        }
    }
    // cout << oper << endl;
    cout << (oper&1?"NO":"YES") << endl;






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