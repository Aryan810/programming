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
    set<pair<int, int> > lft;
    rep(i, n){
        int x;
        cin >> x;
        lft.insert({x, i});
        a[i] = x;
    }

    vector<pair<int, int> > choosed;
    vi b(n);
    int left = n/2 - 1;
    int i = 1;
    while (left > 0){
        if (a[i] > 1){
            left -= 1;
            choosed.push_back({a[i], i});
            lft.erase({a[i], i});
            i += 2;
        }else{
            choosed.push_back({a[i+1], i+1});
            lft.erase({a[i+1], i+1});
            left -= 1;
            i += 3;
        }
    }

    int curr = n;
    sort(all(choosed));
    for (auto & ele: choosed){
        b[ele.second] = curr--;
    }

    for (auto & ele: lft){
        b[ele.second] = curr--;
    }

    for (auto & ele: b){
        cout << ele << " ";
    }cout << endl;
    


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