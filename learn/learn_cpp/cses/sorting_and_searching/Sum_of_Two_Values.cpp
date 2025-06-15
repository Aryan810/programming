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

    map<int, vector<int> > ind;
    vi a(n);
    rep(i, n){
        int x;
        cin >> x;
        ind[x].push_back(i);
        a[i] = x;
    }
    sort(all(a));

    for (int i=0;i<n;i++){
        if (x-a[i] < a[i]){
            break;
        }else if (x - a[i] == a[i]){
            if (ind[a[i]].size() > 1){
                cout << ind[a[i]][0]+1 << " " << ind[a[i]][1]+1 << endl;return;
            }
            break;
        }else{
            auto it = lower_bound(a.begin()+i+1, a.end(), (x-a[i]));
            if (it == a.end()){continue;}
            if (*it == (x-a[i])){
                cout << *ind[a[i]].begin() + 1 << " " << *upper_bound(all(ind[*it]), i) + 1 << endl;return;
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