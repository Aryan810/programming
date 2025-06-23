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

    multiset<pair<int, int> > sames;
    multiset<pair<int, int> > diff;
    vi a(2*n);
    rep(i, 2*n){cin >> a[i];}
    for (int i=0;i<(2*n-1);i+=2){
        if (a[i] == a[i+1]){
            sames.insert({a[i], a[i+1]});
        }else{
            diff.insert({a[i], a[i+1]});
        }
    }

    set<int> left;
    set<int> done;
    for(int i=1;i<=n;i++){
        left.insert(i);
    }
    int ans = 0;
    for (auto & ele: sames){
        // cout << ele.first << " " << ele.second << endl;
        if (left.find(ele.first) != left.end()){
            left.erase(ele.first);
            done.insert(ele.first);
        }else{
            ans += 2;
        }
    }
    multiset<pair<int, int> > other;
    for (auto & ele: diff){
        bool f = (left.find(ele.first) != left.end());
        bool s = (left.find(ele.second) != left.end());
        if (!f && !s){
            ans += 2;
        }else if (!f && s){
            ans += 1;
            left.erase(ele.second);
        }else if (f && !s){
            ans += 1;
            left.erase(ele.first);
        }else{
            other.insert(ele);
        }
    }
    for (auto & ele: other){
        bool f = (left.find(ele.first) != left.end());
        bool s = (left.find(ele.second) != left.end());
        if (f && s){
            ans += 1;
            left.erase(f);
        }else if (!f && !s){
            ans += 2;
        }else if (!f && s){
            ans += 1;
            left.erase(ele.second);
        }else if (f && !s){
            ans += 1;
            left.erase(ele.first);
        }
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