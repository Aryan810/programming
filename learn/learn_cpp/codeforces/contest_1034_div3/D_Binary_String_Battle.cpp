// #include<atcoder/modint>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;
// using mint = modint;
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define each(x, a) for (auto &x : a)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pi pair<int, int>
#define p(a, b) pair<a, b>
#define vi vector<int>
#define vii vector<int>::iterator
#define vvi vector<vector<int> >
#define vv(x) vector<vector<x> >
#define PRECISION(x) cout << fixed << setprecision(x);
#define mnv(v) *min_element(v.begin(), v.end())
#define mxv(v) *max_element(v.begin(), v.end())
#define umap(x, y) unordered_map<x, y, custom_hash>
const int mod7 = 1e9 + 7;
const int mod9 = 998244353;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

void solve(){
    
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    ordered_set<int> ones;
    for (int i=0;i<n;i++){
        if (s[i] == '1'){
            ones.insert(i);
        }
    }
    if (ones.size() <= k){
        cout << "Alice" << endl;return;
    }

    if (2*k > n){
        cout << "Alice" << endl;
    }else{
        cout << "Bob" << endl;
    }

    // int f = *ones.begin();
    // int sec = *(--ones.end());
    // int d = 0;
    // for (auto & ele: ones){
    //     int left = k - d;
    //     if (left < 0){break;}
    //     auto right = *ones.find_by_order(ones.size()-1-left);
    //     cout << ele << " " << right << " " << left  << endl;
    //     // cout << left << " " << ele << " " << right << endl;
    //     if (max(sec + 1, n-f) > max(right + 1, n - ele)){
    //         f = ele;
    //         sec = right;
    //     }
    //     d += 1;
    // }
    // cout << f << " " << sec << endl;
    // int mx = sec;
    // int mn = f;
    // // cout << mn << " " << mx << endl;

    // // if (r > l){
    //     if (max(n - mn, mx+1) > k){
    //         cout << "Bob" << endl;
    //     }else{
    //         cout << "Alice" << endl;
    //     }
    // }else{
    //     if (mx + 1 > k){
    //         cout << "Bob" << endl;
    //     }else{
    //         cout << "Alice" << endl;
    //     }
    // }

}

signed main(){
    fast_io;   
    // mint::set_mod(M);
    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}