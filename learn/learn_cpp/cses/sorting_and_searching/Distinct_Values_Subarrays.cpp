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

    multiset<pair<int, int> > s;
    map<int, int> num;
    map<int, vector<int> > ind;
    vi a(n);
    rep(i, n){
        int x;
        cin >> x;
        num[x] += 1;
        ind[x].push_back(i);
        if (num[x] > 1){s.insert({i, x});}
        a[i] = x;
    }
    int ans = 0;
    for (int i=0;i<n;i++){
        if (s.size() > 0){
            auto it = s.begin();
            ans += (*it).first - i;
            auto it1 = upper_bound(all(ind[a[i]]), i);
            if (it1 != ind[a[i]].end()){
                auto temp = s.find({*it1, a[i]});
                if (temp != s.end()){
                    s.erase(temp);
                }
            }
        }else{
            ans += n-i;
        }
    }
    cout << ans << endl;



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