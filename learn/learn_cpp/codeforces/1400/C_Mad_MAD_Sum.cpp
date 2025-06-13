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
    rep(i, n) cin >> a[i];
    int ans = 0;
    vector<int> num(n+1, 0);
    vector<pair<int, int> > v;
    for (int i=0;i<n;i++){
        ans += a[i];
        num[a[i]] += 1;
        if (num[a[i]] == 2){
            v.push_back({a[i], i});
        }
    }

    sort(rall(v));
    vector<pair<int, int> > v1;
    vi b;
    int ind = n;
    for (auto ele: v){
        if (ele.second < ind){
            int x = ind - ele.second;
            for (int i=0;i<x;i++){
                b.push_back(ele.first);
            }
            ans += x * (ele.first);
            ind = ele.second;
        }
    }
    reverse(all(b));
    num.clear();
    num.assign(n+1, 0);
    for (int i=0;i<b.size();i++){
        num[b[i]] += 1;
        // cout << num[b[i]] << endl;
        if (num[b[i]] == 2){
            v1.push_back({b[i], i});
        }
    }
    // cout << ans << endl;
    // for (auto ele: b){
    //     cout << ele << " ";
    // }cout << endl;
    sort(rall(v1));
    ind = b.size();
    int before = 0;
    // cout << "S: " << v1.size() << endl;
    for (auto ele: v1){
        if (ele.second < ind){
            int x = ind - ele.second;
            ans += (ele.first)*((x * (x+1))/2) + ((x > 1)?(ele.first * x * before):0);
            ind = ele.second;
            before += x;
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