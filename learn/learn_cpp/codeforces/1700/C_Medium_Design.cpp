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

    vector<pair<int, int> > ml;
    vector<pair<int, int> > l;
    rep(i, n){
        int x, y;
        cin >> x >> y;
        if (x <= 1 && y >= 1){
            if (!(x <= m && y >= m)){
                ml.push_back({x, 0});
                ml.push_back({y, 1});
            }
            continue;
        }
        if (x <= m && y >= m){
            l.push_back({x, 0});
            l.push_back({y, 1});
            continue;
        }
        ml.push_back({x, 0});
        ml.push_back({y, 1});
        l.push_back({x, 0});
        l.push_back({y, 1});
    }

    sort(all(l));
    sort(all(ml));
    // for (auto & ele: l){
    //     cout << ele.first << " " << ele.second << endl;
    // }cout << endl;
    // for (auto & ele: ml){
    //     cout << ele.first << " " << ele.second << endl;
    // }
    // case 1 - considering 1 as minimum !
    int ans = 0;
    int curr = 0;
    for (auto & ele: l){
        if (ele.second == 0){
            curr += 1;
        }else{
            curr -= 1;
        }
        ans = max(ans, curr);
    }
    curr = 0;
    for (auto & ele: ml){
        if (ele.second == 0){
            curr += 1;
        }else{
            curr -= 1;
        }
        ans = max(ans, curr);
    }
    cout << ans << endl;
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